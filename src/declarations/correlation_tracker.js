module.exports = [
	["class dlib.correlation_tracker", "", ["/Simple"], [], "", ""],

	["dlib.correlation_tracker.correlation_tracker", "", [], [], "", ""],

	["dlib.correlation_tracker.start_track", "void", ["/Call=dlib::start_track", "/Expr=*this->__self->get(), $0"], [
		["cv::Mat", "image", "", []],
		["drectangle", "bounding_box", "", []],
	], "", ""],

	["dlib.correlation_tracker.start_track", "void", ["/Call=dlib::start_track", "/Expr=*this->__self->get(), $0"], [
		["cv::Mat", "image", "", []],
		["rectangle", "bounding_box", "", ["/Cast=rectangle"]],
	], "", ""],

	["dlib.correlation_tracker.update", "double", ["/Call=dlib::update", "/Expr=*this->__self->get(), $0"], [
		["cv::Mat", "image", "", []],
	], "", ""],

	["dlib.correlation_tracker.update", "double", ["/Call=dlib::update", "/Expr=*this->__self->get(), $0"], [
		["cv::Mat", "image", "", []],
		["drectangle", "bounding_box", "", []],
	], "", ""],

	["dlib.correlation_tracker.update", "double", ["/Call=dlib::update", "/Expr=*this->__self->get(), $0"], [
		["cv::Mat", "image", "", []],
		["rectangle", "bounding_box", "", ["/Cast=rectangle"]],
	], "", ""],

	["dlib.correlation_tracker.get_position", "drectangle", [], [], "", ""],

];
