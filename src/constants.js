exports.SIMPLE_ARGTYPE_DEFAULTS = new Map([
    ["bool", "0"],
    ["size_t", "0"],
    ["int", "0"],
    ["float", "0.f"],
    ["double", "0"],
    ["c_string", "(char*)\"\""],
    ["Stream", "Stream::Null()"],
]);

exports.IDL_TYPES = new Map([
    ["bool", "VARIANT_BOOL"],
    ["float", "FLOAT"],
    ["int64", "LONGLONG"],
    ["int", "LONG"],
    ["uint", "ULONG"],
    ["long", "LONG"],
    ["ulong", "ULONG"],
    ["size_t", "ULONGLONG"],
    ["uint64", "ULONGLONG"],
    ["String", "BSTR"],
    ["string", "BSTR"],
    ["uchar", "BYTE"],
]);

exports.CPP_TYPES = new Map([
]);

exports.ALIASES = new Map([
]);

exports.CLASS_PTR = new Set([
]);

exports.PTR = new Set([
    "void*",
    "uchar*",
    "HWND",
]);

exports.CUSTOM_CLASSES = [
];

exports.CUSTOM_NAMESPACES = new Set();

exports.ARRAY_CLASSES = new Set([
]);

exports.ARRAYS_CLASSES = new Set([
]);

exports.IGNORED_CLASSES = new Set([
]);

for (const type of exports.CPP_TYPES.keys()) {
    const cpptype = exports.CPP_TYPES.get(type);
    if (cpptype[0] !== "_" && !cpptype.includes("<") && !type.includes("string") && !type.includes("String")) {
        exports.ALIASES.set(type, cpptype);
    }
}
