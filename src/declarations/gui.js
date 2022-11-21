module.exports = [
    ["class dlib.image_window", "", [], [], "", ""],

    ["dlib.image_window.image_window", "shared_ptr_image_window", [], [], "", ""],

    ["dlib.image_window.create", "shared_ptr_image_window", ["/External"], [
        ["fhog_object_detector", "detector", "", ["/Ref"]],
    ], "", ""],

    ["dlib.image_window.create", "shared_ptr_image_window", ["/External"], [
        ["simple_object_detector_com", "detector", "", ["/Ref"]],
    ], "", ""],

    ["dlib.image_window.create", "shared_ptr_image_window", ["/External"], [
        ["fhog_object_detector", "detector", "", ["/Ref"]],
        ["string", "title", "", []],
    ], "", ""],

    ["dlib.image_window.create", "shared_ptr_image_window", ["/External"], [
        ["simple_object_detector_com", "detector", "", ["/Ref"]],
        ["string", "title", "", []],
    ], "", ""],

    ["dlib.image_window.create", "shared_ptr_image_window", ["/External"], [
        ["cv::Mat", "img", "", ["/Ref"]],
    ], "", ""],

    ["dlib.image_window.create", "shared_ptr_image_window", ["/External"], [
        ["cv::Mat", "img", "", ["/Ref"]],
        ["string", "title", "", []],
    ], "", ""],

    ["dlib.image_window.set_image", "void", [], [
        ["fhog_object_detector", "detector", "", ["/Ref", "/Cast=draw_fhog"]],
    ], "", ""],

    ["dlib.image_window.set_image", "void", [], [
        ["simple_object_detector_com", "detector", "", ["/Ref", "/Expr=detector.detector", "/Cast=draw_fhog"]],
    ], "", ""],

    ["dlib.image_window.set_image", "void", ["/External"], [
        ["cv::Mat", "img", "", ["/Ref"]],
    ], "", ""],

    ["dlib.image_window.set_title", "void", [], [
        ["string", "title", "", []],
    ], "", ""],

    ["dlib.image_window.clear_overlay", "void", [], [], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["vector_rectangle", "rectangles", "", []],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["vector_rectangle", "rectangles", "", []],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", ["/Expr=std::get<0>(color), std::get<1>(color), std::get<2>(color)", "/Cast=rgb_pixel"]],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["vector_drectangle", "drectangles", "", ["/Cast=vector_drectangle_to_vector_rectangle"]],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["vector_drectangle", "drectangles", "", ["/Cast=vector_drectangle_to_vector_rectangle"]],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", ["/Expr=std::get<0>(color), std::get<1>(color), std::get<2>(color)", "/Cast=rgb_pixel"]],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["/External"], [
        ["vector__variant_t", "objs", "", []],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["/External"], [
        ["vector__variant_t", "objs", "", []],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["rectangle", "rect", "", []],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["rectangle", "rect", "", []],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", ["/Expr=std::get<0>(color), std::get<1>(color), std::get<2>(color)", "/Cast=rgb_pixel"]],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["drectangle", "drect", "", ["/Cast=rectangle"]],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["drectangle", "drect", "", ["/Cast=rectangle"]],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", ["/Expr=std::get<0>(color), std::get<1>(color), std::get<2>(color)", "/Cast=rgb_pixel"]],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["/External"], [
        ["full_object_detection", "detection", "", ["/Ref"]],
        ["rgb_pixel", "color", "rgb_pixel(0, 0, 255)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["/External"], [
        ["full_object_detection", "detection", "", ["/Ref"]],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{0, 0, 255}", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["line", "l", "", []],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", [], [
        ["line", "l", "", []],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", ["/Expr=std::get<0>(color), std::get<1>(color), std::get<2>(color)", "/Cast=rgb_pixel"]],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["=add_overlay_circle", "/Expr=image_window::overlay_circle($0)"], [
        ["point", "center", "", []],
        ["double", "radius", "", []],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["=add_overlay_circle", "/Expr=image_window::overlay_circle($0)"], [
        ["point", "center", "", []],
        ["double", "radius", "", []],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", ["/Expr=std::get<0>(color), std::get<1>(color), std::get<2>(color)", "/Cast=rgb_pixel"]],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["=add_overlay_circle", "/Expr=image_window::overlay_circle($0)"], [
        ["dpoint", "center", "", []],
        ["double", "radius", "", []],
        ["rgb_pixel", "color", "rgb_pixel(255, 0, 0)", []],
    ], "", ""],

    ["dlib.image_window.add_overlay", "void", ["=add_overlay_circle", "/Expr=image_window::overlay_circle($0)"], [
        ["dpoint", "center", "", []],
        ["double", "radius", "", []],
        ["tuple_uchar_and_uchar_and_uchar", "color", "{255, 0, 0}", ["/Expr=std::get<0>(color), std::get<1>(color), std::get<2>(color)", "/Cast=rgb_pixel"]],
    ], "", ""],

    ["dlib.image_window.wait_until_closed", "void", [], [], "", ""],
    ["dlib.image_window.is_closed", "bool", [], [], "", ""],

    ["dlib.image_window.get_next_double_click", "bool", [], [
        ["point", "p", "", ["/O"]]
    ], "", ""],

    ["dlib.image_window.wait_for_keypress", "void", ["/External"], [
        ["char", "wait_key", "", []]
    ], "", ""],

    ["dlib.image_window.wait_for_keypress", "void", ["/External"], [
        ["string", "wait_key", "", []]
    ], "", ""],

    ["dlib.image_window.get_next_keypress", "bool", ["/External"], [
        ["char*", "key", "", ["/O"]],
        ["bool*", "is_printable", "", ["/O"]],
        ["vector_keyboard_state_masks", "mods", "", ["/O"]],
        ["bool", "get_keyboard_modifiers", "false", []],
    ], "", ""],

    ["enum dlib.image_window.keyboard_state_masks", "", [], [
        ["const dlib.image_window.KBD_MOD_NONE", "0", []],
        ["const dlib.image_window.KBD_MOD_SHIFT", "1", []],
        ["const dlib.image_window.KBD_MOD_CONTROL", "2", []],
        ["const dlib.image_window.KBD_MOD_ALT", "4", []],
        ["const dlib.image_window.KBD_MOD_META", "8", []],
        ["const dlib.image_window.KBD_MOD_CAPS_LOCK", "16", []],
        ["const dlib.image_window.KBD_MOD_NUM_LOCK", "32", []],
        ["const dlib.image_window.KBD_MOD_SCROLL_LOCK", "64", []],
    ], "", ""],

    ["enum dlib.image_window.non_printable_keyboard_keys", "", [], [
        ["const dlib.image_window.KEY_BACKSPACE", "\"BACKSPACE\"", []],
        ["const dlib.image_window.KEY_SHIFT", "\"SHIFT\"", []],
        ["const dlib.image_window.KEY_CTRL", "\"CTRL\"", []],
        ["const dlib.image_window.KEY_ALT", "\"ALT\"", []],
        ["const dlib.image_window.KEY_PAUSE", "\"PAUSE\"", []],
        ["const dlib.image_window.KEY_CAPS_LOCK", "\"CAPS_LOCK\"", []],
        ["const dlib.image_window.KEY_ESC", "\"ESC\"", []],
        ["const dlib.image_window.KEY_PAGE_UP", "\"PAGE_UP\"", []],
        ["const dlib.image_window.KEY_PAGE_DOWN", "\"PAGE_DOWN\"", []],
        ["const dlib.image_window.KEY_END", "\"END\"", []],
        ["const dlib.image_window.KEY_HOME", "\"HOME\"", []],
        ["const dlib.image_window.KEY_LEFT", "\"LEFT\"", []], // This is the left arrow key
        ["const dlib.image_window.KEY_RIGHT", "\"RIGHT\"", []], // This is the right arrow key
        ["const dlib.image_window.KEY_UP", "\"UP\"", []], // This is the up arrow key
        ["const dlib.image_window.KEY_DOWN", "\"DOWN\"", []], // This is the down arrow key
        ["const dlib.image_window.KEY_INSERT", "\"INSERT\"", []],
        ["const dlib.image_window.KEY_DELETE", "\"DELETE\"", []],
        ["const dlib.image_window.KEY_SCROLL_LOCK", "\"SCROLL_LOCK\"", []],

            // Function Keys
        ["const dlib.image_window.KEY_F1", "\"F1\"", []],
        ["const dlib.image_window.KEY_F2", "\"F2\"", []],
        ["const dlib.image_window.KEY_F3", "\"F3\"", []],
        ["const dlib.image_window.KEY_F4", "\"F4\"", []],
        ["const dlib.image_window.KEY_F5", "\"F5\"", []],
        ["const dlib.image_window.KEY_F6", "\"F6\"", []],
        ["const dlib.image_window.KEY_F7", "\"F7\"", []],
        ["const dlib.image_window.KEY_F8", "\"F8\"", []],
        ["const dlib.image_window.KEY_F9", "\"F9\"", []],
        ["const dlib.image_window.KEY_F10", "\"F10\"", []],
        ["const dlib.image_window.KEY_F11", "\"F11\"", []],
        ["const dlib.image_window.KEY_F12", "\"F12\"", []]
    ], "", ""],
];
