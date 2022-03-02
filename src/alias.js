const {ALIASES} = require("./constants");

exports.replaceAliases = (str, options = {}) => {
    if (ALIASES.size === 0) {
        return str;
    }

    const shared_ptr = exports.removeNamespaces(options.shared_ptr, options);

    const aliases = new RegExp(Array.from(ALIASES.keys()).join("|"), "g");

    // Ptr, tuple, vector, pair
    const replacer = (match, offset, string) => {
        const end = offset + match.length;

        // if a start of a word, then it must be a word
        if (offset === 0 || /\W/.test(string[offset - 1])) {
            return end === string.length || /\W/.test(string[end]) ? ALIASES.get(match) : match;
        }

        // if an end of a word, the it must be a pointer, a vector, or a type in a tuple or a pair
        if (end === string.length || /\W/.test(string[end])) {
            // pointer, vector, or the first sole type of a tuple
            if ([shared_ptr, "vector", "tuple"].some(prefix => string.endsWith(`${ prefix }_`, offset))) {
                return ALIASES.get(match);
            }

            // type in a tuple or a pair
            if (string.endsWith("_and_", offset)) {
                let pos = offset - "_and_".length;
                while (pos > 0 && /\w/.test(string[pos - 1])) {
                    pos--;
                }

                return string.startsWith("pair_", pos) || string.startsWith("tuple_", pos) ? ALIASES.get(match) : match;
            }

            return match;
        }

        // otherwise, it must be a pointer, vector, or a type in a tuple or a pair

        // pointer or vector
        if ([shared_ptr, "vector"].some(prefix => string.endsWith(`${ prefix }_`, offset))) {
            return /\W/.test(string[end]) ? ALIASES.get(match) : match;
        }

        // type in a tuple or a pair
        if (string.endsWith("pair_", offset) || string.endsWith("tuple_", offset)) {
            return string.startsWith("_and_", end) ? ALIASES.get(match) : match;
        }

        if (string.endsWith("_and_", offset)) {
            let pos = offset - "_and_".length;
            while (pos > 0 && /\w/.test(string[pos - 1])) {
                pos--;
            }

            if (!string.startsWith("pair_", pos) && !string.startsWith("tuple_", pos)) {
                return match;
            }

            return ALIASES.get(match);
        }

        return match;
    };

    return str.replace(aliases, replacer);
};

exports.removeNamespaces = (str, options = {}) => {
    if (!options.namespaces || options.namespaces.size === 0) {
        return str;
    }

    const reg = new RegExp(`\\b(?:${ Array.from(options.namespaces).join("|") })::`, "g");

    return str.replace(reg, "");
};

// const options = {
//     shared_ptr: "std::shared_ptr",
//     namespaces: new Set([
//         "cv",
//         "std",
//         "dlib"
//     ])
// };

// ["dense_vect", "SpaceVector"],
// ["sample_type", "SpaceVector"],
// ["matrix_double_0_1", "SpaceVector"],
// ["matrix_double", "Matrix"],
// ["sparse_vect", "vector_pair_ULONG_and_double"],
// ["ranges", "vector_pair_ULONG_and_ULONG"],
// ["simple_object_detector", "fhog_object_detector"],

// console.log(exports.replaceAliases("shared_ptr_sparse_vect", options));
// console.log(exports.replaceAliases("sparse_vect", options));
// console.log(exports.replaceAliases("sparse_vector", options));
// console.log(exports.replaceAliases("sparse_vect ", options));
// console.log(exports.replaceAliases("sparse_vector ", options));
// console.log(exports.replaceAliases(" sparse_vect", options));
// console.log(exports.replaceAliases(" sparse_vector", options));
// console.log(exports.replaceAliases(" sparse_vect_and_", options));
// console.log(exports.replaceAliases("vector_sparse_vect_and_", options));
// console.log(exports.replaceAliases("vector_sparse_vect", options));
// console.log(exports.replaceAliases("tuple_sparse_vect", options));
// console.log(exports.replaceAliases("tuple_sparse_vect_and_int", options));
// console.log(exports.replaceAliases("tuple_int_and_sparse_vect", options));
// console.log(exports.replaceAliases("tuple_int_and_sparse_vect_and_uint", options));
// console.log(exports.replaceAliases(" tuple_sparse_vect", options));
// console.log(exports.replaceAliases(" tuple_sparse_vect_and_int", options));
// console.log(exports.replaceAliases(" tuple_int_and_sparse_vect", options));
// console.log(exports.replaceAliases(" tuple_int_and_sparse_vect_and_uint", options));
// console.log(exports.replaceAliases("tuple_sparse_vect ", options));
// console.log(exports.replaceAliases("tuple_sparse_vect_and_int ", options));
// console.log(exports.replaceAliases("tuple_int_and_sparse_vect ", options));
// console.log(exports.replaceAliases("tuple_int_and_sparse_vect_and_uint ", options));
// console.log(exports.replaceAliases("_make_sparse_vector ", options));
