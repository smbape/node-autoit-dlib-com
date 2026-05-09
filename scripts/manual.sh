#!/usr/bin/env bash

# Update checks:
#   - check changes in python
#   
# https://github.com/microsoft/PTVS/issues/7794
# https://stackoverflow.com/questions/74190153/no-symbols-loaded-for-c-in-mixed-debugging-from-python/74486282#74486282



# ================================
# stash for release
# ================================
git stash push --include-untracked


# ================================
# tidy
# ================================
node ../${ESLINT_CONFIG_PROJECT}/node_modules/eslint/bin/eslint.js --config=../${ESLINT_CONFIG_PROJECT}/.eslintrc --fix 'src/**/*.js' 'scripts/*.js' && \
find examples autoit-dlib-com/udf -type d -name 'BackUp' -prune -o -type f -name '*.au3' -not -name '*test.au3' | xargs -I '{}' 'C:\Program Files (x86)\AutoIt3\AutoIt3.exe' 'C:\Program Files (x86)\AutoIt3\SciTE\AutoIt3Wrapper\AutoIt3Wrapper.au3' //Tidy //in '{}' && \
find examples autoit-dlib-com/udf -type d -name 'BackUp' -exec rm -rf '{}' \; && \
git add --renormalize .


# ================================
# generate doctoc
# ================================
node node_modules/doctoc/doctoc.js README.md && \
git add --renormalize .


# ================================
# create a new version
# ================================
npm version patch


# ================================
# build
# ================================
rm -rf opencv-4.*.0-windows autoit-dlib-com/{build_x64,generated} && \
time CMAKE_BUILD_TYPE=Release cmd.exe //c $(cygpath -w autoit-*-com/build.bat) && time CMAKE_BUILD_TYPE=Debug cmd.exe //c $(cygpath -w autoit-*-com/build.bat) && \
find examples autoit-dlib-com/udf -type d -name 'BackUp' -prune -o -type f -name '*.au3' -not -name '*test.au3' | xargs -I '{}' 'C:\Program Files (x86)\AutoIt3\AutoIt3.exe' 'C:\Program Files (x86)\AutoIt3\SciTE\AutoIt3Wrapper\AutoIt3Wrapper.au3' //Tidy //in '{}' && \
find examples autoit-dlib-com/udf -type d -name 'BackUp' -exec rm -rf '{}' \; && \
bash -c 'source scripts/tasks.sh && update_new_version' && \
node scripts/build.js


# ================================
# test local
# ================================
node scripts/test.js --bash --Release > $(for ifile in autoit-*-com/build_x64/bin; do echo $ifile/test_all.sh; done) && \
./autoit-*-com/build_x64/bin/test_all.sh


# ================================
# pack release
# ================================
bash -c 'source scripts/tasks.sh && update_new_version' && \
node scripts/build.js


# ================================
# test release
# ================================
test -d /d/Programs/AutoIt/UDF/dlib-udf-test/opencv-4.13.0-windows || ./opencv-4.13.0-windows.exe -o/d/Programs/AutoIt/UDF/dlib-udf-test/opencv-4.13.0-windows -y && \
rm -rf /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-* /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-opencv-* /d/Programs/AutoIt/UDF/dlib-udf-test/examples && \
git archive --format zip --output /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-com.zip HEAD && \
7z x autoit-dlib-*.7z -aoa -o/d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-com && \
7z x autoit-opencv-*.7z -aoa -o/d/Programs/AutoIt/UDF/dlib-udf-test/autoit-opencv-com && \
7z x /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-com.zip -aoa -o/d/Programs/AutoIt/UDF/dlib-udf-test 'examples\*' && \
curl -L 'https://github.com/davisking/dlib/archive/refs/tags/v20.0.1.zip' -o autoit-dlib-v20.0.1-src.zip && \
7z x autoit-dlib-v20.0.1-src.zip -aoa 'dlib-20.0.1\examples\faces' 'dlib-20.0.1\examples\video_frames' -o/d/Programs/AutoIt/UDF/dlib-udf-test/ && \
cp -rf /d/Programs/AutoIt/UDF/dlib-udf-test/dlib-20.0.1/* /d/Programs/AutoIt/UDF/dlib-udf-test/ && \
rm -rf /d/Programs/AutoIt/UDF/dlib-udf-test/dlib-20.0.1 && \
mkdir /d/Programs/AutoIt/UDF/dlib-udf-test/examples/data && \
node scripts/test.js --bash --Release /d/Programs/AutoIt/UDF/dlib-udf-test > $(for ifile in autoit-*-com/build_x64/bin; do echo $ifile/test_all.sh; done) && \
./autoit-*-com/build_x64/bin/test_all.sh
