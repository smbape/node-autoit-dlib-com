#!/usr/bin/env bash

# ================================
# stash for release
# ================================
git stash push --include-untracked


# ================================
# tidy
# ================================
node ../${ESLINT_CONFIG_PROJECT}/node_modules/eslint/bin/eslint.js --config=../${ESLINT_CONFIG_PROJECT}/.eslintrc --fix 'src/**/*.js' 'scripts/*.js'
find examples autoit-dlib-com/udf -type d -name 'BackUp' -prune -o -type f -name '*.au3' -not -name '*test.au3' | xargs -I '{}' 'C:\Program Files (x86)\AutoIt3\AutoIt3.exe' 'C:\Program Files (x86)\AutoIt3\SciTE\AutoIt3Wrapper\AutoIt3Wrapper.au3' //Tidy //in '{}'
find examples autoit-dlib-com/udf -type d -name 'BackUp' -exec rm -rf '{}' \;


# ================================
# generate doctoc
# ================================
node node_modules/doctoc/doctoc.js README.md


# ================================
# create a new version
# ================================
npm version patch


# ================================
# build
# ================================
rm -rf opencv-4.*.0-windows autoit-dlib-com/{build_x64,generated} && \
time CMAKE_BUILD_TYPE=Release cmd.exe //c $(cygpath -w autoit-*-com/build.bat) && time CMAKE_BUILD_TYPE=Debug cmd.exe //c $(cygpath -w autoit-*-com/build.bat)


# ================================
# test local
# ================================
# find examples -type f -name '*.au3' -a -not \( -name 'cnn_face_detector.au3' -o -name 'face_recognition.au3' \) -exec 'C:\Program Files (x86)\AutoIt3\AutoIt3.exe' 'C:\Program Files (x86)\AutoIt3\SciTE\AutoIt3Wrapper\AutoIt3Wrapper.au3' //run //prod //ErrorStdOut //in '{}' \;
# find examples -type f -name '*.cs' -exec cmd.exe //c 'examples\dotnet\csrun.bat' '{}' \;
# find examples -type f -name '*.ps1' -exec powershell.exe -ExecutionPolicy, UnRestricted, -File '{}' \;
BUILD_TYPE=Release node scripts/test.js


# ================================
# pack release
# ================================
node scripts/build.js


# ================================
# test release
# ================================
test -d /d/Programs/AutoIt/UDF/dlib-udf-test/opencv-4.10.0-windows || ./opencv-4.10.0-windows.exe -o/d/Programs/AutoIt/UDF/dlib-udf-test/opencv-4.10.0-windows -y && \
rm -rf /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-* /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-opencv-* /d/Programs/AutoIt/UDF/dlib-udf-test/examples && \
git archive --format zip --output /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-com.zip main && \
7z x autoit-dlib-*.7z -aoa -o/d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-com && \
7z x autoit-opencv-*.7z -aoa -o/d/Programs/AutoIt/UDF/dlib-udf-test/autoit-opencv-com && \
7z x /d/Programs/AutoIt/UDF/dlib-udf-test/autoit-dlib-com.zip -aoa -o/d/Programs/AutoIt/UDF/dlib-udf-test 'examples\*' && \
curl -L 'https://github.com/davisking/dlib/archive/refs/tags/v19.24.4.zip' -o autoit-dlib-v19.24.4-src.zip && \
7z x autoit-dlib-v19.24.4-src.zip -aoa 'dlib-19.24.4\examples\faces' 'dlib-19.24.4\examples\video_frames' -o/d/Programs/AutoIt/UDF/dlib-udf-test/ && \
cp -rf /d/Programs/AutoIt/UDF/dlib-udf-test/dlib-19.24.4/* /d/Programs/AutoIt/UDF/dlib-udf-test/ && \
rm -rf /d/Programs/AutoIt/UDF/dlib-udf-test/dlib-19.24.4 && \
mkdir /d/Programs/AutoIt/UDF/dlib-udf-test/examples/data && \
BUILD_TYPE=Release node scripts/test.js /d/Programs/AutoIt/UDF/dlib-udf-test
