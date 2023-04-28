# AutoIt Dlib UDF

## Table Of Contents

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->

- [NamedParameters](#namedparameters)
  - [NamedParameters::create](#namedparameterscreate)
  - [NamedParameters::Add](#namedparametersadd)
  - [NamedParameters::Get](#namedparametersget)
  - [NamedParameters::Items](#namedparametersitems)
  - [NamedParameters::Keys](#namedparameterskeys)
  - [NamedParameters::Remove](#namedparametersremove)
  - [NamedParameters::clear](#namedparametersclear)
  - [NamedParameters::contains](#namedparameterscontains)
  - [NamedParameters::count](#namedparameterscount)
  - [NamedParameters::empty](#namedparametersempty)
  - [NamedParameters::erase](#namedparameterserase)
  - [NamedParameters::get\_Item](#namedparametersget%5C_item)
  - [NamedParameters::get\_\_NewEnum](#namedparametersget%5C_%5C_newenum)
  - [NamedParameters::has](#namedparametershas)
  - [NamedParameters::isNamedParameters](#namedparametersisnamedparameters)
  - [NamedParameters::max\_size](#namedparametersmax%5C_size)
  - [NamedParameters::merge](#namedparametersmerge)
  - [NamedParameters::put\_Item](#namedparametersput%5C_item)
  - [NamedParameters::size](#namedparameterssize)
- [autoit](#autoit)
  - [autoit::findFile](#autoitfindfile)
  - [autoit::findFiles](#autoitfindfiles)
- [com](#com)
  - [com.Thread](#comthread)
  - [com.ThreadSafeQueue](#comthreadsafequeue)
- [com::Thread](#comthread)
  - [com::Thread::get\_create](#comthreadget%5C_create)
  - [com::Thread::join](#comthreadjoin)
  - [com::Thread::start](#comthreadstart)
- [com::ThreadSafeQueue](#comthreadsafequeue)
  - [com::ThreadSafeQueue::get\_create](#comthreadsafequeueget%5C_create)
  - [com::ThreadSafeQueue::clear](#comthreadsafequeueclear)
  - [com::ThreadSafeQueue::get](#comthreadsafequeueget)
  - [com::ThreadSafeQueue::push](#comthreadsafequeuepush)
- [dlib](#dlib)
  - [dlib.binary\_test](#dlibbinary%5C_test)
  - [dlib.regression\_test](#dlibregression%5C_test)
  - [dlib.ranking\_test](#dlibranking%5C_test)
  - [dlib.cca\_outputs](#dlibcca%5C_outputs)
  - [dlib.cnn\_face\_detection\_model\_v1](#dlibcnn%5C_face%5C_detection%5C_model%5C_v1)
  - [dlib.face\_recognition\_model\_v1](#dlibface%5C_recognition%5C_model%5C_v1)
  - [dlib.\_row](#dlib%5C_row)
  - [dlib.segmenter\_type](#dlibsegmenter%5C_type)
  - [dlib.segmenter\_params](#dlibsegmenter%5C_params)
  - [dlib.segmenter\_test](#dlibsegmenter%5C_test)
  - [dlib.shape\_predictor\_training\_options](#dlibshape%5C_predictor%5C_training%5C_options)
  - [dlib.simple\_object\_detector\_training\_options](#dlibsimple%5C_object%5C_detector%5C_training%5C_options)
  - [dlib.simple\_test\_results](#dlibsimple%5C_test%5C_results)
  - [dlib.simple\_object\_detector\_com](#dlibsimple%5C_object%5C_detector%5C_com)
  - [dlib.simple\_structural\_svm\_problem](#dlibsimple%5C_structural%5C_svm%5C_problem)
  - [dlib.mmod\_rect](#dlibmmod%5C_rect)
  - [dlib.cuda](#dlibcuda)
  - [dlib.correlation\_tracker](#dlibcorrelation%5C_tracker)
  - [dlib.\_radial\_basis\_kernel](#dlib%5C_radial%5C_basis%5C_kernel)
  - [dlib.\_linear\_kernel](#dlib%5C_linear%5C_kernel)
  - [dlib.\_decision\_function\_linear](#dlib%5C_decision%5C_function%5C_linear)
  - [dlib.\_decision\_function\_sparse\_linear](#dlib%5C_decision%5C_function%5C_sparse%5C_linear)
  - [dlib.\_decision\_function\_histogram\_intersection](#dlib%5C_decision%5C_function%5C_histogram%5C_intersection)
  - [dlib.\_decision\_function\_sparse\_histogram\_intersection](#dlib%5C_decision%5C_function%5C_sparse%5C_histogram%5C_intersection)
  - [dlib.\_decision\_function\_polynomial](#dlib%5C_decision%5C_function%5C_polynomial)
  - [dlib.\_decision\_function\_sparse\_polynomial](#dlib%5C_decision%5C_function%5C_sparse%5C_polynomial)
  - [dlib.\_decision\_function\_radial\_basis](#dlib%5C_decision%5C_function%5C_radial%5C_basis)
  - [dlib.\_decision\_function\_sparse\_radial\_basis](#dlib%5C_decision%5C_function%5C_sparse%5C_radial%5C_basis)
  - [dlib.\_decision\_function\_sigmoid](#dlib%5C_decision%5C_function%5C_sigmoid)
  - [dlib.\_decision\_function\_sparse\_sigmoid](#dlib%5C_decision%5C_function%5C_sparse%5C_sigmoid)
  - [dlib.\_normalized\_decision\_function\_radial\_basis](#dlib%5C_normalized%5C_decision%5C_function%5C_radial%5C_basis)
  - [dlib.extended](#dlibextended)
  - [dlib.version](#dlibversion)
  - [dlib.time\_compiled](#dlibtime%5C_compiled)
  - [dlib.DLIB\_USE\_CUDA](#dlibdlib%5C_use%5C_cuda)
  - [dlib.DLIB\_USE\_BLAS](#dlibdlib%5C_use%5C_blas)
  - [dlib.DLIB\_USE\_LAPACK](#dlibdlib%5C_use%5C_lapack)
  - [dlib.USE\_AVX\_INSTRUCTIONS](#dlibuse%5C_avx%5C_instructions)
  - [dlib.USE\_NEON\_INSTRUCTIONS](#dlibuse%5C_neon%5C_instructions)
  - [dlib.function\_evaluation](#dlibfunction%5C_evaluation)
  - [dlib.function\_spec](#dlibfunction%5C_spec)
  - [dlib.function\_evaluation\_request](#dlibfunction%5C_evaluation%5C_request)
  - [dlib.global\_function\_search](#dlibglobal%5C_function%5C_search)
  - [dlib.image\_window](#dlibimage%5C_window)
  - [dlib.rgb\_pixel](#dlibrgb%5C_pixel)
  - [dlib.image\_dataset\_metadata](#dlibimage%5C_dataset%5C_metadata)
  - [dlib.line](#dlibline)
  - [dlib.Matrix](#dlibmatrix)
  - [dlib.fhog\_object\_detector](#dlibfhog%5C_object%5C_detector)
  - [dlib.rect\_filter](#dlibrect%5C_filter)
  - [dlib.rectangle](#dlibrectangle)
  - [dlib.drectangle](#dlibdrectangle)
  - [dlib.full\_object\_detection](#dlibfull%5C_object%5C_detection)
  - [dlib.shape\_predictor](#dlibshape%5C_predictor)
  - [dlib.svm\_c\_trainer\_radial\_basis](#dlibsvm%5C_c%5C_trainer%5C_radial%5C_basis)
  - [dlib.svm\_c\_trainer\_sparse\_radial\_basis](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basis)
  - [dlib.svm\_c\_trainer\_histogram\_intersection](#dlibsvm%5C_c%5C_trainer%5C_histogram%5C_intersection)
  - [dlib.svm\_c\_trainer\_sparse\_histogram\_intersection](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersection)
  - [dlib.svm\_c\_trainer\_linear](#dlibsvm%5C_c%5C_trainer%5C_linear)
  - [dlib.svm\_c\_trainer\_sparse\_linear](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_linear)
  - [dlib.rvm\_trainer\_radial\_basis](#dlibrvm%5C_trainer%5C_radial%5C_basis)
  - [dlib.rvm\_trainer\_sparse\_radial\_basis](#dlibrvm%5C_trainer%5C_sparse%5C_radial%5C_basis)
  - [dlib.rvm\_trainer\_histogram\_intersection](#dlibrvm%5C_trainer%5C_histogram%5C_intersection)
  - [dlib.rvm\_trainer\_sparse\_histogram\_intersection](#dlibrvm%5C_trainer%5C_sparse%5C_histogram%5C_intersection)
  - [dlib.rvm\_trainer\_linear](#dlibrvm%5C_trainer%5C_linear)
  - [dlib.rvm\_trainer\_sparse\_linear](#dlibrvm%5C_trainer%5C_sparse%5C_linear)
  - [dlib.vec\_ranking\_pair](#dlibvec%5C_ranking%5C_pair)
  - [dlib.sparse\_ranking\_pair](#dlibsparse%5C_ranking%5C_pair)
  - [dlib.vec\_svm\_rank\_trainer](#dlibvec%5C_svm%5C_rank%5C_trainer)
  - [dlib.svm\_rank\_trainer\_sparse](#dlibsvm%5C_rank%5C_trainer%5C_sparse)
  - [dlib.SpaceVector](#dlibspacevector)
  - [dlib.point\_transform\_projective](#dlibpoint%5C_transform%5C_projective)
  - [dlib.dpoint](#dlibdpoint)
  - [dlib.point](#dlibpoint)
  - [dlib::angle\_between\_lines](#dlibangle%5C_between%5C_lines)
  - [dlib::apply\_cca\_transform](#dlibapply%5C_cca%5C_transform)
  - [dlib::assignment\_cost](#dlibassignment%5C_cost)
  - [dlib::auto\_train\_rbf\_classifier](#dlibauto%5C_train%5C_rbf%5C_classifier)
  - [dlib::cca](#dlibcca)
  - [dlib::center](#dlibcenter)
  - [dlib::centered\_drect](#dlibcentered%5C_drect)
  - [dlib::centered\_rect](#dlibcentered%5C_rect)
  - [dlib::centered\_rects](#dlibcentered%5C_rects)
  - [dlib::chinese\_whispers](#dlibchinese%5C_whispers)
  - [dlib::chinese\_whispers\_clustering](#dlibchinese%5C_whispers%5C_clustering)
  - [dlib::count\_points\_between\_lines](#dlibcount%5C_points%5C_between%5C_lines)
  - [dlib::count\_points\_on\_side\_of\_line](#dlibcount%5C_points%5C_on%5C_side%5C_of%5C_line)
  - [dlib::count\_steps\_without\_decrease](#dlibcount%5C_steps%5C_without%5C_decrease)
  - [dlib::count\_steps\_without\_decrease\_robust](#dlibcount%5C_steps%5C_without%5C_decrease%5C_robust)
  - [dlib::cross\_validate\_ranking\_trainer](#dlibcross%5C_validate%5C_ranking%5C_trainer)
  - [dlib::cross\_validate\_sequence\_segmenter](#dlibcross%5C_validate%5C_sequence%5C_segmenter)
  - [dlib::cross\_validate\_trainer](#dlibcross%5C_validate%5C_trainer)
  - [dlib::cross\_validate\_trainer\_threaded](#dlibcross%5C_validate%5C_trainer%5C_threaded)
  - [dlib::distance\_to\_line](#dlibdistance%5C_to%5C_line)
  - [dlib::dnn\_prefer\_fastest\_algorithms](#dlibdnn%5C_prefer%5C_fastest%5C_algorithms)
  - [dlib::dot](#dlibdot)
  - [dlib::find\_candidate\_object\_locations](#dlibfind%5C_candidate%5C_object%5C_locations)
  - [dlib::find\_max\_global](#dlibfind%5C_max%5C_global)
  - [dlib::find\_min\_global](#dlibfind%5C_min%5C_global)
  - [dlib::find\_optimal\_rect\_filter](#dlibfind%5C_optimal%5C_rect%5C_filter)
  - [dlib::find\_projective\_transform](#dlibfind%5C_projective%5C_transform)
  - [dlib::get\_face\_chip](#dlibget%5C_face%5C_chip)
  - [dlib::get\_face\_chips](#dlibget%5C_face%5C_chips)
  - [dlib::get\_frontal\_face\_detector](#dlibget%5C_frontal%5C_face%5C_detector)
  - [dlib::hit\_enter\_to\_continue](#dlibhit%5C_enter%5C_to%5C_continue)
  - [dlib::intersect](#dlibintersect)
  - [dlib::inv](#dlibinv)
  - [dlib::jitter\_image](#dlibjitter%5C_image)
  - [dlib::length](#dliblength)
  - [dlib::load\_grayscale\_image](#dlibload%5C_grayscale%5C_image)
  - [dlib::load\_libsvm\_formatted\_data](#dlibload%5C_libsvm%5C_formatted%5C_data)
  - [dlib::load\_rgb\_image](#dlibload%5C_rgb%5C_image)
  - [dlib::make\_sparse\_vector](#dlibmake%5C_sparse%5C_vector)
  - [dlib::max\_cost\_assignment](#dlibmax%5C_cost%5C_assignment)
  - [dlib::max\_index\_plus\_one](#dlibmax%5C_index%5C_plus%5C_one)
  - [dlib::num\_separable\_filters](#dlibnum%5C_separable%5C_filters)
  - [dlib::polygon\_area](#dlibpolygon%5C_area)
  - [dlib::probability\_that\_sequence\_is\_increasing](#dlibprobability%5C_that%5C_sequence%5C_is%5C_increasing)
  - [dlib::reduce](#dlibreduce)
  - [dlib::save\_face\_chip](#dlibsave%5C_face%5C_chip)
  - [dlib::save\_face\_chips](#dlibsave%5C_face%5C_chips)
  - [dlib::save\_image](#dlibsave%5C_image)
  - [dlib::save\_libsvm\_formatted\_data](#dlibsave%5C_libsvm%5C_formatted%5C_data)
  - [dlib::scale\_rect](#dlibscale%5C_rect)
  - [dlib::set\_dnn\_prefer\_fastest\_algorithms](#dlibset%5C_dnn%5C_prefer%5C_fastest%5C_algorithms)
  - [dlib::set\_dnn\_prefer\_smallest\_algorithms](#dlibset%5C_dnn%5C_prefer%5C_smallest%5C_algorithms)
  - [dlib::shrink\_rect](#dlibshrink%5C_rect)
  - [dlib::signed\_distance\_to\_line](#dlibsigned%5C_distance%5C_to%5C_line)
  - [dlib::solve\_structural\_svm\_problem](#dlibsolve%5C_structural%5C_svm%5C_problem)
  - [dlib::test\_binary\_decision\_function](#dlibtest%5C_binary%5C_decision%5C_function)
  - [dlib::test\_ranking\_function](#dlibtest%5C_ranking%5C_function)
  - [dlib::test\_regression\_function](#dlibtest%5C_regression%5C_function)
  - [dlib::test\_sequence\_segmenter](#dlibtest%5C_sequence%5C_segmenter)
  - [dlib::test\_shape\_predictor](#dlibtest%5C_shape%5C_predictor)
  - [dlib::test\_simple\_object\_detector](#dlibtest%5C_simple%5C_object%5C_detector)
  - [dlib::threshold\_filter\_singular\_values](#dlibthreshold%5C_filter%5C_singular%5C_values)
  - [dlib::train\_sequence\_segmenter](#dlibtrain%5C_sequence%5C_segmenter)
  - [dlib::train\_shape\_predictor](#dlibtrain%5C_shape%5C_predictor)
  - [dlib::train\_simple\_object\_detector](#dlibtrain%5C_simple%5C_object%5C_detector)
  - [dlib::translate\_rect](#dlibtranslate%5C_rect)
  - [dlib::variant](#dlibvariant)
- [dlib::binary\_test](#dlibbinary%5C_test)
  - [binary\_test.class1\_accuracy](#binary%5C_testclass1%5C_accuracy)
  - [binary\_test.class2\_accuracy](#binary%5C_testclass2%5C_accuracy)
  - [dlib::binary\_test::get\_create](#dlibbinary%5C_testget%5C_create)
  - [dlib::binary\_test::ToString](#dlibbinary%5C_testtostring)
- [dlib::regression\_test](#dlibregression%5C_test)
  - [regression\_test.mean\_squared\_error](#regression%5C_testmean%5C_squared%5C_error)
  - [regression\_test.R\_squared](#regression%5C_testr%5C_squared)
  - [regression\_test.mean\_average\_error](#regression%5C_testmean%5C_average%5C_error)
  - [regression\_test.mean\_error\_stddev](#regression%5C_testmean%5C_error%5C_stddev)
  - [dlib::regression\_test::get\_create](#dlibregression%5C_testget%5C_create)
  - [dlib::regression\_test::ToString](#dlibregression%5C_testtostring)
- [dlib::ranking\_test](#dlibranking%5C_test)
  - [ranking\_test.ranking\_accuracy](#ranking%5C_testranking%5C_accuracy)
  - [ranking\_test.mean\_ap](#ranking%5C_testmean%5C_ap)
  - [dlib::ranking\_test::get\_create](#dlibranking%5C_testget%5C_create)
  - [dlib::ranking\_test::ToString](#dlibranking%5C_testtostring)
- [dlib::cca\_outputs](#dlibcca%5C_outputs)
  - [cca\_outputs.correlations](#cca%5C_outputscorrelations)
  - [cca\_outputs.Ltrans](#cca%5C_outputsltrans)
  - [cca\_outputs.Rtrans](#cca%5C_outputsrtrans)
  - [dlib::cca\_outputs::get\_create](#dlibcca%5C_outputsget%5C_create)
- [dlib::cnn\_face\_detection\_model\_v1](#dlibcnn%5C_face%5C_detection%5C_model%5C_v1)
  - [dlib::cnn\_face\_detection\_model\_v1::create](#dlibcnn%5C_face%5C_detection%5C_model%5C_v1create)
  - [dlib::cnn\_face\_detection\_model\_v1::detect](#dlibcnn%5C_face%5C_detection%5C_model%5C_v1detect)
  - [dlib::cnn\_face\_detection\_model\_v1::detect\_multi](#dlibcnn%5C_face%5C_detection%5C_model%5C_v1detect%5C_multi)
  - [dlib::cnn\_face\_detection\_model\_v1::get\_call](#dlibcnn%5C_face%5C_detection%5C_model%5C_v1get%5C_call)
- [dlib::face\_recognition\_model\_v1](#dlibface%5C_recognition%5C_model%5C_v1)
  - [dlib::face\_recognition\_model\_v1::get\_create](#dlibface%5C_recognition%5C_model%5C_v1get%5C_create)
  - [dlib::face\_recognition\_model\_v1::compute\_face\_descriptor](#dlibface%5C_recognition%5C_model%5C_v1compute%5C_face%5C_descriptor)
- [dlib::\_row](#dlib%5C_row)
  - [dlib::\_row::get\_create](#dlib%5C_rowget%5C_create)
  - [dlib::\_row::ToString](#dlib%5C_rowtostring)
  - [dlib::\_row::get](#dlib%5C_rowget)
  - [dlib::\_row::set](#dlib%5C_rowset)
- [dlib::segmenter\_type](#dlibsegmenter%5C_type)
  - [segmenter\_type.weights](#segmenter%5C_typeweights)
  - [dlib::segmenter\_type::create](#dlibsegmenter%5C_typecreate)
  - [dlib::segmenter\_type::get\_call](#dlibsegmenter%5C_typeget%5C_call)
- [dlib::segmenter\_params](#dlibsegmenter%5C_params)
  - [segmenter\_params.use\_BIO\_model](#segmenter%5C_paramsuse%5C_bio%5C_model)
  - [segmenter\_params.use\_high\_order\_features](#segmenter%5C_paramsuse%5C_high%5C_order%5C_features)
  - [segmenter\_params.allow\_negative\_weights](#segmenter%5C_paramsallow%5C_negative%5C_weights)
  - [segmenter\_params.window\_size](#segmenter%5C_paramswindow%5C_size)
  - [segmenter\_params.num\_threads](#segmenter%5C_paramsnum%5C_threads)
  - [segmenter\_params.epsilon](#segmenter%5C_paramsepsilon)
  - [segmenter\_params.max\_cache\_size](#segmenter%5C_paramsmax%5C_cache%5C_size)
  - [segmenter\_params.be\_verbose](#segmenter%5C_paramsbe%5C_verbose)
  - [segmenter\_params.C](#segmenter%5C_paramsc)
  - [dlib::segmenter\_params::get\_create](#dlibsegmenter%5C_paramsget%5C_create)
  - [dlib::segmenter\_params::ToString](#dlibsegmenter%5C_paramstostring)
- [dlib::segmenter\_test](#dlibsegmenter%5C_test)
  - [segmenter\_test.precision](#segmenter%5C_testprecision)
  - [segmenter\_test.recall](#segmenter%5C_testrecall)
  - [segmenter\_test.f1](#segmenter%5C_testf1)
  - [dlib::segmenter\_test::get\_create](#dlibsegmenter%5C_testget%5C_create)
  - [dlib::segmenter\_test::ToString](#dlibsegmenter%5C_testtostring)
- [dlib::shape\_predictor\_training\_options](#dlibshape%5C_predictor%5C_training%5C_options)
  - [shape\_predictor\_training\_options.be\_verbose](#shape%5C_predictor%5C_training%5C_optionsbe%5C_verbose)
  - [shape\_predictor\_training\_options.cascade\_depth](#shape%5C_predictor%5C_training%5C_optionscascade%5C_depth)
  - [shape\_predictor\_training\_options.tree\_depth](#shape%5C_predictor%5C_training%5C_optionstree%5C_depth)
  - [shape\_predictor\_training\_options.num\_trees\_per\_cascade\_level](#shape%5C_predictor%5C_training%5C_optionsnum%5C_trees%5C_per%5C_cascade%5C_level)
  - [shape\_predictor\_training\_options.nu](#shape%5C_predictor%5C_training%5C_optionsnu)
  - [shape\_predictor\_training\_options.oversampling\_amount](#shape%5C_predictor%5C_training%5C_optionsoversampling%5C_amount)
  - [shape\_predictor\_training\_options.oversampling\_translation\_jitter](#shape%5C_predictor%5C_training%5C_optionsoversampling%5C_translation%5C_jitter)
  - [shape\_predictor\_training\_options.feature\_pool\_size](#shape%5C_predictor%5C_training%5C_optionsfeature%5C_pool%5C_size)
  - [shape\_predictor\_training\_options.lambda\_param](#shape%5C_predictor%5C_training%5C_optionslambda%5C_param)
  - [shape\_predictor\_training\_options.num\_test\_splits](#shape%5C_predictor%5C_training%5C_optionsnum%5C_test%5C_splits)
  - [shape\_predictor\_training\_options.feature\_pool\_region\_padding](#shape%5C_predictor%5C_training%5C_optionsfeature%5C_pool%5C_region%5C_padding)
  - [shape\_predictor\_training\_options.random\_seed](#shape%5C_predictor%5C_training%5C_optionsrandom%5C_seed)
  - [shape\_predictor\_training\_options.landmark\_relative\_padding\_mode](#shape%5C_predictor%5C_training%5C_optionslandmark%5C_relative%5C_padding%5C_mode)
  - [shape\_predictor\_training\_options.num\_threads](#shape%5C_predictor%5C_training%5C_optionsnum%5C_threads)
  - [dlib::shape\_predictor\_training\_options::get\_create](#dlibshape%5C_predictor%5C_training%5C_optionsget%5C_create)
  - [dlib::shape\_predictor\_training\_options::ToString](#dlibshape%5C_predictor%5C_training%5C_optionstostring)
- [dlib::simple\_object\_detector\_training\_options](#dlibsimple%5C_object%5C_detector%5C_training%5C_options)
  - [simple\_object\_detector\_training\_options.be\_verbose](#simple%5C_object%5C_detector%5C_training%5C_optionsbe%5C_verbose)
  - [simple\_object\_detector\_training\_options.add\_left\_right\_image\_flips](#simple%5C_object%5C_detector%5C_training%5C_optionsadd%5C_left%5C_right%5C_image%5C_flips)
  - [simple\_object\_detector\_training\_options.num\_threads](#simple%5C_object%5C_detector%5C_training%5C_optionsnum%5C_threads)
  - [simple\_object\_detector\_training\_options.detection\_window\_size](#simple%5C_object%5C_detector%5C_training%5C_optionsdetection%5C_window%5C_size)
  - [simple\_object\_detector\_training\_options.C](#simple%5C_object%5C_detector%5C_training%5C_optionsc)
  - [simple\_object\_detector\_training\_options.epsilon](#simple%5C_object%5C_detector%5C_training%5C_optionsepsilon)
  - [simple\_object\_detector\_training\_options.upsample\_limit](#simple%5C_object%5C_detector%5C_training%5C_optionsupsample%5C_limit)
  - [simple\_object\_detector\_training\_options.nuclear\_norm\_regularization\_strength](#simple%5C_object%5C_detector%5C_training%5C_optionsnuclear%5C_norm%5C_regularization%5C_strength)
  - [simple\_object\_detector\_training\_options.max\_runtime\_seconds](#simple%5C_object%5C_detector%5C_training%5C_optionsmax%5C_runtime%5C_seconds)
  - [dlib::simple\_object\_detector\_training\_options::get\_create](#dlibsimple%5C_object%5C_detector%5C_training%5C_optionsget%5C_create)
  - [dlib::simple\_object\_detector\_training\_options::ToString](#dlibsimple%5C_object%5C_detector%5C_training%5C_optionstostring)
- [dlib::simple\_test\_results](#dlibsimple%5C_test%5C_results)
  - [simple\_test\_results.precision](#simple%5C_test%5C_resultsprecision)
  - [simple\_test\_results.recall](#simple%5C_test%5C_resultsrecall)
  - [simple\_test\_results.average\_precision](#simple%5C_test%5C_resultsaverage%5C_precision)
  - [dlib::simple\_test\_results::get\_create](#dlibsimple%5C_test%5C_resultsget%5C_create)
  - [dlib::simple\_test\_results::ToString](#dlibsimple%5C_test%5C_resultstostring)
- [dlib::simple\_object\_detector\_com](#dlibsimple%5C_object%5C_detector%5C_com)
  - [simple\_object\_detector\_com.detector](#simple%5C_object%5C_detector%5C_comdetector)
  - [simple\_object\_detector\_com.upsampling\_amount](#simple%5C_object%5C_detector%5C_comupsampling%5C_amount)
  - [simple\_object\_detector\_com.detection\_window\_width](#simple%5C_object%5C_detector%5C_comdetection%5C_window%5C_width)
  - [simple\_object\_detector\_com.detection\_window\_height](#simple%5C_object%5C_detector%5C_comdetection%5C_window%5C_height)
  - [simple\_object\_detector\_com.num\_detectors](#simple%5C_object%5C_detector%5C_comnum%5C_detectors)
  - [dlib::simple\_object\_detector\_com::create](#dlibsimple%5C_object%5C_detector%5C_comcreate)
  - [dlib::simple\_object\_detector\_com::get\_call](#dlibsimple%5C_object%5C_detector%5C_comget%5C_call)
  - [dlib::simple\_object\_detector\_com::run\_multiple](#dlibsimple%5C_object%5C_detector%5C_comrun%5C_multiple)
- [dlib::simple\_structural\_svm\_problem](#dlibsimple%5C_structural%5C_svm%5C_problem)
  - [simple\_structural\_svm\_problem.C](#simple%5C_structural%5C_svm%5C_problemc)
  - [simple\_structural\_svm\_problem.num\_samples](#simple%5C_structural%5C_svm%5C_problemnum%5C_samples)
  - [simple\_structural\_svm\_problem.num\_dimensions](#simple%5C_structural%5C_svm%5C_problemnum%5C_dimensions)
  - [simple\_structural\_svm\_problem.get\_truth\_joint\_feature\_vector](#simple%5C_structural%5C_svm%5C_problemget%5C_truth%5C_joint%5C_feature%5C_vector)
  - [simple\_structural\_svm\_problem.separation\_oracle](#simple%5C_structural%5C_svm%5C_problemseparation%5C_oracle)
  - [simple\_structural\_svm\_problem.epsilon](#simple%5C_structural%5C_svm%5C_problemepsilon)
  - [simple\_structural\_svm\_problem.max\_cache\_size](#simple%5C_structural%5C_svm%5C_problemmax%5C_cache%5C_size)
  - [simple\_structural\_svm\_problem.be\_verbose](#simple%5C_structural%5C_svm%5C_problembe%5C_verbose)
  - [simple\_structural\_svm\_problem.use\_sparse\_feature\_vectors](#simple%5C_structural%5C_svm%5C_problemuse%5C_sparse%5C_feature%5C_vectors)
  - [simple\_structural\_svm\_problem.learns\_nonnegative\_weights](#simple%5C_structural%5C_svm%5C_problemlearns%5C_nonnegative%5C_weights)
  - [simple\_structural\_svm\_problem.result](#simple%5C_structural%5C_svm%5C_problemresult)
  - [dlib::simple\_structural\_svm\_problem::get\_create](#dlibsimple%5C_structural%5C_svm%5C_problemget%5C_create)
- [cv](#cv)
  - [cv.cuda](#cvcuda)
  - [cv.\_InputArray](#cv%5C_inputarray)
  - [cv.\_OutputArray](#cv%5C_outputarray)
  - [cv.\_InputOutputArray](#cv%5C_inputoutputarray)
  - [cv.Mat](#cvmat)
  - [cv.Range](#cvrange)
  - [cv.UMat](#cvumat)
  - [cv::createMatFromBitmap](#cvcreatematfrombitmap)
  - [cv::haveImageReader](#cvhaveimagereader)
  - [cv::haveImageWriter](#cvhaveimagewriter)
  - [cv::imcount](#cvimcount)
  - [cv::imdecode](#cvimdecode)
  - [cv::imencode](#cvimencode)
  - [cv::imread](#cvimread)
  - [cv::imreadmulti](#cvimreadmulti)
  - [cv::imwrite](#cvimwrite)
  - [cv::imwritemulti](#cvimwritemulti)
  - [cv.ACCESS\_READ\_](#cvaccess%5C_read%5C_)
  - [cv.ACCESS\_WRITE\_](#cvaccess%5C_write%5C_)
  - [cv.ACCESS\_RW\_](#cvaccess%5C_rw%5C_)
  - [cv.ACCESS\_MASK\_](#cvaccess%5C_mask%5C_)
  - [cv.ACCESS\_FAST\_](#cvaccess%5C_fast%5C_)
  - [cv.USAGE\_DEFAULT\_](#cvusage%5C_default%5C_)
  - [cv.USAGE\_ALLOCATE\_HOST\_MEMORY\_](#cvusage%5C_allocate%5C_host%5C_memory%5C_)
  - [cv.USAGE\_ALLOCATE\_DEVICE\_MEMORY\_](#cvusage%5C_allocate%5C_device%5C_memory%5C_)
  - [cv.USAGE\_ALLOCATE\_SHARED\_MEMORY\_](#cvusage%5C_allocate%5C_shared%5C_memory%5C_)
  - [cv.\_\_UMAT\_USAGE\_FLAGS\_32BIT\_](#cv%5C_%5C_umat%5C_usage%5C_flags%5C_32bit%5C_)
- [dlib::mmod\_rect](#dlibmmod%5C_rect)
  - [mmod\_rect.rect](#mmod%5C_rectrect)
  - [mmod\_rect.confidence](#mmod%5C_rectconfidence)
  - [mmod\_rect.label](#mmod%5C_rectlabel)
  - [mmod\_rect.ignore](#mmod%5C_rectignore)
  - [dlib::mmod\_rect::get\_create](#dlibmmod%5C_rectget%5C_create)
- [dlib::cuda](#dlibcuda)
  - [dlib::cuda::can\_access\_peer](#dlibcudacan%5C_access%5C_peer)
  - [dlib::cuda::device\_synchronize](#dlibcudadevice%5C_synchronize)
  - [dlib::cuda::get\_device](#dlibcudaget%5C_device)
  - [dlib::cuda::get\_device\_name](#dlibcudaget%5C_device%5C_name)
  - [dlib::cuda::set\_current\_device\_blocking\_sync](#dlibcudaset%5C_current%5C_device%5C_blocking%5C_sync)
  - [dlib::cuda::set\_device](#dlibcudaset%5C_device)
- [dlib::correlation\_tracker](#dlibcorrelation%5C_tracker)
  - [dlib::correlation\_tracker::get\_create](#dlibcorrelation%5C_trackerget%5C_create)
  - [dlib::correlation\_tracker::get\_position](#dlibcorrelation%5C_trackerget%5C_position)
  - [dlib::correlation\_tracker::start\_track](#dlibcorrelation%5C_trackerstart%5C_track)
  - [dlib::correlation\_tracker::update](#dlibcorrelation%5C_trackerupdate)
- [cv::cuda](#cvcuda)
  - [cuda.GpuMat](#cudagpumat)
- [dlib::\_radial\_basis\_kernel](#dlib%5C_radial%5C_basis%5C_kernel)
  - [\_radial\_basis\_kernel.gamma](#%5C_radial%5C_basis%5C_kernelgamma)
  - [dlib::\_radial\_basis\_kernel::get\_create](#dlib%5C_radial%5C_basis%5C_kernelget%5C_create)
- [dlib::\_linear\_kernel](#dlib%5C_linear%5C_kernel)
  - [dlib::\_linear\_kernel::get\_create](#dlib%5C_linear%5C_kernelget%5C_create)
- [dlib::\_decision\_function\_linear](#dlib%5C_decision%5C_function%5C_linear)
  - [\_decision\_function\_linear.weights](#%5C_decision%5C_function%5C_linearweights)
  - [\_decision\_function\_linear.bias](#%5C_decision%5C_function%5C_linearbias)
  - [dlib::\_decision\_function\_linear::create](#dlib%5C_decision%5C_function%5C_linearcreate)
  - [dlib::\_decision\_function\_linear::get\_call](#dlib%5C_decision%5C_function%5C_linearget%5C_call)
- [dlib::\_decision\_function\_sparse\_linear](#dlib%5C_decision%5C_function%5C_sparse%5C_linear)
  - [\_decision\_function\_sparse\_linear.weights](#%5C_decision%5C_function%5C_sparse%5C_linearweights)
  - [\_decision\_function\_sparse\_linear.bias](#%5C_decision%5C_function%5C_sparse%5C_linearbias)
  - [dlib::\_decision\_function\_sparse\_linear::create](#dlib%5C_decision%5C_function%5C_sparse%5C_linearcreate)
  - [dlib::\_decision\_function\_sparse\_linear::get\_call](#dlib%5C_decision%5C_function%5C_sparse%5C_linearget%5C_call)
- [dlib::\_decision\_function\_histogram\_intersection](#dlib%5C_decision%5C_function%5C_histogram%5C_intersection)
  - [\_decision\_function\_histogram\_intersection.alpha](#%5C_decision%5C_function%5C_histogram%5C_intersectionalpha)
  - [\_decision\_function\_histogram\_intersection.b](#%5C_decision%5C_function%5C_histogram%5C_intersectionb)
  - [\_decision\_function\_histogram\_intersection.basis\_vectors](#%5C_decision%5C_function%5C_histogram%5C_intersectionbasis%5C_vectors)
  - [dlib::\_decision\_function\_histogram\_intersection::create](#dlib%5C_decision%5C_function%5C_histogram%5C_intersectioncreate)
  - [dlib::\_decision\_function\_histogram\_intersection::get\_call](#dlib%5C_decision%5C_function%5C_histogram%5C_intersectionget%5C_call)
- [dlib::\_decision\_function\_sparse\_histogram\_intersection](#dlib%5C_decision%5C_function%5C_sparse%5C_histogram%5C_intersection)
  - [\_decision\_function\_sparse\_histogram\_intersection.alpha](#%5C_decision%5C_function%5C_sparse%5C_histogram%5C_intersectionalpha)
  - [\_decision\_function\_sparse\_histogram\_intersection.b](#%5C_decision%5C_function%5C_sparse%5C_histogram%5C_intersectionb)
  - [\_decision\_function\_sparse\_histogram\_intersection.basis\_vectors](#%5C_decision%5C_function%5C_sparse%5C_histogram%5C_intersectionbasis%5C_vectors)
  - [dlib::\_decision\_function\_sparse\_histogram\_intersection::create](#dlib%5C_decision%5C_function%5C_sparse%5C_histogram%5C_intersectioncreate)
  - [dlib::\_decision\_function\_sparse\_histogram\_intersection::get\_call](#dlib%5C_decision%5C_function%5C_sparse%5C_histogram%5C_intersectionget%5C_call)
- [dlib::\_decision\_function\_polynomial](#dlib%5C_decision%5C_function%5C_polynomial)
  - [\_decision\_function\_polynomial.alpha](#%5C_decision%5C_function%5C_polynomialalpha)
  - [\_decision\_function\_polynomial.b](#%5C_decision%5C_function%5C_polynomialb)
  - [\_decision\_function\_polynomial.basis\_vectors](#%5C_decision%5C_function%5C_polynomialbasis%5C_vectors)
  - [dlib::\_decision\_function\_polynomial::create](#dlib%5C_decision%5C_function%5C_polynomialcreate)
  - [dlib::\_decision\_function\_polynomial::get\_call](#dlib%5C_decision%5C_function%5C_polynomialget%5C_call)
- [dlib::\_decision\_function\_sparse\_polynomial](#dlib%5C_decision%5C_function%5C_sparse%5C_polynomial)
  - [\_decision\_function\_sparse\_polynomial.alpha](#%5C_decision%5C_function%5C_sparse%5C_polynomialalpha)
  - [\_decision\_function\_sparse\_polynomial.b](#%5C_decision%5C_function%5C_sparse%5C_polynomialb)
  - [\_decision\_function\_sparse\_polynomial.basis\_vectors](#%5C_decision%5C_function%5C_sparse%5C_polynomialbasis%5C_vectors)
  - [dlib::\_decision\_function\_sparse\_polynomial::create](#dlib%5C_decision%5C_function%5C_sparse%5C_polynomialcreate)
  - [dlib::\_decision\_function\_sparse\_polynomial::get\_call](#dlib%5C_decision%5C_function%5C_sparse%5C_polynomialget%5C_call)
- [dlib::\_decision\_function\_radial\_basis](#dlib%5C_decision%5C_function%5C_radial%5C_basis)
  - [\_decision\_function\_radial\_basis.alpha](#%5C_decision%5C_function%5C_radial%5C_basisalpha)
  - [\_decision\_function\_radial\_basis.b](#%5C_decision%5C_function%5C_radial%5C_basisb)
  - [\_decision\_function\_radial\_basis.basis\_vectors](#%5C_decision%5C_function%5C_radial%5C_basisbasis%5C_vectors)
  - [dlib::\_decision\_function\_radial\_basis::create](#dlib%5C_decision%5C_function%5C_radial%5C_basiscreate)
  - [dlib::\_decision\_function\_radial\_basis::get\_call](#dlib%5C_decision%5C_function%5C_radial%5C_basisget%5C_call)
- [dlib::\_decision\_function\_sparse\_radial\_basis](#dlib%5C_decision%5C_function%5C_sparse%5C_radial%5C_basis)
  - [\_decision\_function\_sparse\_radial\_basis.alpha](#%5C_decision%5C_function%5C_sparse%5C_radial%5C_basisalpha)
  - [\_decision\_function\_sparse\_radial\_basis.b](#%5C_decision%5C_function%5C_sparse%5C_radial%5C_basisb)
  - [\_decision\_function\_sparse\_radial\_basis.basis\_vectors](#%5C_decision%5C_function%5C_sparse%5C_radial%5C_basisbasis%5C_vectors)
  - [dlib::\_decision\_function\_sparse\_radial\_basis::create](#dlib%5C_decision%5C_function%5C_sparse%5C_radial%5C_basiscreate)
  - [dlib::\_decision\_function\_sparse\_radial\_basis::get\_call](#dlib%5C_decision%5C_function%5C_sparse%5C_radial%5C_basisget%5C_call)
- [dlib::\_decision\_function\_sigmoid](#dlib%5C_decision%5C_function%5C_sigmoid)
  - [\_decision\_function\_sigmoid.alpha](#%5C_decision%5C_function%5C_sigmoidalpha)
  - [\_decision\_function\_sigmoid.b](#%5C_decision%5C_function%5C_sigmoidb)
  - [\_decision\_function\_sigmoid.basis\_vectors](#%5C_decision%5C_function%5C_sigmoidbasis%5C_vectors)
  - [dlib::\_decision\_function\_sigmoid::create](#dlib%5C_decision%5C_function%5C_sigmoidcreate)
  - [dlib::\_decision\_function\_sigmoid::get\_call](#dlib%5C_decision%5C_function%5C_sigmoidget%5C_call)
- [dlib::\_decision\_function\_sparse\_sigmoid](#dlib%5C_decision%5C_function%5C_sparse%5C_sigmoid)
  - [\_decision\_function\_sparse\_sigmoid.alpha](#%5C_decision%5C_function%5C_sparse%5C_sigmoidalpha)
  - [\_decision\_function\_sparse\_sigmoid.b](#%5C_decision%5C_function%5C_sparse%5C_sigmoidb)
  - [\_decision\_function\_sparse\_sigmoid.basis\_vectors](#%5C_decision%5C_function%5C_sparse%5C_sigmoidbasis%5C_vectors)
  - [dlib::\_decision\_function\_sparse\_sigmoid::create](#dlib%5C_decision%5C_function%5C_sparse%5C_sigmoidcreate)
  - [dlib::\_decision\_function\_sparse\_sigmoid::get\_call](#dlib%5C_decision%5C_function%5C_sparse%5C_sigmoidget%5C_call)
- [dlib::\_normalized\_decision\_function\_radial\_basis](#dlib%5C_normalized%5C_decision%5C_function%5C_radial%5C_basis)
  - [\_normalized\_decision\_function\_radial\_basis.alpha](#%5C_normalized%5C_decision%5C_function%5C_radial%5C_basisalpha)
  - [\_normalized\_decision\_function\_radial\_basis.b](#%5C_normalized%5C_decision%5C_function%5C_radial%5C_basisb)
  - [\_normalized\_decision\_function\_radial\_basis.basis\_vectors](#%5C_normalized%5C_decision%5C_function%5C_radial%5C_basisbasis%5C_vectors)
  - [\_normalized\_decision\_function\_radial\_basis.means](#%5C_normalized%5C_decision%5C_function%5C_radial%5C_basismeans)
  - [\_normalized\_decision\_function\_radial\_basis.invstd\_devs](#%5C_normalized%5C_decision%5C_function%5C_radial%5C_basisinvstd%5C_devs)
  - [dlib::\_normalized\_decision\_function\_radial\_basis::create](#dlib%5C_normalized%5C_decision%5C_function%5C_radial%5C_basiscreate)
  - [dlib::\_normalized\_decision\_function\_radial\_basis::batch\_predict](#dlib%5C_normalized%5C_decision%5C_function%5C_radial%5C_basisbatch%5C_predict)
  - [dlib::\_normalized\_decision\_function\_radial\_basis::get\_call](#dlib%5C_normalized%5C_decision%5C_function%5C_radial%5C_basisget%5C_call)
- [dlib::function\_evaluation](#dlibfunction%5C_evaluation)
  - [function\_evaluation.x](#function%5C_evaluationx)
  - [function\_evaluation.y](#function%5C_evaluationy)
  - [dlib::function\_evaluation::get\_create](#dlibfunction%5C_evaluationget%5C_create)
- [dlib::function\_spec](#dlibfunction%5C_spec)
  - [function\_spec.lower](#function%5C_speclower)
  - [function\_spec.upper](#function%5C_specupper)
  - [function\_spec.is\_integer\_variable](#function%5C_specis%5C_integer%5C_variable)
  - [dlib::function\_spec::get\_create](#dlibfunction%5C_specget%5C_create)
- [dlib::function\_evaluation\_request](#dlibfunction%5C_evaluation%5C_request)
  - [function\_evaluation\_request.function\_idx](#function%5C_evaluation%5C_requestfunction%5C_idx)
  - [function\_evaluation\_request.x](#function%5C_evaluation%5C_requestx)
  - [function\_evaluation\_request.has\_been\_evaluated](#function%5C_evaluation%5C_requesthas%5C_been%5C_evaluated)
  - [dlib::function\_evaluation\_request::set](#dlibfunction%5C_evaluation%5C_requestset)
- [dlib::global\_function\_search](#dlibglobal%5C_function%5C_search)
  - [dlib::global\_function\_search::get\_create](#dlibglobal%5C_function%5C_searchget%5C_create)
  - [dlib::global\_function\_search::get\_best\_function\_eval](#dlibglobal%5C_function%5C_searchget%5C_best%5C_function%5C_eval)
  - [dlib::global\_function\_search::get\_function\_evaluations](#dlibglobal%5C_function%5C_searchget%5C_function%5C_evaluations)
  - [dlib::global\_function\_search::get\_monte\_carlo\_upper\_bound\_sample\_num](#dlibglobal%5C_function%5C_searchget%5C_monte%5C_carlo%5C_upper%5C_bound%5C_sample%5C_num)
  - [dlib::global\_function\_search::get\_next\_x](#dlibglobal%5C_function%5C_searchget%5C_next%5C_x)
  - [dlib::global\_function\_search::get\_pure\_random\_search\_probability](#dlibglobal%5C_function%5C_searchget%5C_pure%5C_random%5C_search%5C_probability)
  - [dlib::global\_function\_search::get\_relative\_noise\_magnitude](#dlibglobal%5C_function%5C_searchget%5C_relative%5C_noise%5C_magnitude)
  - [dlib::global\_function\_search::get\_solver\_epsilon](#dlibglobal%5C_function%5C_searchget%5C_solver%5C_epsilon)
  - [dlib::global\_function\_search::num\_functions](#dlibglobal%5C_function%5C_searchnum%5C_functions)
  - [dlib::global\_function\_search::set\_monte\_carlo\_upper\_bound\_sample\_num](#dlibglobal%5C_function%5C_searchset%5C_monte%5C_carlo%5C_upper%5C_bound%5C_sample%5C_num)
  - [dlib::global\_function\_search::set\_pure\_random\_search\_probability](#dlibglobal%5C_function%5C_searchset%5C_pure%5C_random%5C_search%5C_probability)
  - [dlib::global\_function\_search::set\_relative\_noise\_magnitude](#dlibglobal%5C_function%5C_searchset%5C_relative%5C_noise%5C_magnitude)
  - [dlib::global\_function\_search::set\_seed](#dlibglobal%5C_function%5C_searchset%5C_seed)
  - [dlib::global\_function\_search::set\_solver\_epsilon](#dlibglobal%5C_function%5C_searchset%5C_solver%5C_epsilon)
- [dlib::image\_window](#dlibimage%5C_window)
  - [dlib::image\_window::get\_create](#dlibimage%5C_windowget%5C_create)
  - [dlib::image\_window::add\_overlay](#dlibimage%5C_windowadd%5C_overlay)
  - [dlib::image\_window::add\_overlay\_circle](#dlibimage%5C_windowadd%5C_overlay%5C_circle)
  - [dlib::image\_window::clear\_overlay](#dlibimage%5C_windowclear%5C_overlay)
  - [dlib::image\_window::get\_next\_double\_click](#dlibimage%5C_windowget%5C_next%5C_double%5C_click)
  - [dlib::image\_window::get\_next\_keypress](#dlibimage%5C_windowget%5C_next%5C_keypress)
  - [dlib::image\_window::is\_closed](#dlibimage%5C_windowis%5C_closed)
  - [dlib::image\_window::set\_image](#dlibimage%5C_windowset%5C_image)
  - [dlib::image\_window::set\_title](#dlibimage%5C_windowset%5C_title)
  - [dlib::image\_window::wait\_for\_keypress](#dlibimage%5C_windowwait%5C_for%5C_keypress)
  - [dlib::image\_window::wait\_until\_closed](#dlibimage%5C_windowwait%5C_until%5C_closed)
  - [image\_window.KBD\_MOD\_NONE\_](#image%5C_windowkbd%5C_mod%5C_none%5C_)
  - [image\_window.KBD\_MOD\_SHIFT\_](#image%5C_windowkbd%5C_mod%5C_shift%5C_)
  - [image\_window.KBD\_MOD\_CONTROL\_](#image%5C_windowkbd%5C_mod%5C_control%5C_)
  - [image\_window.KBD\_MOD\_ALT\_](#image%5C_windowkbd%5C_mod%5C_alt%5C_)
  - [image\_window.KBD\_MOD\_META\_](#image%5C_windowkbd%5C_mod%5C_meta%5C_)
  - [image\_window.KBD\_MOD\_CAPS\_LOCK\_](#image%5C_windowkbd%5C_mod%5C_caps%5C_lock%5C_)
  - [image\_window.KBD\_MOD\_NUM\_LOCK\_](#image%5C_windowkbd%5C_mod%5C_num%5C_lock%5C_)
  - [image\_window.KBD\_MOD\_SCROLL\_LOCK\_](#image%5C_windowkbd%5C_mod%5C_scroll%5C_lock%5C_)
  - [image\_window.KEY\_BACKSPACE\_](#image%5C_windowkey%5C_backspace%5C_)
  - [image\_window.KEY\_SHIFT\_](#image%5C_windowkey%5C_shift%5C_)
  - [image\_window.KEY\_CTRL\_](#image%5C_windowkey%5C_ctrl%5C_)
  - [image\_window.KEY\_ALT\_](#image%5C_windowkey%5C_alt%5C_)
  - [image\_window.KEY\_PAUSE\_](#image%5C_windowkey%5C_pause%5C_)
  - [image\_window.KEY\_CAPS\_LOCK\_](#image%5C_windowkey%5C_caps%5C_lock%5C_)
  - [image\_window.KEY\_ESC\_](#image%5C_windowkey%5C_esc%5C_)
  - [image\_window.KEY\_PAGE\_UP\_](#image%5C_windowkey%5C_page%5C_up%5C_)
  - [image\_window.KEY\_PAGE\_DOWN\_](#image%5C_windowkey%5C_page%5C_down%5C_)
  - [image\_window.KEY\_END\_](#image%5C_windowkey%5C_end%5C_)
  - [image\_window.KEY\_HOME\_](#image%5C_windowkey%5C_home%5C_)
  - [image\_window.KEY\_LEFT\_](#image%5C_windowkey%5C_left%5C_)
  - [image\_window.KEY\_RIGHT\_](#image%5C_windowkey%5C_right%5C_)
  - [image\_window.KEY\_UP\_](#image%5C_windowkey%5C_up%5C_)
  - [image\_window.KEY\_DOWN\_](#image%5C_windowkey%5C_down%5C_)
  - [image\_window.KEY\_INSERT\_](#image%5C_windowkey%5C_insert%5C_)
  - [image\_window.KEY\_DELETE\_](#image%5C_windowkey%5C_delete%5C_)
  - [image\_window.KEY\_SCROLL\_LOCK\_](#image%5C_windowkey%5C_scroll%5C_lock%5C_)
  - [image\_window.KEY\_F1\_](#image%5C_windowkey%5C_f1%5C_)
  - [image\_window.KEY\_F2\_](#image%5C_windowkey%5C_f2%5C_)
  - [image\_window.KEY\_F3\_](#image%5C_windowkey%5C_f3%5C_)
  - [image\_window.KEY\_F4\_](#image%5C_windowkey%5C_f4%5C_)
  - [image\_window.KEY\_F5\_](#image%5C_windowkey%5C_f5%5C_)
  - [image\_window.KEY\_F6\_](#image%5C_windowkey%5C_f6%5C_)
  - [image\_window.KEY\_F7\_](#image%5C_windowkey%5C_f7%5C_)
  - [image\_window.KEY\_F8\_](#image%5C_windowkey%5C_f8%5C_)
  - [image\_window.KEY\_F9\_](#image%5C_windowkey%5C_f9%5C_)
  - [image\_window.KEY\_F10\_](#image%5C_windowkey%5C_f10%5C_)
  - [image\_window.KEY\_F11\_](#image%5C_windowkey%5C_f11%5C_)
  - [image\_window.KEY\_F12\_](#image%5C_windowkey%5C_f12%5C_)
- [dlib::rgb\_pixel](#dlibrgb%5C_pixel)
  - [rgb\_pixel.red](#rgb%5C_pixelred)
  - [rgb\_pixel.blue](#rgb%5C_pixelblue)
  - [rgb\_pixel.green](#rgb%5C_pixelgreen)
  - [dlib::rgb\_pixel::get\_create](#dlibrgb%5C_pixelget%5C_create)
- [dlib::image\_dataset\_metadata](#dlibimage%5C_dataset%5C_metadata)
  - [image\_dataset\_metadata.box](#image%5C_dataset%5C_metadatabox)
  - [image\_dataset\_metadata.image](#image%5C_dataset%5C_metadataimage)
  - [image\_dataset\_metadata.dataset](#image%5C_dataset%5C_metadatadataset)
  - [dlib::image\_dataset\_metadata::load\_image\_dataset\_metadata](#dlibimage%5C_dataset%5C_metadataload%5C_image%5C_dataset%5C_metadata)
  - [dlib::image\_dataset\_metadata::make\_bounding\_box\_regression\_training\_data](#dlibimage%5C_dataset%5C_metadatamake%5C_bounding%5C_box%5C_regression%5C_training%5C_data)
  - [dlib::image\_dataset\_metadata::save\_image\_dataset\_metadata](#dlibimage%5C_dataset%5C_metadatasave%5C_image%5C_dataset%5C_metadata)
  - [image\_dataset\_metadata.UNKNOWN\_](#image%5C_dataset%5C_metadataunknown%5C_)
  - [image\_dataset\_metadata.MALE\_](#image%5C_dataset%5C_metadatamale%5C_)
  - [image\_dataset\_metadata.FEMALE\_](#image%5C_dataset%5C_metadatafemale%5C_)
- [dlib::image\_dataset\_metadata::box](#dlibimage%5C_dataset%5C_metadatabox)
  - [box.rect](#boxrect)
  - [box.parts](#boxparts)
  - [box.label](#boxlabel)
  - [box.difficult](#boxdifficult)
  - [box.truncated](#boxtruncated)
  - [box.occluded](#boxoccluded)
  - [box.ignore](#boxignore)
  - [box.pose](#boxpose)
  - [box.detection\_score](#boxdetection%5C_score)
  - [box.angle](#boxangle)
  - [box.gender](#boxgender)
  - [box.age](#boxage)
  - [dlib::image\_dataset\_metadata::box::get\_create](#dlibimage%5C_dataset%5C_metadataboxget%5C_create)
  - [dlib::image\_dataset\_metadata::box::has\_label](#dlibimage%5C_dataset%5C_metadataboxhas%5C_label)
- [dlib::image\_dataset\_metadata::image](#dlibimage%5C_dataset%5C_metadataimage)
  - [image.filename](#imagefilename)
  - [image.boxes](#imageboxes)
  - [dlib::image\_dataset\_metadata::image::get\_create](#dlibimage%5C_dataset%5C_metadataimageget%5C_create)
- [dlib::image\_dataset\_metadata::dataset](#dlibimage%5C_dataset%5C_metadatadataset)
  - [dataset.images](#datasetimages)
  - [dataset.comment](#datasetcomment)
  - [dataset.name](#datasetname)
  - [dlib::image\_dataset\_metadata::dataset::get\_create](#dlibimage%5C_dataset%5C_metadatadatasetget%5C_create)
- [dlib::line](#dlibline)
  - [line.normal](#linenormal)
  - [line.p1](#linep1)
  - [line.p2](#linep2)
  - [dlib::line::get\_create](#dliblineget%5C_create)
- [cv::Mat](#cvmat)
  - [Mat.cols](#matcols)
  - [Mat.data](#matdata)
  - [Mat.dims](#matdims)
  - [Mat.flags](#matflags)
  - [Mat.rows](#matrows)
  - [Mat.step](#matstep)
  - [Mat.width](#matwidth)
  - [Mat.height](#matheight)
  - [Mat.shape](#matshape)
  - [Mat.sizes](#matsizes)
  - [Mat.steps](#matsteps)
  - [cv::Mat::create](#cvmatcreate)
  - [cv::Mat::GdiplusResize](#cvmatgdiplusresize)
  - [cv::Mat::PixelChecksum](#cvmatpixelchecksum)
  - [cv::Mat::PixelSearch](#cvmatpixelsearch)
  - [cv::Mat::Point\_at](#cvmatpoint%5C_at)
  - [cv::Mat::Vec2b\_at](#cvmatvec2b%5C_at)
  - [cv::Mat::Vec2b\_set\_at](#cvmatvec2b%5C_set%5C_at)
  - [cv::Mat::Vec2d\_at](#cvmatvec2d%5C_at)
  - [cv::Mat::Vec2d\_set\_at](#cvmatvec2d%5C_set%5C_at)
  - [cv::Mat::Vec2f\_at](#cvmatvec2f%5C_at)
  - [cv::Mat::Vec2f\_set\_at](#cvmatvec2f%5C_set%5C_at)
  - [cv::Mat::Vec2i\_at](#cvmatvec2i%5C_at)
  - [cv::Mat::Vec2i\_set\_at](#cvmatvec2i%5C_set%5C_at)
  - [cv::Mat::Vec2s\_at](#cvmatvec2s%5C_at)
  - [cv::Mat::Vec2s\_set\_at](#cvmatvec2s%5C_set%5C_at)
  - [cv::Mat::Vec2w\_at](#cvmatvec2w%5C_at)
  - [cv::Mat::Vec2w\_set\_at](#cvmatvec2w%5C_set%5C_at)
  - [cv::Mat::Vec3b\_at](#cvmatvec3b%5C_at)
  - [cv::Mat::Vec3b\_set\_at](#cvmatvec3b%5C_set%5C_at)
  - [cv::Mat::Vec3d\_at](#cvmatvec3d%5C_at)
  - [cv::Mat::Vec3d\_set\_at](#cvmatvec3d%5C_set%5C_at)
  - [cv::Mat::Vec3f\_at](#cvmatvec3f%5C_at)
  - [cv::Mat::Vec3f\_set\_at](#cvmatvec3f%5C_set%5C_at)
  - [cv::Mat::Vec3i\_at](#cvmatvec3i%5C_at)
  - [cv::Mat::Vec3i\_set\_at](#cvmatvec3i%5C_set%5C_at)
  - [cv::Mat::Vec3s\_at](#cvmatvec3s%5C_at)
  - [cv::Mat::Vec3s\_set\_at](#cvmatvec3s%5C_set%5C_at)
  - [cv::Mat::Vec3w\_at](#cvmatvec3w%5C_at)
  - [cv::Mat::Vec3w\_set\_at](#cvmatvec3w%5C_set%5C_at)
  - [cv::Mat::Vec4b\_at](#cvmatvec4b%5C_at)
  - [cv::Mat::Vec4b\_set\_at](#cvmatvec4b%5C_set%5C_at)
  - [cv::Mat::Vec4d\_at](#cvmatvec4d%5C_at)
  - [cv::Mat::Vec4d\_set\_at](#cvmatvec4d%5C_set%5C_at)
  - [cv::Mat::Vec4f\_at](#cvmatvec4f%5C_at)
  - [cv::Mat::Vec4f\_set\_at](#cvmatvec4f%5C_set%5C_at)
  - [cv::Mat::Vec4i\_at](#cvmatvec4i%5C_at)
  - [cv::Mat::Vec4i\_set\_at](#cvmatvec4i%5C_set%5C_at)
  - [cv::Mat::Vec4s\_at](#cvmatvec4s%5C_at)
  - [cv::Mat::Vec4s\_set\_at](#cvmatvec4s%5C_set%5C_at)
  - [cv::Mat::Vec4w\_at](#cvmatvec4w%5C_at)
  - [cv::Mat::Vec4w\_set\_at](#cvmatvec4w%5C_set%5C_at)
  - [cv::Mat::Vec6d\_at](#cvmatvec6d%5C_at)
  - [cv::Mat::Vec6d\_set\_at](#cvmatvec6d%5C_set%5C_at)
  - [cv::Mat::Vec6f\_at](#cvmatvec6f%5C_at)
  - [cv::Mat::Vec6f\_set\_at](#cvmatvec6f%5C_set%5C_at)
  - [cv::Mat::Vec6i\_at](#cvmatvec6i%5C_at)
  - [cv::Mat::Vec6i\_set\_at](#cvmatvec6i%5C_set%5C_at)
  - [cv::Mat::Vec8i\_at](#cvmatvec8i%5C_at)
  - [cv::Mat::Vec8i\_set\_at](#cvmatvec8i%5C_set%5C_at)
  - [cv::Mat::adjustROI](#cvmatadjustroi)
  - [cv::Mat::asArray](#cvmatasarray)
  - [cv::Mat::assignTo](#cvmatassignto)
  - [cv::Mat::at](#cvmatat)
  - [cv::Mat::channels](#cvmatchannels)
  - [cv::Mat::checkVector](#cvmatcheckvector)
  - [cv::Mat::clone](#cvmatclone)
  - [cv::Mat::col](#cvmatcol)
  - [cv::Mat::colRange](#cvmatcolrange)
  - [cv::Mat::convertTo](#cvmatconvertto)
  - [cv::Mat::convertToBitmap](#cvmatconverttobitmap)
  - [cv::Mat::convertToShow](#cvmatconverttoshow)
  - [cv::Mat::copy](#cvmatcopy)
  - [cv::Mat::copySize](#cvmatcopysize)
  - [cv::Mat::copyTo](#cvmatcopyto)
  - [cv::Mat::createFromArray](#cvmatcreatefromarray)
  - [cv::Mat::createFromVec2b](#cvmatcreatefromvec2b)
  - [cv::Mat::createFromVec2d](#cvmatcreatefromvec2d)
  - [cv::Mat::createFromVec2f](#cvmatcreatefromvec2f)
  - [cv::Mat::createFromVec2i](#cvmatcreatefromvec2i)
  - [cv::Mat::createFromVec2s](#cvmatcreatefromvec2s)
  - [cv::Mat::createFromVec2w](#cvmatcreatefromvec2w)
  - [cv::Mat::createFromVec3b](#cvmatcreatefromvec3b)
  - [cv::Mat::createFromVec3d](#cvmatcreatefromvec3d)
  - [cv::Mat::createFromVec3f](#cvmatcreatefromvec3f)
  - [cv::Mat::createFromVec3i](#cvmatcreatefromvec3i)
  - [cv::Mat::createFromVec3s](#cvmatcreatefromvec3s)
  - [cv::Mat::createFromVec3w](#cvmatcreatefromvec3w)
  - [cv::Mat::createFromVec4b](#cvmatcreatefromvec4b)
  - [cv::Mat::createFromVec4d](#cvmatcreatefromvec4d)
  - [cv::Mat::createFromVec4f](#cvmatcreatefromvec4f)
  - [cv::Mat::createFromVec4i](#cvmatcreatefromvec4i)
  - [cv::Mat::createFromVec4s](#cvmatcreatefromvec4s)
  - [cv::Mat::createFromVec4w](#cvmatcreatefromvec4w)
  - [cv::Mat::createFromVec6d](#cvmatcreatefromvec6d)
  - [cv::Mat::createFromVec6f](#cvmatcreatefromvec6f)
  - [cv::Mat::createFromVec6i](#cvmatcreatefromvec6i)
  - [cv::Mat::createFromVec8i](#cvmatcreatefromvec8i)
  - [cv::Mat::createFromVectorOfDouble](#cvmatcreatefromvectorofdouble)
  - [cv::Mat::createFromVectorOfFloat](#cvmatcreatefromvectoroffloat)
  - [cv::Mat::createFromVectorOfInt](#cvmatcreatefromvectorofint)
  - [cv::Mat::createFromVectorOfMat](#cvmatcreatefromvectorofmat)
  - [cv::Mat::createFromVectorOfVec2b](#cvmatcreatefromvectorofvec2b)
  - [cv::Mat::createFromVectorOfVec2d](#cvmatcreatefromvectorofvec2d)
  - [cv::Mat::createFromVectorOfVec2f](#cvmatcreatefromvectorofvec2f)
  - [cv::Mat::createFromVectorOfVec2i](#cvmatcreatefromvectorofvec2i)
  - [cv::Mat::createFromVectorOfVec2s](#cvmatcreatefromvectorofvec2s)
  - [cv::Mat::createFromVectorOfVec2w](#cvmatcreatefromvectorofvec2w)
  - [cv::Mat::createFromVectorOfVec3b](#cvmatcreatefromvectorofvec3b)
  - [cv::Mat::createFromVectorOfVec3d](#cvmatcreatefromvectorofvec3d)
  - [cv::Mat::createFromVectorOfVec3f](#cvmatcreatefromvectorofvec3f)
  - [cv::Mat::createFromVectorOfVec3i](#cvmatcreatefromvectorofvec3i)
  - [cv::Mat::createFromVectorOfVec3s](#cvmatcreatefromvectorofvec3s)
  - [cv::Mat::createFromVectorOfVec3w](#cvmatcreatefromvectorofvec3w)
  - [cv::Mat::createFromVectorOfVec4b](#cvmatcreatefromvectorofvec4b)
  - [cv::Mat::createFromVectorOfVec4d](#cvmatcreatefromvectorofvec4d)
  - [cv::Mat::createFromVectorOfVec4f](#cvmatcreatefromvectorofvec4f)
  - [cv::Mat::createFromVectorOfVec4i](#cvmatcreatefromvectorofvec4i)
  - [cv::Mat::createFromVectorOfVec4s](#cvmatcreatefromvectorofvec4s)
  - [cv::Mat::createFromVectorOfVec4w](#cvmatcreatefromvectorofvec4w)
  - [cv::Mat::createFromVectorOfVec6d](#cvmatcreatefromvectorofvec6d)
  - [cv::Mat::createFromVectorOfVec6f](#cvmatcreatefromvectorofvec6f)
  - [cv::Mat::createFromVectorOfVec6i](#cvmatcreatefromvectorofvec6i)
  - [cv::Mat::createFromVectorOfVec8i](#cvmatcreatefromvectorofvec8i)
  - [cv::Mat::cross](#cvmatcross)
  - [cv::Mat::depth](#cvmatdepth)
  - [cv::Mat::diag](#cvmatdiag)
  - [cv::Mat::dot](#cvmatdot)
  - [cv::Mat::double\_at](#cvmatdouble%5C_at)
  - [cv::Mat::double\_set\_at](#cvmatdouble%5C_set%5C_at)
  - [cv::Mat::elemSize](#cvmatelemsize)
  - [cv::Mat::elemSize1](#cvmatelemsize1)
  - [cv::Mat::empty](#cvmatempty)
  - [cv::Mat::eye](#cvmateye)
  - [cv::Mat::float\_at](#cvmatfloat%5C_at)
  - [cv::Mat::float\_set\_at](#cvmatfloat%5C_set%5C_at)
  - [cv::Mat::getUMat](#cvmatgetumat)
  - [cv::Mat::get\_Item](#cvmatget%5C_item)
  - [cv::Mat::int\_at](#cvmatint%5C_at)
  - [cv::Mat::int\_set\_at](#cvmatint%5C_set%5C_at)
  - [cv::Mat::inv](#cvmatinv)
  - [cv::Mat::isContinuous](#cvmatiscontinuous)
  - [cv::Mat::isSubmatrix](#cvmatissubmatrix)
  - [cv::Mat::locateROI](#cvmatlocateroi)
  - [cv::Mat::makeInputArray](#cvmatmakeinputarray)
  - [cv::Mat::makeInputOutputArray](#cvmatmakeinputoutputarray)
  - [cv::Mat::makeOutputArray](#cvmatmakeoutputarray)
  - [cv::Mat::mul](#cvmatmul)
  - [cv::Mat::ones](#cvmatones)
  - [cv::Mat::pop\_back](#cvmatpop%5C_back)
  - [cv::Mat::ptr](#cvmatptr)
  - [cv::Mat::push\_back](#cvmatpush%5C_back)
  - [cv::Mat::put\_Item](#cvmatput%5C_item)
  - [cv::Mat::reserve](#cvmatreserve)
  - [cv::Mat::reserveBuffer](#cvmatreservebuffer)
  - [cv::Mat::reshape](#cvmatreshape)
  - [cv::Mat::resize](#cvmatresize)
  - [cv::Mat::row](#cvmatrow)
  - [cv::Mat::rowRange](#cvmatrowrange)
  - [cv::Mat::setTo](#cvmatsetto)
  - [cv::Mat::set\_at](#cvmatset%5C_at)
  - [cv::Mat::size](#cvmatsize)
  - [cv::Mat::step1](#cvmatstep1)
  - [cv::Mat::t](#cvmatt)
  - [cv::Mat::total](#cvmattotal)
  - [cv::Mat::type](#cvmattype)
  - [cv::Mat::updateContinuityFlag](#cvmatupdatecontinuityflag)
  - [cv::Mat::zeros](#cvmatzeros)
- [dlib::Matrix](#dlibmatrix)
  - [Matrix.shape](#matrixshape)
  - [dlib::Matrix::get\_create](#dlibmatrixget%5C_create)
  - [dlib::Matrix::ToString](#dlibmatrixtostring)
  - [dlib::Matrix::deserialize](#dlibmatrixdeserialize)
  - [dlib::Matrix::get](#dlibmatrixget)
  - [dlib::Matrix::nc](#dlibmatrixnc)
  - [dlib::Matrix::nr](#dlibmatrixnr)
  - [dlib::Matrix::serialize](#dlibmatrixserialize)
  - [dlib::Matrix::set\_size](#dlibmatrixset%5C_size)
- [std](#std)
  - [std.mutex](#stdmutex)
  - [std.timed\_mutex](#stdtimed%5C_mutex)
- [std::mutex](#stdmutex)
  - [std::mutex::get\_create](#stdmutexget%5C_create)
  - [std::mutex::lock](#stdmutexlock)
  - [std::mutex::try\_lock](#stdmutextry%5C_lock)
  - [std::mutex::unlock](#stdmutexunlock)
- [std::timed\_mutex](#stdtimed%5C_mutex)
  - [std::timed\_mutex::get\_create](#stdtimed%5C_mutexget%5C_create)
  - [std::timed\_mutex::lock](#stdtimed%5C_mutexlock)
  - [std::timed\_mutex::try\_lock](#stdtimed%5C_mutextry%5C_lock)
  - [std::timed\_mutex::try\_lock\_for](#stdtimed%5C_mutextry%5C_lock%5C_for)
  - [std::timed\_mutex::unlock](#stdtimed%5C_mutexunlock)
- [dlib::fhog\_object\_detector](#dlibfhog%5C_object%5C_detector)
  - [fhog\_object\_detector.detection\_window\_width](#fhog%5C_object%5C_detectordetection%5C_window%5C_width)
  - [fhog\_object\_detector.detection\_window\_height](#fhog%5C_object%5C_detectordetection%5C_window%5C_height)
  - [fhog\_object\_detector.num\_detectors](#fhog%5C_object%5C_detectornum%5C_detectors)
  - [dlib::fhog\_object\_detector::create](#dlibfhog%5C_object%5C_detectorcreate)
  - [dlib::fhog\_object\_detector::get\_call](#dlibfhog%5C_object%5C_detectorget%5C_call)
  - [dlib::fhog\_object\_detector::run](#dlibfhog%5C_object%5C_detectorrun)
  - [dlib::fhog\_object\_detector::run\_multiple](#dlibfhog%5C_object%5C_detectorrun%5C_multiple)
  - [dlib::fhog\_object\_detector::save](#dlibfhog%5C_object%5C_detectorsave)
- [cv::Range](#cvrange)
  - [Range.start](#rangestart)
  - [Range.end](#rangeend)
  - [cv::Range::get\_create](#cvrangeget%5C_create)
  - [cv::Range::all](#cvrangeall)
  - [cv::Range::empty](#cvrangeempty)
  - [cv::Range::size](#cvrangesize)
- [dlib::rect\_filter](#dlibrect%5C_filter)
  - [dlib::rect\_filter::create](#dlibrect%5C_filtercreate)
  - [dlib::rect\_filter::get\_call](#dlibrect%5C_filterget%5C_call)
  - [dlib::rect\_filter::max\_measurement\_deviation](#dlibrect%5C_filtermax%5C_measurement%5C_deviation)
  - [dlib::rect\_filter::measurement\_noise](#dlibrect%5C_filtermeasurement%5C_noise)
  - [dlib::rect\_filter::typical\_acceleration](#dlibrect%5C_filtertypical%5C_acceleration)
- [dlib::rectangle](#dlibrectangle)
  - [dlib::rectangle::get\_create](#dlibrectangleget%5C_create)
  - [dlib::rectangle::ToString](#dlibrectangletostring)
  - [dlib::rectangle::area](#dlibrectanglearea)
  - [dlib::rectangle::bl\_corner](#dlibrectanglebl%5C_corner)
  - [dlib::rectangle::bottom](#dlibrectanglebottom)
  - [dlib::rectangle::br\_corner](#dlibrectanglebr%5C_corner)
  - [dlib::rectangle::center](#dlibrectanglecenter)
  - [dlib::rectangle::contains](#dlibrectanglecontains)
  - [dlib::rectangle::dcenter](#dlibrectangledcenter)
  - [dlib::rectangle::height](#dlibrectangleheight)
  - [dlib::rectangle::intersect](#dlibrectangleintersect)
  - [dlib::rectangle::is\_empty](#dlibrectangleis%5C_empty)
  - [dlib::rectangle::left](#dlibrectangleleft)
  - [dlib::rectangle::right](#dlibrectangleright)
  - [dlib::rectangle::tl\_corner](#dlibrectangletl%5C_corner)
  - [dlib::rectangle::top](#dlibrectangletop)
  - [dlib::rectangle::tr\_corner](#dlibrectangletr%5C_corner)
  - [dlib::rectangle::width](#dlibrectanglewidth)
- [dlib::drectangle](#dlibdrectangle)
  - [dlib::drectangle::get\_create](#dlibdrectangleget%5C_create)
  - [dlib::drectangle::ToString](#dlibdrectangletostring)
  - [dlib::drectangle::area](#dlibdrectanglearea)
  - [dlib::drectangle::bl\_corner](#dlibdrectanglebl%5C_corner)
  - [dlib::drectangle::bottom](#dlibdrectanglebottom)
  - [dlib::drectangle::br\_corner](#dlibdrectanglebr%5C_corner)
  - [dlib::drectangle::center](#dlibdrectanglecenter)
  - [dlib::drectangle::contains](#dlibdrectanglecontains)
  - [dlib::drectangle::dcenter](#dlibdrectangledcenter)
  - [dlib::drectangle::height](#dlibdrectangleheight)
  - [dlib::drectangle::intersect](#dlibdrectangleintersect)
  - [dlib::drectangle::is\_empty](#dlibdrectangleis%5C_empty)
  - [dlib::drectangle::left](#dlibdrectangleleft)
  - [dlib::drectangle::right](#dlibdrectangleright)
  - [dlib::drectangle::tl\_corner](#dlibdrectangletl%5C_corner)
  - [dlib::drectangle::top](#dlibdrectangletop)
  - [dlib::drectangle::tr\_corner](#dlibdrectangletr%5C_corner)
  - [dlib::drectangle::width](#dlibdrectanglewidth)
- [dlib::full\_object\_detection](#dlibfull%5C_object%5C_detection)
  - [full\_object\_detection.rect](#full%5C_object%5C_detectionrect)
  - [full\_object\_detection.num\_parts](#full%5C_object%5C_detectionnum%5C_parts)
  - [dlib::full\_object\_detection::get\_create](#dlibfull%5C_object%5C_detectionget%5C_create)
  - [dlib::full\_object\_detection::part](#dlibfull%5C_object%5C_detectionpart)
  - [dlib::full\_object\_detection::parts](#dlibfull%5C_object%5C_detectionparts)
- [dlib::shape\_predictor](#dlibshape%5C_predictor)
  - [dlib::shape\_predictor::create](#dlibshape%5C_predictorcreate)
  - [dlib::shape\_predictor::get\_call](#dlibshape%5C_predictorget%5C_call)
  - [dlib::shape\_predictor::save](#dlibshape%5C_predictorsave)
- [dlib::svm\_c\_trainer\_radial\_basis](#dlibsvm%5C_c%5C_trainer%5C_radial%5C_basis)
  - [svm\_c\_trainer\_radial\_basis.epsilon](#svm%5C_c%5C_trainer%5C_radial%5C_basisepsilon)
  - [svm\_c\_trainer\_radial\_basis.c\_class1](#svm%5C_c%5C_trainer%5C_radial%5C_basisc%5C_class1)
  - [svm\_c\_trainer\_radial\_basis.c\_class2](#svm%5C_c%5C_trainer%5C_radial%5C_basisc%5C_class2)
  - [svm\_c\_trainer\_radial\_basis.cache\_size](#svm%5C_c%5C_trainer%5C_radial%5C_basiscache%5C_size)
  - [svm\_c\_trainer\_radial\_basis.gamma](#svm%5C_c%5C_trainer%5C_radial%5C_basisgamma)
  - [dlib::svm\_c\_trainer\_radial\_basis::get\_create](#dlibsvm%5C_c%5C_trainer%5C_radial%5C_basisget%5C_create)
  - [dlib::svm\_c\_trainer\_radial\_basis::set\_c](#dlibsvm%5C_c%5C_trainer%5C_radial%5C_basisset%5C_c)
  - [dlib::svm\_c\_trainer\_radial\_basis::train](#dlibsvm%5C_c%5C_trainer%5C_radial%5C_basistrain)
- [dlib::svm\_c\_trainer\_sparse\_radial\_basis](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basis)
  - [svm\_c\_trainer\_sparse\_radial\_basis.epsilon](#svm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basisepsilon)
  - [svm\_c\_trainer\_sparse\_radial\_basis.c\_class1](#svm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basisc%5C_class1)
  - [svm\_c\_trainer\_sparse\_radial\_basis.c\_class2](#svm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basisc%5C_class2)
  - [svm\_c\_trainer\_sparse\_radial\_basis.cache\_size](#svm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basiscache%5C_size)
  - [svm\_c\_trainer\_sparse\_radial\_basis.gamma](#svm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basisgamma)
  - [dlib::svm\_c\_trainer\_sparse\_radial\_basis::get\_create](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basisget%5C_create)
  - [dlib::svm\_c\_trainer\_sparse\_radial\_basis::set\_c](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basisset%5C_c)
  - [dlib::svm\_c\_trainer\_sparse\_radial\_basis::train](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_radial%5C_basistrain)
- [dlib::svm\_c\_trainer\_histogram\_intersection](#dlibsvm%5C_c%5C_trainer%5C_histogram%5C_intersection)
  - [svm\_c\_trainer\_histogram\_intersection.epsilon](#svm%5C_c%5C_trainer%5C_histogram%5C_intersectionepsilon)
  - [svm\_c\_trainer\_histogram\_intersection.c\_class1](#svm%5C_c%5C_trainer%5C_histogram%5C_intersectionc%5C_class1)
  - [svm\_c\_trainer\_histogram\_intersection.c\_class2](#svm%5C_c%5C_trainer%5C_histogram%5C_intersectionc%5C_class2)
  - [svm\_c\_trainer\_histogram\_intersection.cache\_size](#svm%5C_c%5C_trainer%5C_histogram%5C_intersectioncache%5C_size)
  - [dlib::svm\_c\_trainer\_histogram\_intersection::get\_create](#dlibsvm%5C_c%5C_trainer%5C_histogram%5C_intersectionget%5C_create)
  - [dlib::svm\_c\_trainer\_histogram\_intersection::set\_c](#dlibsvm%5C_c%5C_trainer%5C_histogram%5C_intersectionset%5C_c)
  - [dlib::svm\_c\_trainer\_histogram\_intersection::train](#dlibsvm%5C_c%5C_trainer%5C_histogram%5C_intersectiontrain)
- [dlib::svm\_c\_trainer\_sparse\_histogram\_intersection](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersection)
  - [svm\_c\_trainer\_sparse\_histogram\_intersection.epsilon](#svm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersectionepsilon)
  - [svm\_c\_trainer\_sparse\_histogram\_intersection.c\_class1](#svm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersectionc%5C_class1)
  - [svm\_c\_trainer\_sparse\_histogram\_intersection.c\_class2](#svm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersectionc%5C_class2)
  - [svm\_c\_trainer\_sparse\_histogram\_intersection.cache\_size](#svm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersectioncache%5C_size)
  - [dlib::svm\_c\_trainer\_sparse\_histogram\_intersection::get\_create](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersectionget%5C_create)
  - [dlib::svm\_c\_trainer\_sparse\_histogram\_intersection::set\_c](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersectionset%5C_c)
  - [dlib::svm\_c\_trainer\_sparse\_histogram\_intersection::train](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_histogram%5C_intersectiontrain)
- [dlib::svm\_c\_trainer\_linear](#dlibsvm%5C_c%5C_trainer%5C_linear)
  - [svm\_c\_trainer\_linear.epsilon](#svm%5C_c%5C_trainer%5C_linearepsilon)
  - [svm\_c\_trainer\_linear.c\_class1](#svm%5C_c%5C_trainer%5C_linearc%5C_class1)
  - [svm\_c\_trainer\_linear.c\_class2](#svm%5C_c%5C_trainer%5C_linearc%5C_class2)
  - [svm\_c\_trainer\_linear.max\_iterations](#svm%5C_c%5C_trainer%5C_linearmax%5C_iterations)
  - [svm\_c\_trainer\_linear.force\_last\_weight\_to\_1](#svm%5C_c%5C_trainer%5C_linearforce%5C_last%5C_weight%5C_to%5C_1)
  - [svm\_c\_trainer\_linear.learns\_nonnegative\_weights](#svm%5C_c%5C_trainer%5C_linearlearns%5C_nonnegative%5C_weights)
  - [svm\_c\_trainer\_linear.has\_prior](#svm%5C_c%5C_trainer%5C_linearhas%5C_prior)
  - [dlib::svm\_c\_trainer\_linear::get\_create](#dlibsvm%5C_c%5C_trainer%5C_linearget%5C_create)
  - [dlib::svm\_c\_trainer\_linear::be\_quiet](#dlibsvm%5C_c%5C_trainer%5C_linearbe%5C_quiet)
  - [dlib::svm\_c\_trainer\_linear::be\_verbose](#dlibsvm%5C_c%5C_trainer%5C_linearbe%5C_verbose)
  - [dlib::svm\_c\_trainer\_linear::set\_c](#dlibsvm%5C_c%5C_trainer%5C_linearset%5C_c)
  - [dlib::svm\_c\_trainer\_linear::set\_prior](#dlibsvm%5C_c%5C_trainer%5C_linearset%5C_prior)
  - [dlib::svm\_c\_trainer\_linear::train](#dlibsvm%5C_c%5C_trainer%5C_lineartrain)
- [dlib::svm\_c\_trainer\_sparse\_linear](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_linear)
  - [svm\_c\_trainer\_sparse\_linear.epsilon](#svm%5C_c%5C_trainer%5C_sparse%5C_linearepsilon)
  - [svm\_c\_trainer\_sparse\_linear.c\_class1](#svm%5C_c%5C_trainer%5C_sparse%5C_linearc%5C_class1)
  - [svm\_c\_trainer\_sparse\_linear.c\_class2](#svm%5C_c%5C_trainer%5C_sparse%5C_linearc%5C_class2)
  - [svm\_c\_trainer\_sparse\_linear.max\_iterations](#svm%5C_c%5C_trainer%5C_sparse%5C_linearmax%5C_iterations)
  - [svm\_c\_trainer\_sparse\_linear.force\_last\_weight\_to\_1](#svm%5C_c%5C_trainer%5C_sparse%5C_linearforce%5C_last%5C_weight%5C_to%5C_1)
  - [svm\_c\_trainer\_sparse\_linear.learns\_nonnegative\_weights](#svm%5C_c%5C_trainer%5C_sparse%5C_linearlearns%5C_nonnegative%5C_weights)
  - [svm\_c\_trainer\_sparse\_linear.has\_prior](#svm%5C_c%5C_trainer%5C_sparse%5C_linearhas%5C_prior)
  - [dlib::svm\_c\_trainer\_sparse\_linear::get\_create](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_linearget%5C_create)
  - [dlib::svm\_c\_trainer\_sparse\_linear::be\_quiet](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_linearbe%5C_quiet)
  - [dlib::svm\_c\_trainer\_sparse\_linear::be\_verbose](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_linearbe%5C_verbose)
  - [dlib::svm\_c\_trainer\_sparse\_linear::set\_c](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_linearset%5C_c)
  - [dlib::svm\_c\_trainer\_sparse\_linear::set\_prior](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_linearset%5C_prior)
  - [dlib::svm\_c\_trainer\_sparse\_linear::train](#dlibsvm%5C_c%5C_trainer%5C_sparse%5C_lineartrain)
- [dlib::rvm\_trainer\_radial\_basis](#dlibrvm%5C_trainer%5C_radial%5C_basis)
  - [rvm\_trainer\_radial\_basis.epsilon](#rvm%5C_trainer%5C_radial%5C_basisepsilon)
  - [rvm\_trainer\_radial\_basis.gamma](#rvm%5C_trainer%5C_radial%5C_basisgamma)
  - [dlib::rvm\_trainer\_radial\_basis::get\_create](#dlibrvm%5C_trainer%5C_radial%5C_basisget%5C_create)
  - [dlib::rvm\_trainer\_radial\_basis::train](#dlibrvm%5C_trainer%5C_radial%5C_basistrain)
- [dlib::rvm\_trainer\_sparse\_radial\_basis](#dlibrvm%5C_trainer%5C_sparse%5C_radial%5C_basis)
  - [rvm\_trainer\_sparse\_radial\_basis.epsilon](#rvm%5C_trainer%5C_sparse%5C_radial%5C_basisepsilon)
  - [rvm\_trainer\_sparse\_radial\_basis.gamma](#rvm%5C_trainer%5C_sparse%5C_radial%5C_basisgamma)
  - [dlib::rvm\_trainer\_sparse\_radial\_basis::get\_create](#dlibrvm%5C_trainer%5C_sparse%5C_radial%5C_basisget%5C_create)
  - [dlib::rvm\_trainer\_sparse\_radial\_basis::train](#dlibrvm%5C_trainer%5C_sparse%5C_radial%5C_basistrain)
- [dlib::rvm\_trainer\_histogram\_intersection](#dlibrvm%5C_trainer%5C_histogram%5C_intersection)
  - [rvm\_trainer\_histogram\_intersection.epsilon](#rvm%5C_trainer%5C_histogram%5C_intersectionepsilon)
  - [dlib::rvm\_trainer\_histogram\_intersection::get\_create](#dlibrvm%5C_trainer%5C_histogram%5C_intersectionget%5C_create)
  - [dlib::rvm\_trainer\_histogram\_intersection::train](#dlibrvm%5C_trainer%5C_histogram%5C_intersectiontrain)
- [dlib::rvm\_trainer\_sparse\_histogram\_intersection](#dlibrvm%5C_trainer%5C_sparse%5C_histogram%5C_intersection)
  - [rvm\_trainer\_sparse\_histogram\_intersection.epsilon](#rvm%5C_trainer%5C_sparse%5C_histogram%5C_intersectionepsilon)
  - [dlib::rvm\_trainer\_sparse\_histogram\_intersection::get\_create](#dlibrvm%5C_trainer%5C_sparse%5C_histogram%5C_intersectionget%5C_create)
  - [dlib::rvm\_trainer\_sparse\_histogram\_intersection::train](#dlibrvm%5C_trainer%5C_sparse%5C_histogram%5C_intersectiontrain)
- [dlib::rvm\_trainer\_linear](#dlibrvm%5C_trainer%5C_linear)
  - [rvm\_trainer\_linear.epsilon](#rvm%5C_trainer%5C_linearepsilon)
  - [dlib::rvm\_trainer\_linear::get\_create](#dlibrvm%5C_trainer%5C_linearget%5C_create)
  - [dlib::rvm\_trainer\_linear::train](#dlibrvm%5C_trainer%5C_lineartrain)
- [dlib::rvm\_trainer\_sparse\_linear](#dlibrvm%5C_trainer%5C_sparse%5C_linear)
  - [rvm\_trainer\_sparse\_linear.epsilon](#rvm%5C_trainer%5C_sparse%5C_linearepsilon)
  - [dlib::rvm\_trainer\_sparse\_linear::get\_create](#dlibrvm%5C_trainer%5C_sparse%5C_linearget%5C_create)
  - [dlib::rvm\_trainer\_sparse\_linear::train](#dlibrvm%5C_trainer%5C_sparse%5C_lineartrain)
- [dlib::vec\_ranking\_pair](#dlibvec%5C_ranking%5C_pair)
  - [vec\_ranking\_pair.relevant](#vec%5C_ranking%5C_pairrelevant)
  - [vec\_ranking\_pair.nonrelevant](#vec%5C_ranking%5C_pairnonrelevant)
  - [dlib::vec\_ranking\_pair::get\_create](#dlibvec%5C_ranking%5C_pairget%5C_create)
- [dlib::sparse\_ranking\_pair](#dlibsparse%5C_ranking%5C_pair)
  - [sparse\_ranking\_pair.relevant](#sparse%5C_ranking%5C_pairrelevant)
  - [sparse\_ranking\_pair.nonrelevant](#sparse%5C_ranking%5C_pairnonrelevant)
  - [dlib::sparse\_ranking\_pair::get\_create](#dlibsparse%5C_ranking%5C_pairget%5C_create)
- [dlib::vec\_svm\_rank\_trainer](#dlibvec%5C_svm%5C_rank%5C_trainer)
  - [vec\_svm\_rank\_trainer.epsilon](#vec%5C_svm%5C_rank%5C_trainerepsilon)
  - [vec\_svm\_rank\_trainer.c](#vec%5C_svm%5C_rank%5C_trainerc)
  - [vec\_svm\_rank\_trainer.max\_iterations](#vec%5C_svm%5C_rank%5C_trainermax%5C_iterations)
  - [vec\_svm\_rank\_trainer.force\_last\_weight\_to\_1](#vec%5C_svm%5C_rank%5C_trainerforce%5C_last%5C_weight%5C_to%5C_1)
  - [vec\_svm\_rank\_trainer.learns\_nonnegative\_weights](#vec%5C_svm%5C_rank%5C_trainerlearns%5C_nonnegative%5C_weights)
  - [vec\_svm\_rank\_trainer.has\_prior](#vec%5C_svm%5C_rank%5C_trainerhas%5C_prior)
  - [dlib::vec\_svm\_rank\_trainer::get\_create](#dlibvec%5C_svm%5C_rank%5C_trainerget%5C_create)
  - [dlib::vec\_svm\_rank\_trainer::be\_quiet](#dlibvec%5C_svm%5C_rank%5C_trainerbe%5C_quiet)
  - [dlib::vec\_svm\_rank\_trainer::be\_verbose](#dlibvec%5C_svm%5C_rank%5C_trainerbe%5C_verbose)
  - [dlib::vec\_svm\_rank\_trainer::set\_prior](#dlibvec%5C_svm%5C_rank%5C_trainerset%5C_prior)
  - [dlib::vec\_svm\_rank\_trainer::train](#dlibvec%5C_svm%5C_rank%5C_trainertrain)
- [dlib::svm\_rank\_trainer\_sparse](#dlibsvm%5C_rank%5C_trainer%5C_sparse)
  - [svm\_rank\_trainer\_sparse.epsilon](#svm%5C_rank%5C_trainer%5C_sparseepsilon)
  - [svm\_rank\_trainer\_sparse.c](#svm%5C_rank%5C_trainer%5C_sparsec)
  - [svm\_rank\_trainer\_sparse.max\_iterations](#svm%5C_rank%5C_trainer%5C_sparsemax%5C_iterations)
  - [svm\_rank\_trainer\_sparse.force\_last\_weight\_to\_1](#svm%5C_rank%5C_trainer%5C_sparseforce%5C_last%5C_weight%5C_to%5C_1)
  - [svm\_rank\_trainer\_sparse.learns\_nonnegative\_weights](#svm%5C_rank%5C_trainer%5C_sparselearns%5C_nonnegative%5C_weights)
  - [svm\_rank\_trainer\_sparse.has\_prior](#svm%5C_rank%5C_trainer%5C_sparsehas%5C_prior)
  - [dlib::svm\_rank\_trainer\_sparse::get\_create](#dlibsvm%5C_rank%5C_trainer%5C_sparseget%5C_create)
  - [dlib::svm\_rank\_trainer\_sparse::be\_quiet](#dlibsvm%5C_rank%5C_trainer%5C_sparsebe%5C_quiet)
  - [dlib::svm\_rank\_trainer\_sparse::be\_verbose](#dlibsvm%5C_rank%5C_trainer%5C_sparsebe%5C_verbose)
  - [dlib::svm\_rank\_trainer\_sparse::set\_prior](#dlibsvm%5C_rank%5C_trainer%5C_sparseset%5C_prior)
  - [dlib::svm\_rank\_trainer\_sparse::train](#dlibsvm%5C_rank%5C_trainer%5C_sparsetrain)
- [cv::UMat](#cvumat)
  - [UMat.cols](#umatcols)
  - [UMat.dims](#umatdims)
  - [UMat.flags](#umatflags)
  - [UMat.rows](#umatrows)
  - [UMat.step](#umatstep)
  - [UMat.width](#umatwidth)
  - [UMat.height](#umatheight)
  - [UMat.shape](#umatshape)
  - [UMat.sizes](#umatsizes)
  - [UMat.steps](#umatsteps)
  - [cv::UMat::get\_create](#cvumatget%5C_create)
  - [cv::UMat::GdiplusResize](#cvumatgdiplusresize)
  - [cv::UMat::adjustROI](#cvumatadjustroi)
  - [cv::UMat::assignTo](#cvumatassignto)
  - [cv::UMat::channels](#cvumatchannels)
  - [cv::UMat::checkVector](#cvumatcheckvector)
  - [cv::UMat::clone](#cvumatclone)
  - [cv::UMat::col](#cvumatcol)
  - [cv::UMat::colRange](#cvumatcolrange)
  - [cv::UMat::convertTo](#cvumatconvertto)
  - [cv::UMat::convertToBitmap](#cvumatconverttobitmap)
  - [cv::UMat::convertToShow](#cvumatconverttoshow)
  - [cv::UMat::copy](#cvumatcopy)
  - [cv::UMat::copySize](#cvumatcopysize)
  - [cv::UMat::copyTo](#cvumatcopyto)
  - [cv::UMat::depth](#cvumatdepth)
  - [cv::UMat::diag](#cvumatdiag)
  - [cv::UMat::dot](#cvumatdot)
  - [cv::UMat::elemSize](#cvumatelemsize)
  - [cv::UMat::elemSize1](#cvumatelemsize1)
  - [cv::UMat::empty](#cvumatempty)
  - [cv::UMat::eye](#cvumateye)
  - [cv::UMat::getMat](#cvumatgetmat)
  - [cv::UMat::handle](#cvumathandle)
  - [cv::UMat::isContinuous](#cvumatiscontinuous)
  - [cv::UMat::isSubmatrix](#cvumatissubmatrix)
  - [cv::UMat::locateROI](#cvumatlocateroi)
  - [cv::UMat::makeeInputArray](#cvumatmakeeinputarray)
  - [cv::UMat::makeeInputOutputArray](#cvumatmakeeinputoutputarray)
  - [cv::UMat::makeeOutputArray](#cvumatmakeeoutputarray)
  - [cv::UMat::mul](#cvumatmul)
  - [cv::UMat::ndoffset](#cvumatndoffset)
  - [cv::UMat::ones](#cvumatones)
  - [cv::UMat::reshape](#cvumatreshape)
  - [cv::UMat::row](#cvumatrow)
  - [cv::UMat::rowRange](#cvumatrowrange)
  - [cv::UMat::setTo](#cvumatsetto)
  - [cv::UMat::size](#cvumatsize)
  - [cv::UMat::step1](#cvumatstep1)
  - [cv::UMat::t](#cvumatt)
  - [cv::UMat::total](#cvumattotal)
  - [cv::UMat::type](#cvumattype)
  - [cv::UMat::updateContinuityFlag](#cvumatupdatecontinuityflag)
  - [cv::UMat::zeros](#cvumatzeros)
- [dlib::SpaceVector](#dlibspacevector)
  - [SpaceVector.shape](#spacevectorshape)
  - [dlib::SpaceVector::create](#dlibspacevectorcreate)
  - [dlib::SpaceVector::ToString](#dlibspacevectortostring)
  - [dlib::SpaceVector::get](#dlibspacevectorget)
  - [dlib::SpaceVector::get\_Item](#dlibspacevectorget%5C_item)
  - [dlib::SpaceVector::put\_Item](#dlibspacevectorput%5C_item)
  - [dlib::SpaceVector::resize](#dlibspacevectorresize)
  - [dlib::SpaceVector::set](#dlibspacevectorset)
  - [dlib::SpaceVector::set\_size](#dlibspacevectorset%5C_size)
  - [dlib::SpaceVector::size](#dlibspacevectorsize)
  - [dlib::SpaceVector::slice](#dlibspacevectorslice)
- [dlib::point\_transform\_projective](#dlibpoint%5C_transform%5C_projective)
  - [point\_transform\_projective.m](#point%5C_transform%5C_projectivem)
  - [dlib::point\_transform\_projective::get\_create](#dlibpoint%5C_transform%5C_projectiveget%5C_create)
- [dlib::dpoint](#dlibdpoint)
  - [dpoint.x](#dpointx)
  - [dpoint.y](#dpointy)
  - [dlib::dpoint::get\_create](#dlibdpointget%5C_create)
  - [dlib::dpoint::ToString](#dlibdpointtostring)
  - [dlib::dpoint::add](#dlibdpointadd)
  - [dlib::dpoint::divide](#dlibdpointdivide)
  - [dlib::dpoint::multiply](#dlibdpointmultiply)
  - [dlib::dpoint::normalize](#dlibdpointnormalize)
  - [dlib::dpoint::sub](#dlibdpointsub)
- [dlib::point](#dlibpoint)
  - [point.x](#pointx)
  - [point.y](#pointy)
  - [dlib::point::get\_create](#dlibpointget%5C_create)
  - [dlib::point::ToString](#dlibpointtostring)
  - [dlib::point::add](#dlibpointadd)
  - [dlib::point::divide](#dlibpointdivide)
  - [dlib::point::multiply](#dlibpointmultiply)
  - [dlib::point::normalize](#dlibpointnormalize)
  - [dlib::point::sub](#dlibpointsub)
- [VectorOfString](#vectorofstring)
  - [VectorOfString.Count](#vectorofstringcount)
  - [VectorOfString::create](#vectorofstringcreate)
  - [VectorOfString::Add](#vectorofstringadd)
  - [VectorOfString::Items](#vectorofstringitems)
  - [VectorOfString::Keys](#vectorofstringkeys)
  - [VectorOfString::Remove](#vectorofstringremove)
  - [VectorOfString::append](#vectorofstringappend)
  - [VectorOfString::at](#vectorofstringat)
  - [VectorOfString::clear](#vectorofstringclear)
  - [VectorOfString::empty](#vectorofstringempty)
  - [VectorOfString::end](#vectorofstringend)
  - [VectorOfString::get\_Item](#vectorofstringget%5C_item)
  - [VectorOfString::get\_\_NewEnum](#vectorofstringget%5C_%5C_newenum)
  - [VectorOfString::push\_back](#vectorofstringpush%5C_back)
  - [VectorOfString::push\_vector](#vectorofstringpush%5C_vector)
  - [VectorOfString::put\_Item](#vectorofstringput%5C_item)
  - [VectorOfString::size](#vectorofstringsize)
  - [VectorOfString::slice](#vectorofstringslice)
  - [VectorOfString::sort](#vectorofstringsort)
  - [VectorOfString::sort\_variant](#vectorofstringsort%5C_variant)
  - [VectorOfString::start](#vectorofstringstart)
- [VectorOfVariant](#vectorofvariant)
  - [VectorOfVariant.Count](#vectorofvariantcount)
  - [VectorOfVariant::create](#vectorofvariantcreate)
  - [VectorOfVariant::Add](#vectorofvariantadd)
  - [VectorOfVariant::Items](#vectorofvariantitems)
  - [VectorOfVariant::Keys](#vectorofvariantkeys)
  - [VectorOfVariant::Remove](#vectorofvariantremove)
  - [VectorOfVariant::append](#vectorofvariantappend)
  - [VectorOfVariant::at](#vectorofvariantat)
  - [VectorOfVariant::clear](#vectorofvariantclear)
  - [VectorOfVariant::empty](#vectorofvariantempty)
  - [VectorOfVariant::end](#vectorofvariantend)
  - [VectorOfVariant::get\_Item](#vectorofvariantget%5C_item)
  - [VectorOfVariant::get\_\_NewEnum](#vectorofvariantget%5C_%5C_newenum)
  - [VectorOfVariant::push\_back](#vectorofvariantpush%5C_back)
  - [VectorOfVariant::push\_vector](#vectorofvariantpush%5C_vector)
  - [VectorOfVariant::put\_Item](#vectorofvariantput%5C_item)
  - [VectorOfVariant::size](#vectorofvariantsize)
  - [VectorOfVariant::slice](#vectorofvariantslice)
  - [VectorOfVariant::sort](#vectorofvariantsort)
  - [VectorOfVariant::sort\_variant](#vectorofvariantsort%5C_variant)
  - [VectorOfVariant::start](#vectorofvariantstart)
- [VectorOfPairOfULONGAndDouble](#vectorofpairofulonganddouble)
  - [VectorOfPairOfULONGAndDouble.Count](#vectorofpairofulonganddoublecount)
  - [VectorOfPairOfULONGAndDouble::create](#vectorofpairofulonganddoublecreate)
  - [VectorOfPairOfULONGAndDouble::Add](#vectorofpairofulonganddoubleadd)
  - [VectorOfPairOfULONGAndDouble::Items](#vectorofpairofulonganddoubleitems)
  - [VectorOfPairOfULONGAndDouble::Keys](#vectorofpairofulonganddoublekeys)
  - [VectorOfPairOfULONGAndDouble::Remove](#vectorofpairofulonganddoubleremove)
  - [VectorOfPairOfULONGAndDouble::append](#vectorofpairofulonganddoubleappend)
  - [VectorOfPairOfULONGAndDouble::at](#vectorofpairofulonganddoubleat)
  - [VectorOfPairOfULONGAndDouble::clear](#vectorofpairofulonganddoubleclear)
  - [VectorOfPairOfULONGAndDouble::empty](#vectorofpairofulonganddoubleempty)
  - [VectorOfPairOfULONGAndDouble::end](#vectorofpairofulonganddoubleend)
  - [VectorOfPairOfULONGAndDouble::get\_Item](#vectorofpairofulonganddoubleget%5C_item)
  - [VectorOfPairOfULONGAndDouble::get\_\_NewEnum](#vectorofpairofulonganddoubleget%5C_%5C_newenum)
  - [VectorOfPairOfULONGAndDouble::push\_back](#vectorofpairofulonganddoublepush%5C_back)
  - [VectorOfPairOfULONGAndDouble::push\_vector](#vectorofpairofulonganddoublepush%5C_vector)
  - [VectorOfPairOfULONGAndDouble::put\_Item](#vectorofpairofulonganddoubleput%5C_item)
  - [VectorOfPairOfULONGAndDouble::size](#vectorofpairofulonganddoublesize)
  - [VectorOfPairOfULONGAndDouble::slice](#vectorofpairofulonganddoubleslice)
  - [VectorOfPairOfULONGAndDouble::sort](#vectorofpairofulonganddoublesort)
  - [VectorOfPairOfULONGAndDouble::sort\_variant](#vectorofpairofulonganddoublesort%5C_variant)
  - [VectorOfPairOfULONGAndDouble::start](#vectorofpairofulonganddoublestart)
- [VectorOfVectorOfPairOfULONGAndDouble](#vectorofvectorofpairofulonganddouble)
  - [VectorOfVectorOfPairOfULONGAndDouble.Count](#vectorofvectorofpairofulonganddoublecount)
  - [VectorOfVectorOfPairOfULONGAndDouble::create](#vectorofvectorofpairofulonganddoublecreate)
  - [VectorOfVectorOfPairOfULONGAndDouble::Add](#vectorofvectorofpairofulonganddoubleadd)
  - [VectorOfVectorOfPairOfULONGAndDouble::Items](#vectorofvectorofpairofulonganddoubleitems)
  - [VectorOfVectorOfPairOfULONGAndDouble::Keys](#vectorofvectorofpairofulonganddoublekeys)
  - [VectorOfVectorOfPairOfULONGAndDouble::Remove](#vectorofvectorofpairofulonganddoubleremove)
  - [VectorOfVectorOfPairOfULONGAndDouble::append](#vectorofvectorofpairofulonganddoubleappend)
  - [VectorOfVectorOfPairOfULONGAndDouble::at](#vectorofvectorofpairofulonganddoubleat)
  - [VectorOfVectorOfPairOfULONGAndDouble::clear](#vectorofvectorofpairofulonganddoubleclear)
  - [VectorOfVectorOfPairOfULONGAndDouble::empty](#vectorofvectorofpairofulonganddoubleempty)
  - [VectorOfVectorOfPairOfULONGAndDouble::end](#vectorofvectorofpairofulonganddoubleend)
  - [VectorOfVectorOfPairOfULONGAndDouble::get\_Item](#vectorofvectorofpairofulonganddoubleget%5C_item)
  - [VectorOfVectorOfPairOfULONGAndDouble::get\_\_NewEnum](#vectorofvectorofpairofulonganddoubleget%5C_%5C_newenum)
  - [VectorOfVectorOfPairOfULONGAndDouble::push\_back](#vectorofvectorofpairofulonganddoublepush%5C_back)
  - [VectorOfVectorOfPairOfULONGAndDouble::push\_vector](#vectorofvectorofpairofulonganddoublepush%5C_vector)
  - [VectorOfVectorOfPairOfULONGAndDouble::put\_Item](#vectorofvectorofpairofulonganddoubleput%5C_item)
  - [VectorOfVectorOfPairOfULONGAndDouble::size](#vectorofvectorofpairofulonganddoublesize)
  - [VectorOfVectorOfPairOfULONGAndDouble::slice](#vectorofvectorofpairofulonganddoubleslice)
  - [VectorOfVectorOfPairOfULONGAndDouble::sort](#vectorofvectorofpairofulonganddoublesort)
  - [VectorOfVectorOfPairOfULONGAndDouble::sort\_variant](#vectorofvectorofpairofulonganddoublesort%5C_variant)
  - [VectorOfVectorOfPairOfULONGAndDouble::start](#vectorofvectorofpairofulonganddoublestart)
- [VectorOfMat](#vectorofmat)
  - [VectorOfMat.Count](#vectorofmatcount)
  - [VectorOfMat::create](#vectorofmatcreate)
  - [VectorOfMat::Add](#vectorofmatadd)
  - [VectorOfMat::Items](#vectorofmatitems)
  - [VectorOfMat::Keys](#vectorofmatkeys)
  - [VectorOfMat::Remove](#vectorofmatremove)
  - [VectorOfMat::append](#vectorofmatappend)
  - [VectorOfMat::at](#vectorofmatat)
  - [VectorOfMat::clear](#vectorofmatclear)
  - [VectorOfMat::empty](#vectorofmatempty)
  - [VectorOfMat::end](#vectorofmatend)
  - [VectorOfMat::get\_Item](#vectorofmatget%5C_item)
  - [VectorOfMat::get\_\_NewEnum](#vectorofmatget%5C_%5C_newenum)
  - [VectorOfMat::push\_back](#vectorofmatpush%5C_back)
  - [VectorOfMat::push\_vector](#vectorofmatpush%5C_vector)
  - [VectorOfMat::put\_Item](#vectorofmatput%5C_item)
  - [VectorOfMat::size](#vectorofmatsize)
  - [VectorOfMat::slice](#vectorofmatslice)
  - [VectorOfMat::sort](#vectorofmatsort)
  - [VectorOfMat::sort\_variant](#vectorofmatsort%5C_variant)
  - [VectorOfMat::start](#vectorofmatstart)
- [VectorOfFull\_object\_detection](#vectoroffull%5C_object%5C_detection)
  - [VectorOfFull\_object\_detection.Count](#vectoroffull%5C_object%5C_detectioncount)
  - [VectorOfFull\_object\_detection::create](#vectoroffull%5C_object%5C_detectioncreate)
  - [VectorOfFull\_object\_detection::Add](#vectoroffull%5C_object%5C_detectionadd)
  - [VectorOfFull\_object\_detection::Items](#vectoroffull%5C_object%5C_detectionitems)
  - [VectorOfFull\_object\_detection::Keys](#vectoroffull%5C_object%5C_detectionkeys)
  - [VectorOfFull\_object\_detection::Remove](#vectoroffull%5C_object%5C_detectionremove)
  - [VectorOfFull\_object\_detection::append](#vectoroffull%5C_object%5C_detectionappend)
  - [VectorOfFull\_object\_detection::at](#vectoroffull%5C_object%5C_detectionat)
  - [VectorOfFull\_object\_detection::clear](#vectoroffull%5C_object%5C_detectionclear)
  - [VectorOfFull\_object\_detection::empty](#vectoroffull%5C_object%5C_detectionempty)
  - [VectorOfFull\_object\_detection::end](#vectoroffull%5C_object%5C_detectionend)
  - [VectorOfFull\_object\_detection::get\_Item](#vectoroffull%5C_object%5C_detectionget%5C_item)
  - [VectorOfFull\_object\_detection::get\_\_NewEnum](#vectoroffull%5C_object%5C_detectionget%5C_%5C_newenum)
  - [VectorOfFull\_object\_detection::push\_back](#vectoroffull%5C_object%5C_detectionpush%5C_back)
  - [VectorOfFull\_object\_detection::push\_vector](#vectoroffull%5C_object%5C_detectionpush%5C_vector)
  - [VectorOfFull\_object\_detection::put\_Item](#vectoroffull%5C_object%5C_detectionput%5C_item)
  - [VectorOfFull\_object\_detection::size](#vectoroffull%5C_object%5C_detectionsize)
  - [VectorOfFull\_object\_detection::slice](#vectoroffull%5C_object%5C_detectionslice)
  - [VectorOfFull\_object\_detection::sort](#vectoroffull%5C_object%5C_detectionsort)
  - [VectorOfFull\_object\_detection::sort\_variant](#vectoroffull%5C_object%5C_detectionsort%5C_variant)
  - [VectorOfFull\_object\_detection::start](#vectoroffull%5C_object%5C_detectionstart)
- [VectorOfULONG](#vectorofulong)
  - [VectorOfULONG.Count](#vectorofulongcount)
  - [VectorOfULONG::create](#vectorofulongcreate)
  - [VectorOfULONG::Add](#vectorofulongadd)
  - [VectorOfULONG::Items](#vectorofulongitems)
  - [VectorOfULONG::Keys](#vectorofulongkeys)
  - [VectorOfULONG::Remove](#vectorofulongremove)
  - [VectorOfULONG::append](#vectorofulongappend)
  - [VectorOfULONG::at](#vectorofulongat)
  - [VectorOfULONG::clear](#vectorofulongclear)
  - [VectorOfULONG::empty](#vectorofulongempty)
  - [VectorOfULONG::end](#vectorofulongend)
  - [VectorOfULONG::get\_Item](#vectorofulongget%5C_item)
  - [VectorOfULONG::get\_\_NewEnum](#vectorofulongget%5C_%5C_newenum)
  - [VectorOfULONG::push\_back](#vectorofulongpush%5C_back)
  - [VectorOfULONG::push\_vector](#vectorofulongpush%5C_vector)
  - [VectorOfULONG::put\_Item](#vectorofulongput%5C_item)
  - [VectorOfULONG::size](#vectorofulongsize)
  - [VectorOfULONG::slice](#vectorofulongslice)
  - [VectorOfULONG::sort](#vectorofulongsort)
  - [VectorOfULONG::sort\_variant](#vectorofulongsort%5C_variant)
  - [VectorOfULONG::start](#vectorofulongstart)
- [VectorOfSpaceVector](#vectorofspacevector)
  - [VectorOfSpaceVector.Count](#vectorofspacevectorcount)
  - [VectorOfSpaceVector::create](#vectorofspacevectorcreate)
  - [VectorOfSpaceVector::Add](#vectorofspacevectoradd)
  - [VectorOfSpaceVector::Items](#vectorofspacevectoritems)
  - [VectorOfSpaceVector::Keys](#vectorofspacevectorkeys)
  - [VectorOfSpaceVector::Remove](#vectorofspacevectorremove)
  - [VectorOfSpaceVector::append](#vectorofspacevectorappend)
  - [VectorOfSpaceVector::at](#vectorofspacevectorat)
  - [VectorOfSpaceVector::clear](#vectorofspacevectorclear)
  - [VectorOfSpaceVector::empty](#vectorofspacevectorempty)
  - [VectorOfSpaceVector::end](#vectorofspacevectorend)
  - [VectorOfSpaceVector::get\_Item](#vectorofspacevectorget%5C_item)
  - [VectorOfSpaceVector::get\_\_NewEnum](#vectorofspacevectorget%5C_%5C_newenum)
  - [VectorOfSpaceVector::push\_back](#vectorofspacevectorpush%5C_back)
  - [VectorOfSpaceVector::push\_vector](#vectorofspacevectorpush%5C_vector)
  - [VectorOfSpaceVector::put\_Item](#vectorofspacevectorput%5C_item)
  - [VectorOfSpaceVector::size](#vectorofspacevectorsize)
  - [VectorOfSpaceVector::slice](#vectorofspacevectorslice)
  - [VectorOfSpaceVector::sort](#vectorofspacevectorsort)
  - [VectorOfSpaceVector::sort\_variant](#vectorofspacevectorsort%5C_variant)
  - [VectorOfSpaceVector::start](#vectorofspacevectorstart)
- [VectorOfDouble](#vectorofdouble)
  - [VectorOfDouble.Count](#vectorofdoublecount)
  - [VectorOfDouble::create](#vectorofdoublecreate)
  - [VectorOfDouble::Add](#vectorofdoubleadd)
  - [VectorOfDouble::Items](#vectorofdoubleitems)
  - [VectorOfDouble::Keys](#vectorofdoublekeys)
  - [VectorOfDouble::Remove](#vectorofdoubleremove)
  - [VectorOfDouble::append](#vectorofdoubleappend)
  - [VectorOfDouble::at](#vectorofdoubleat)
  - [VectorOfDouble::clear](#vectorofdoubleclear)
  - [VectorOfDouble::empty](#vectorofdoubleempty)
  - [VectorOfDouble::end](#vectorofdoubleend)
  - [VectorOfDouble::get\_Item](#vectorofdoubleget%5C_item)
  - [VectorOfDouble::get\_\_NewEnum](#vectorofdoubleget%5C_%5C_newenum)
  - [VectorOfDouble::push\_back](#vectorofdoublepush%5C_back)
  - [VectorOfDouble::push\_vector](#vectorofdoublepush%5C_vector)
  - [VectorOfDouble::put\_Item](#vectorofdoubleput%5C_item)
  - [VectorOfDouble::size](#vectorofdoublesize)
  - [VectorOfDouble::slice](#vectorofdoubleslice)
  - [VectorOfDouble::sort](#vectorofdoublesort)
  - [VectorOfDouble::sort\_variant](#vectorofdoublesort%5C_variant)
  - [VectorOfDouble::start](#vectorofdoublestart)
- [VectorOfBool](#vectorofbool)
  - [VectorOfBool.Count](#vectorofboolcount)
  - [VectorOfBool::create](#vectorofboolcreate)
  - [VectorOfBool::Add](#vectorofbooladd)
  - [VectorOfBool::Items](#vectorofboolitems)
  - [VectorOfBool::Keys](#vectorofboolkeys)
  - [VectorOfBool::Remove](#vectorofboolremove)
  - [VectorOfBool::append](#vectorofboolappend)
  - [VectorOfBool::at](#vectorofboolat)
  - [VectorOfBool::clear](#vectorofboolclear)
  - [VectorOfBool::empty](#vectorofboolempty)
  - [VectorOfBool::end](#vectorofboolend)
  - [VectorOfBool::get\_Item](#vectorofboolget%5C_item)
  - [VectorOfBool::get\_\_NewEnum](#vectorofboolget%5C_%5C_newenum)
  - [VectorOfBool::push\_back](#vectorofboolpush%5C_back)
  - [VectorOfBool::push\_vector](#vectorofboolpush%5C_vector)
  - [VectorOfBool::put\_Item](#vectorofboolput%5C_item)
  - [VectorOfBool::size](#vectorofboolsize)
  - [VectorOfBool::slice](#vectorofboolslice)
  - [VectorOfBool::sort](#vectorofboolsort)
  - [VectorOfBool::sort\_variant](#vectorofboolsort%5C_variant)
  - [VectorOfBool::start](#vectorofboolstart)
- [VectorOfRectangle](#vectorofrectangle)
  - [VectorOfRectangle.Count](#vectorofrectanglecount)
  - [VectorOfRectangle::create](#vectorofrectanglecreate)
  - [VectorOfRectangle::Add](#vectorofrectangleadd)
  - [VectorOfRectangle::Items](#vectorofrectangleitems)
  - [VectorOfRectangle::Keys](#vectorofrectanglekeys)
  - [VectorOfRectangle::Remove](#vectorofrectangleremove)
  - [VectorOfRectangle::append](#vectorofrectangleappend)
  - [VectorOfRectangle::at](#vectorofrectangleat)
  - [VectorOfRectangle::clear](#vectorofrectangleclear)
  - [VectorOfRectangle::empty](#vectorofrectangleempty)
  - [VectorOfRectangle::end](#vectorofrectangleend)
  - [VectorOfRectangle::get\_Item](#vectorofrectangleget%5C_item)
  - [VectorOfRectangle::get\_\_NewEnum](#vectorofrectangleget%5C_%5C_newenum)
  - [VectorOfRectangle::push\_back](#vectorofrectanglepush%5C_back)
  - [VectorOfRectangle::push\_vector](#vectorofrectanglepush%5C_vector)
  - [VectorOfRectangle::put\_Item](#vectorofrectangleput%5C_item)
  - [VectorOfRectangle::size](#vectorofrectanglesize)
  - [VectorOfRectangle::slice](#vectorofrectangleslice)
  - [VectorOfRectangle::sort](#vectorofrectanglesort)
  - [VectorOfRectangle::sort\_variant](#vectorofrectanglesort%5C_variant)
  - [VectorOfRectangle::start](#vectorofrectanglestart)
- [VectorOfLong](#vectoroflong)
  - [VectorOfLong.Count](#vectoroflongcount)
  - [VectorOfLong::create](#vectoroflongcreate)
  - [VectorOfLong::Add](#vectoroflongadd)
  - [VectorOfLong::Items](#vectoroflongitems)
  - [VectorOfLong::Keys](#vectoroflongkeys)
  - [VectorOfLong::Remove](#vectoroflongremove)
  - [VectorOfLong::append](#vectoroflongappend)
  - [VectorOfLong::at](#vectoroflongat)
  - [VectorOfLong::clear](#vectoroflongclear)
  - [VectorOfLong::empty](#vectoroflongempty)
  - [VectorOfLong::end](#vectoroflongend)
  - [VectorOfLong::get\_Item](#vectoroflongget%5C_item)
  - [VectorOfLong::get\_\_NewEnum](#vectoroflongget%5C_%5C_newenum)
  - [VectorOfLong::push\_back](#vectoroflongpush%5C_back)
  - [VectorOfLong::push\_vector](#vectoroflongpush%5C_vector)
  - [VectorOfLong::put\_Item](#vectoroflongput%5C_item)
  - [VectorOfLong::size](#vectoroflongsize)
  - [VectorOfLong::slice](#vectoroflongslice)
  - [VectorOfLong::sort](#vectoroflongsort)
  - [VectorOfLong::sort\_variant](#vectoroflongsort%5C_variant)
  - [VectorOfLong::start](#vectoroflongstart)
- [VectorOfVectorOfSpaceVector](#vectorofvectorofspacevector)
  - [VectorOfVectorOfSpaceVector.Count](#vectorofvectorofspacevectorcount)
  - [VectorOfVectorOfSpaceVector::create](#vectorofvectorofspacevectorcreate)
  - [VectorOfVectorOfSpaceVector::Add](#vectorofvectorofspacevectoradd)
  - [VectorOfVectorOfSpaceVector::Items](#vectorofvectorofspacevectoritems)
  - [VectorOfVectorOfSpaceVector::Keys](#vectorofvectorofspacevectorkeys)
  - [VectorOfVectorOfSpaceVector::Remove](#vectorofvectorofspacevectorremove)
  - [VectorOfVectorOfSpaceVector::append](#vectorofvectorofspacevectorappend)
  - [VectorOfVectorOfSpaceVector::at](#vectorofvectorofspacevectorat)
  - [VectorOfVectorOfSpaceVector::clear](#vectorofvectorofspacevectorclear)
  - [VectorOfVectorOfSpaceVector::empty](#vectorofvectorofspacevectorempty)
  - [VectorOfVectorOfSpaceVector::end](#vectorofvectorofspacevectorend)
  - [VectorOfVectorOfSpaceVector::get\_Item](#vectorofvectorofspacevectorget%5C_item)
  - [VectorOfVectorOfSpaceVector::get\_\_NewEnum](#vectorofvectorofspacevectorget%5C_%5C_newenum)
  - [VectorOfVectorOfSpaceVector::push\_back](#vectorofvectorofspacevectorpush%5C_back)
  - [VectorOfVectorOfSpaceVector::push\_vector](#vectorofvectorofspacevectorpush%5C_vector)
  - [VectorOfVectorOfSpaceVector::put\_Item](#vectorofvectorofspacevectorput%5C_item)
  - [VectorOfVectorOfSpaceVector::size](#vectorofvectorofspacevectorsize)
  - [VectorOfVectorOfSpaceVector::slice](#vectorofvectorofspacevectorslice)
  - [VectorOfVectorOfSpaceVector::sort](#vectorofvectorofspacevectorsort)
  - [VectorOfVectorOfSpaceVector::sort\_variant](#vectorofvectorofspacevectorsort%5C_variant)
  - [VectorOfVectorOfSpaceVector::start](#vectorofvectorofspacevectorstart)
- [VectorOfPairOfULONGAndULONG](#vectorofpairofulongandulong)
  - [VectorOfPairOfULONGAndULONG.Count](#vectorofpairofulongandulongcount)
  - [VectorOfPairOfULONGAndULONG::create](#vectorofpairofulongandulongcreate)
  - [VectorOfPairOfULONGAndULONG::Add](#vectorofpairofulongandulongadd)
  - [VectorOfPairOfULONGAndULONG::Items](#vectorofpairofulongandulongitems)
  - [VectorOfPairOfULONGAndULONG::Keys](#vectorofpairofulongandulongkeys)
  - [VectorOfPairOfULONGAndULONG::Remove](#vectorofpairofulongandulongremove)
  - [VectorOfPairOfULONGAndULONG::append](#vectorofpairofulongandulongappend)
  - [VectorOfPairOfULONGAndULONG::at](#vectorofpairofulongandulongat)
  - [VectorOfPairOfULONGAndULONG::clear](#vectorofpairofulongandulongclear)
  - [VectorOfPairOfULONGAndULONG::empty](#vectorofpairofulongandulongempty)
  - [VectorOfPairOfULONGAndULONG::end](#vectorofpairofulongandulongend)
  - [VectorOfPairOfULONGAndULONG::get\_Item](#vectorofpairofulongandulongget%5C_item)
  - [VectorOfPairOfULONGAndULONG::get\_\_NewEnum](#vectorofpairofulongandulongget%5C_%5C_newenum)
  - [VectorOfPairOfULONGAndULONG::push\_back](#vectorofpairofulongandulongpush%5C_back)
  - [VectorOfPairOfULONGAndULONG::push\_vector](#vectorofpairofulongandulongpush%5C_vector)
  - [VectorOfPairOfULONGAndULONG::put\_Item](#vectorofpairofulongandulongput%5C_item)
  - [VectorOfPairOfULONGAndULONG::size](#vectorofpairofulongandulongsize)
  - [VectorOfPairOfULONGAndULONG::slice](#vectorofpairofulongandulongslice)
  - [VectorOfPairOfULONGAndULONG::sort](#vectorofpairofulongandulongsort)
  - [VectorOfPairOfULONGAndULONG::sort\_variant](#vectorofpairofulongandulongsort%5C_variant)
  - [VectorOfPairOfULONGAndULONG::start](#vectorofpairofulongandulongstart)
- [VectorOfVectorOfPairOfULONGAndULONG](#vectorofvectorofpairofulongandulong)
  - [VectorOfVectorOfPairOfULONGAndULONG.Count](#vectorofvectorofpairofulongandulongcount)
  - [VectorOfVectorOfPairOfULONGAndULONG::create](#vectorofvectorofpairofulongandulongcreate)
  - [VectorOfVectorOfPairOfULONGAndULONG::Add](#vectorofvectorofpairofulongandulongadd)
  - [VectorOfVectorOfPairOfULONGAndULONG::Items](#vectorofvectorofpairofulongandulongitems)
  - [VectorOfVectorOfPairOfULONGAndULONG::Keys](#vectorofvectorofpairofulongandulongkeys)
  - [VectorOfVectorOfPairOfULONGAndULONG::Remove](#vectorofvectorofpairofulongandulongremove)
  - [VectorOfVectorOfPairOfULONGAndULONG::append](#vectorofvectorofpairofulongandulongappend)
  - [VectorOfVectorOfPairOfULONGAndULONG::at](#vectorofvectorofpairofulongandulongat)
  - [VectorOfVectorOfPairOfULONGAndULONG::clear](#vectorofvectorofpairofulongandulongclear)
  - [VectorOfVectorOfPairOfULONGAndULONG::empty](#vectorofvectorofpairofulongandulongempty)
  - [VectorOfVectorOfPairOfULONGAndULONG::end](#vectorofvectorofpairofulongandulongend)
  - [VectorOfVectorOfPairOfULONGAndULONG::get\_Item](#vectorofvectorofpairofulongandulongget%5C_item)
  - [VectorOfVectorOfPairOfULONGAndULONG::get\_\_NewEnum](#vectorofvectorofpairofulongandulongget%5C_%5C_newenum)
  - [VectorOfVectorOfPairOfULONGAndULONG::push\_back](#vectorofvectorofpairofulongandulongpush%5C_back)
  - [VectorOfVectorOfPairOfULONGAndULONG::push\_vector](#vectorofvectorofpairofulongandulongpush%5C_vector)
  - [VectorOfVectorOfPairOfULONGAndULONG::put\_Item](#vectorofvectorofpairofulongandulongput%5C_item)
  - [VectorOfVectorOfPairOfULONGAndULONG::size](#vectorofvectorofpairofulongandulongsize)
  - [VectorOfVectorOfPairOfULONGAndULONG::slice](#vectorofvectorofpairofulongandulongslice)
  - [VectorOfVectorOfPairOfULONGAndULONG::sort](#vectorofvectorofpairofulongandulongsort)
  - [VectorOfVectorOfPairOfULONGAndULONG::sort\_variant](#vectorofvectorofpairofulongandulongsort%5C_variant)
  - [VectorOfVectorOfPairOfULONGAndULONG::start](#vectorofvectorofpairofulongandulongstart)
- [VectorOfVectorOfVectorOfPairOfULONGAndDouble](#vectorofvectorofvectorofpairofulonganddouble)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble.Count](#vectorofvectorofvectorofpairofulonganddoublecount)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::create](#vectorofvectorofvectorofpairofulonganddoublecreate)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Add](#vectorofvectorofvectorofpairofulonganddoubleadd)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Items](#vectorofvectorofvectorofpairofulonganddoubleitems)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Keys](#vectorofvectorofvectorofpairofulonganddoublekeys)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::Remove](#vectorofvectorofvectorofpairofulonganddoubleremove)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::append](#vectorofvectorofvectorofpairofulonganddoubleappend)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::at](#vectorofvectorofvectorofpairofulonganddoubleat)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::clear](#vectorofvectorofvectorofpairofulonganddoubleclear)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::empty](#vectorofvectorofvectorofpairofulonganddoubleempty)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::end](#vectorofvectorofvectorofpairofulonganddoubleend)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::get\_Item](#vectorofvectorofvectorofpairofulonganddoubleget%5C_item)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::get\_\_NewEnum](#vectorofvectorofvectorofpairofulonganddoubleget%5C_%5C_newenum)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::push\_back](#vectorofvectorofvectorofpairofulonganddoublepush%5C_back)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::push\_vector](#vectorofvectorofvectorofpairofulonganddoublepush%5C_vector)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::put\_Item](#vectorofvectorofvectorofpairofulonganddoubleput%5C_item)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::size](#vectorofvectorofvectorofpairofulonganddoublesize)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::slice](#vectorofvectorofvectorofpairofulonganddoubleslice)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort](#vectorofvectorofvectorofpairofulonganddoublesort)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort\_variant](#vectorofvectorofvectorofpairofulonganddoublesort%5C_variant)
  - [VectorOfVectorOfVectorOfPairOfULONGAndDouble::start](#vectorofvectorofvectorofpairofulonganddoublestart)
- [VectorOfVectorOfFull\_object\_detection](#vectorofvectoroffull%5C_object%5C_detection)
  - [VectorOfVectorOfFull\_object\_detection.Count](#vectorofvectoroffull%5C_object%5C_detectioncount)
  - [VectorOfVectorOfFull\_object\_detection::create](#vectorofvectoroffull%5C_object%5C_detectioncreate)
  - [VectorOfVectorOfFull\_object\_detection::Add](#vectorofvectoroffull%5C_object%5C_detectionadd)
  - [VectorOfVectorOfFull\_object\_detection::Items](#vectorofvectoroffull%5C_object%5C_detectionitems)
  - [VectorOfVectorOfFull\_object\_detection::Keys](#vectorofvectoroffull%5C_object%5C_detectionkeys)
  - [VectorOfVectorOfFull\_object\_detection::Remove](#vectorofvectoroffull%5C_object%5C_detectionremove)
  - [VectorOfVectorOfFull\_object\_detection::append](#vectorofvectoroffull%5C_object%5C_detectionappend)
  - [VectorOfVectorOfFull\_object\_detection::at](#vectorofvectoroffull%5C_object%5C_detectionat)
  - [VectorOfVectorOfFull\_object\_detection::clear](#vectorofvectoroffull%5C_object%5C_detectionclear)
  - [VectorOfVectorOfFull\_object\_detection::empty](#vectorofvectoroffull%5C_object%5C_detectionempty)
  - [VectorOfVectorOfFull\_object\_detection::end](#vectorofvectoroffull%5C_object%5C_detectionend)
  - [VectorOfVectorOfFull\_object\_detection::get\_Item](#vectorofvectoroffull%5C_object%5C_detectionget%5C_item)
  - [VectorOfVectorOfFull\_object\_detection::get\_\_NewEnum](#vectorofvectoroffull%5C_object%5C_detectionget%5C_%5C_newenum)
  - [VectorOfVectorOfFull\_object\_detection::push\_back](#vectorofvectoroffull%5C_object%5C_detectionpush%5C_back)
  - [VectorOfVectorOfFull\_object\_detection::push\_vector](#vectorofvectoroffull%5C_object%5C_detectionpush%5C_vector)
  - [VectorOfVectorOfFull\_object\_detection::put\_Item](#vectorofvectoroffull%5C_object%5C_detectionput%5C_item)
  - [VectorOfVectorOfFull\_object\_detection::size](#vectorofvectoroffull%5C_object%5C_detectionsize)
  - [VectorOfVectorOfFull\_object\_detection::slice](#vectorofvectoroffull%5C_object%5C_detectionslice)
  - [VectorOfVectorOfFull\_object\_detection::sort](#vectorofvectoroffull%5C_object%5C_detectionsort)
  - [VectorOfVectorOfFull\_object\_detection::sort\_variant](#vectorofvectoroffull%5C_object%5C_detectionsort%5C_variant)
  - [VectorOfVectorOfFull\_object\_detection::start](#vectorofvectoroffull%5C_object%5C_detectionstart)
- [VectorOfVectorOfRectangle](#vectorofvectorofrectangle)
  - [VectorOfVectorOfRectangle.Count](#vectorofvectorofrectanglecount)
  - [VectorOfVectorOfRectangle::create](#vectorofvectorofrectanglecreate)
  - [VectorOfVectorOfRectangle::Add](#vectorofvectorofrectangleadd)
  - [VectorOfVectorOfRectangle::Items](#vectorofvectorofrectangleitems)
  - [VectorOfVectorOfRectangle::Keys](#vectorofvectorofrectanglekeys)
  - [VectorOfVectorOfRectangle::Remove](#vectorofvectorofrectangleremove)
  - [VectorOfVectorOfRectangle::append](#vectorofvectorofrectangleappend)
  - [VectorOfVectorOfRectangle::at](#vectorofvectorofrectangleat)
  - [VectorOfVectorOfRectangle::clear](#vectorofvectorofrectangleclear)
  - [VectorOfVectorOfRectangle::empty](#vectorofvectorofrectangleempty)
  - [VectorOfVectorOfRectangle::end](#vectorofvectorofrectangleend)
  - [VectorOfVectorOfRectangle::get\_Item](#vectorofvectorofrectangleget%5C_item)
  - [VectorOfVectorOfRectangle::get\_\_NewEnum](#vectorofvectorofrectangleget%5C_%5C_newenum)
  - [VectorOfVectorOfRectangle::push\_back](#vectorofvectorofrectanglepush%5C_back)
  - [VectorOfVectorOfRectangle::push\_vector](#vectorofvectorofrectanglepush%5C_vector)
  - [VectorOfVectorOfRectangle::put\_Item](#vectorofvectorofrectangleput%5C_item)
  - [VectorOfVectorOfRectangle::size](#vectorofvectorofrectanglesize)
  - [VectorOfVectorOfRectangle::slice](#vectorofvectorofrectangleslice)
  - [VectorOfVectorOfRectangle::sort](#vectorofvectorofrectanglesort)
  - [VectorOfVectorOfRectangle::sort\_variant](#vectorofvectorofrectanglesort%5C_variant)
  - [VectorOfVectorOfRectangle::start](#vectorofvectorofrectanglestart)
- [VectorOfVec\_ranking\_pair](#vectorofvec%5C_ranking%5C_pair)
  - [VectorOfVec\_ranking\_pair.Count](#vectorofvec%5C_ranking%5C_paircount)
  - [VectorOfVec\_ranking\_pair::create](#vectorofvec%5C_ranking%5C_paircreate)
  - [VectorOfVec\_ranking\_pair::Add](#vectorofvec%5C_ranking%5C_pairadd)
  - [VectorOfVec\_ranking\_pair::Items](#vectorofvec%5C_ranking%5C_pairitems)
  - [VectorOfVec\_ranking\_pair::Keys](#vectorofvec%5C_ranking%5C_pairkeys)
  - [VectorOfVec\_ranking\_pair::Remove](#vectorofvec%5C_ranking%5C_pairremove)
  - [VectorOfVec\_ranking\_pair::append](#vectorofvec%5C_ranking%5C_pairappend)
  - [VectorOfVec\_ranking\_pair::at](#vectorofvec%5C_ranking%5C_pairat)
  - [VectorOfVec\_ranking\_pair::clear](#vectorofvec%5C_ranking%5C_pairclear)
  - [VectorOfVec\_ranking\_pair::empty](#vectorofvec%5C_ranking%5C_pairempty)
  - [VectorOfVec\_ranking\_pair::end](#vectorofvec%5C_ranking%5C_pairend)
  - [VectorOfVec\_ranking\_pair::get\_Item](#vectorofvec%5C_ranking%5C_pairget%5C_item)
  - [VectorOfVec\_ranking\_pair::get\_\_NewEnum](#vectorofvec%5C_ranking%5C_pairget%5C_%5C_newenum)
  - [VectorOfVec\_ranking\_pair::push\_back](#vectorofvec%5C_ranking%5C_pairpush%5C_back)
  - [VectorOfVec\_ranking\_pair::push\_vector](#vectorofvec%5C_ranking%5C_pairpush%5C_vector)
  - [VectorOfVec\_ranking\_pair::put\_Item](#vectorofvec%5C_ranking%5C_pairput%5C_item)
  - [VectorOfVec\_ranking\_pair::size](#vectorofvec%5C_ranking%5C_pairsize)
  - [VectorOfVec\_ranking\_pair::slice](#vectorofvec%5C_ranking%5C_pairslice)
  - [VectorOfVec\_ranking\_pair::sort](#vectorofvec%5C_ranking%5C_pairsort)
  - [VectorOfVec\_ranking\_pair::sort\_variant](#vectorofvec%5C_ranking%5C_pairsort%5C_variant)
  - [VectorOfVec\_ranking\_pair::start](#vectorofvec%5C_ranking%5C_pairstart)
- [VectorOfSparse\_ranking\_pair](#vectorofsparse%5C_ranking%5C_pair)
  - [VectorOfSparse\_ranking\_pair.Count](#vectorofsparse%5C_ranking%5C_paircount)
  - [VectorOfSparse\_ranking\_pair::create](#vectorofsparse%5C_ranking%5C_paircreate)
  - [VectorOfSparse\_ranking\_pair::Add](#vectorofsparse%5C_ranking%5C_pairadd)
  - [VectorOfSparse\_ranking\_pair::Items](#vectorofsparse%5C_ranking%5C_pairitems)
  - [VectorOfSparse\_ranking\_pair::Keys](#vectorofsparse%5C_ranking%5C_pairkeys)
  - [VectorOfSparse\_ranking\_pair::Remove](#vectorofsparse%5C_ranking%5C_pairremove)
  - [VectorOfSparse\_ranking\_pair::append](#vectorofsparse%5C_ranking%5C_pairappend)
  - [VectorOfSparse\_ranking\_pair::at](#vectorofsparse%5C_ranking%5C_pairat)
  - [VectorOfSparse\_ranking\_pair::clear](#vectorofsparse%5C_ranking%5C_pairclear)
  - [VectorOfSparse\_ranking\_pair::empty](#vectorofsparse%5C_ranking%5C_pairempty)
  - [VectorOfSparse\_ranking\_pair::end](#vectorofsparse%5C_ranking%5C_pairend)
  - [VectorOfSparse\_ranking\_pair::get\_Item](#vectorofsparse%5C_ranking%5C_pairget%5C_item)
  - [VectorOfSparse\_ranking\_pair::get\_\_NewEnum](#vectorofsparse%5C_ranking%5C_pairget%5C_%5C_newenum)
  - [VectorOfSparse\_ranking\_pair::push\_back](#vectorofsparse%5C_ranking%5C_pairpush%5C_back)
  - [VectorOfSparse\_ranking\_pair::push\_vector](#vectorofsparse%5C_ranking%5C_pairpush%5C_vector)
  - [VectorOfSparse\_ranking\_pair::put\_Item](#vectorofsparse%5C_ranking%5C_pairput%5C_item)
  - [VectorOfSparse\_ranking\_pair::size](#vectorofsparse%5C_ranking%5C_pairsize)
  - [VectorOfSparse\_ranking\_pair::slice](#vectorofsparse%5C_ranking%5C_pairslice)
  - [VectorOfSparse\_ranking\_pair::sort](#vectorofsparse%5C_ranking%5C_pairsort)
  - [VectorOfSparse\_ranking\_pair::sort\_variant](#vectorofsparse%5C_ranking%5C_pairsort%5C_variant)
  - [VectorOfSparse\_ranking\_pair::start](#vectorofsparse%5C_ranking%5C_pairstart)
- [VectorOfDpoint](#vectorofdpoint)
  - [VectorOfDpoint.Count](#vectorofdpointcount)
  - [VectorOfDpoint::create](#vectorofdpointcreate)
  - [VectorOfDpoint::Add](#vectorofdpointadd)
  - [VectorOfDpoint::Items](#vectorofdpointitems)
  - [VectorOfDpoint::Keys](#vectorofdpointkeys)
  - [VectorOfDpoint::Remove](#vectorofdpointremove)
  - [VectorOfDpoint::append](#vectorofdpointappend)
  - [VectorOfDpoint::at](#vectorofdpointat)
  - [VectorOfDpoint::clear](#vectorofdpointclear)
  - [VectorOfDpoint::empty](#vectorofdpointempty)
  - [VectorOfDpoint::end](#vectorofdpointend)
  - [VectorOfDpoint::get\_Item](#vectorofdpointget%5C_item)
  - [VectorOfDpoint::get\_\_NewEnum](#vectorofdpointget%5C_%5C_newenum)
  - [VectorOfDpoint::push\_back](#vectorofdpointpush%5C_back)
  - [VectorOfDpoint::push\_vector](#vectorofdpointpush%5C_vector)
  - [VectorOfDpoint::put\_Item](#vectorofdpointput%5C_item)
  - [VectorOfDpoint::size](#vectorofdpointsize)
  - [VectorOfDpoint::slice](#vectorofdpointslice)
  - [VectorOfDpoint::sort](#vectorofdpointsort)
  - [VectorOfDpoint::sort\_variant](#vectorofdpointsort%5C_variant)
  - [VectorOfDpoint::start](#vectorofdpointstart)
- [VectorOfPoint](#vectorofpoint)
  - [VectorOfPoint.Count](#vectorofpointcount)
  - [VectorOfPoint::create](#vectorofpointcreate)
  - [VectorOfPoint::Add](#vectorofpointadd)
  - [VectorOfPoint::Items](#vectorofpointitems)
  - [VectorOfPoint::Keys](#vectorofpointkeys)
  - [VectorOfPoint::Remove](#vectorofpointremove)
  - [VectorOfPoint::append](#vectorofpointappend)
  - [VectorOfPoint::at](#vectorofpointat)
  - [VectorOfPoint::clear](#vectorofpointclear)
  - [VectorOfPoint::empty](#vectorofpointempty)
  - [VectorOfPoint::end](#vectorofpointend)
  - [VectorOfPoint::get\_Item](#vectorofpointget%5C_item)
  - [VectorOfPoint::get\_\_NewEnum](#vectorofpointget%5C_%5C_newenum)
  - [VectorOfPoint::push\_back](#vectorofpointpush%5C_back)
  - [VectorOfPoint::push\_vector](#vectorofpointpush%5C_vector)
  - [VectorOfPoint::put\_Item](#vectorofpointput%5C_item)
  - [VectorOfPoint::size](#vectorofpointsize)
  - [VectorOfPoint::slice](#vectorofpointslice)
  - [VectorOfPoint::sort](#vectorofpointsort)
  - [VectorOfPoint::sort\_variant](#vectorofpointsort%5C_variant)
  - [VectorOfPoint::start](#vectorofpointstart)
- [VectorOfVectorOfDouble](#vectorofvectorofdouble)
  - [VectorOfVectorOfDouble.Count](#vectorofvectorofdoublecount)
  - [VectorOfVectorOfDouble::create](#vectorofvectorofdoublecreate)
  - [VectorOfVectorOfDouble::Add](#vectorofvectorofdoubleadd)
  - [VectorOfVectorOfDouble::Items](#vectorofvectorofdoubleitems)
  - [VectorOfVectorOfDouble::Keys](#vectorofvectorofdoublekeys)
  - [VectorOfVectorOfDouble::Remove](#vectorofvectorofdoubleremove)
  - [VectorOfVectorOfDouble::append](#vectorofvectorofdoubleappend)
  - [VectorOfVectorOfDouble::at](#vectorofvectorofdoubleat)
  - [VectorOfVectorOfDouble::clear](#vectorofvectorofdoubleclear)
  - [VectorOfVectorOfDouble::empty](#vectorofvectorofdoubleempty)
  - [VectorOfVectorOfDouble::end](#vectorofvectorofdoubleend)
  - [VectorOfVectorOfDouble::get\_Item](#vectorofvectorofdoubleget%5C_item)
  - [VectorOfVectorOfDouble::get\_\_NewEnum](#vectorofvectorofdoubleget%5C_%5C_newenum)
  - [VectorOfVectorOfDouble::push\_back](#vectorofvectorofdoublepush%5C_back)
  - [VectorOfVectorOfDouble::push\_vector](#vectorofvectorofdoublepush%5C_vector)
  - [VectorOfVectorOfDouble::put\_Item](#vectorofvectorofdoubleput%5C_item)
  - [VectorOfVectorOfDouble::size](#vectorofvectorofdoublesize)
  - [VectorOfVectorOfDouble::slice](#vectorofvectorofdoubleslice)
  - [VectorOfVectorOfDouble::sort](#vectorofvectorofdoublesort)
  - [VectorOfVectorOfDouble::sort\_variant](#vectorofvectorofdoublesort%5C_variant)
  - [VectorOfVectorOfDouble::start](#vectorofvectorofdoublestart)
- [VectorOfMmod\_rect](#vectorofmmod%5C_rect)
  - [VectorOfMmod\_rect.Count](#vectorofmmod%5C_rectcount)
  - [VectorOfMmod\_rect::create](#vectorofmmod%5C_rectcreate)
  - [VectorOfMmod\_rect::Add](#vectorofmmod%5C_rectadd)
  - [VectorOfMmod\_rect::Items](#vectorofmmod%5C_rectitems)
  - [VectorOfMmod\_rect::Keys](#vectorofmmod%5C_rectkeys)
  - [VectorOfMmod\_rect::Remove](#vectorofmmod%5C_rectremove)
  - [VectorOfMmod\_rect::append](#vectorofmmod%5C_rectappend)
  - [VectorOfMmod\_rect::at](#vectorofmmod%5C_rectat)
  - [VectorOfMmod\_rect::clear](#vectorofmmod%5C_rectclear)
  - [VectorOfMmod\_rect::empty](#vectorofmmod%5C_rectempty)
  - [VectorOfMmod\_rect::end](#vectorofmmod%5C_rectend)
  - [VectorOfMmod\_rect::get\_Item](#vectorofmmod%5C_rectget%5C_item)
  - [VectorOfMmod\_rect::get\_\_NewEnum](#vectorofmmod%5C_rectget%5C_%5C_newenum)
  - [VectorOfMmod\_rect::push\_back](#vectorofmmod%5C_rectpush%5C_back)
  - [VectorOfMmod\_rect::push\_vector](#vectorofmmod%5C_rectpush%5C_vector)
  - [VectorOfMmod\_rect::put\_Item](#vectorofmmod%5C_rectput%5C_item)
  - [VectorOfMmod\_rect::size](#vectorofmmod%5C_rectsize)
  - [VectorOfMmod\_rect::slice](#vectorofmmod%5C_rectslice)
  - [VectorOfMmod\_rect::sort](#vectorofmmod%5C_rectsort)
  - [VectorOfMmod\_rect::sort\_variant](#vectorofmmod%5C_rectsort%5C_variant)
  - [VectorOfMmod\_rect::start](#vectorofmmod%5C_rectstart)
- [VectorOfVectorOfMmod\_rect](#vectorofvectorofmmod%5C_rect)
  - [VectorOfVectorOfMmod\_rect.Count](#vectorofvectorofmmod%5C_rectcount)
  - [VectorOfVectorOfMmod\_rect::create](#vectorofvectorofmmod%5C_rectcreate)
  - [VectorOfVectorOfMmod\_rect::Add](#vectorofvectorofmmod%5C_rectadd)
  - [VectorOfVectorOfMmod\_rect::Items](#vectorofvectorofmmod%5C_rectitems)
  - [VectorOfVectorOfMmod\_rect::Keys](#vectorofvectorofmmod%5C_rectkeys)
  - [VectorOfVectorOfMmod\_rect::Remove](#vectorofvectorofmmod%5C_rectremove)
  - [VectorOfVectorOfMmod\_rect::append](#vectorofvectorofmmod%5C_rectappend)
  - [VectorOfVectorOfMmod\_rect::at](#vectorofvectorofmmod%5C_rectat)
  - [VectorOfVectorOfMmod\_rect::clear](#vectorofvectorofmmod%5C_rectclear)
  - [VectorOfVectorOfMmod\_rect::empty](#vectorofvectorofmmod%5C_rectempty)
  - [VectorOfVectorOfMmod\_rect::end](#vectorofvectorofmmod%5C_rectend)
  - [VectorOfVectorOfMmod\_rect::get\_Item](#vectorofvectorofmmod%5C_rectget%5C_item)
  - [VectorOfVectorOfMmod\_rect::get\_\_NewEnum](#vectorofvectorofmmod%5C_rectget%5C_%5C_newenum)
  - [VectorOfVectorOfMmod\_rect::push\_back](#vectorofvectorofmmod%5C_rectpush%5C_back)
  - [VectorOfVectorOfMmod\_rect::push\_vector](#vectorofvectorofmmod%5C_rectpush%5C_vector)
  - [VectorOfVectorOfMmod\_rect::put\_Item](#vectorofvectorofmmod%5C_rectput%5C_item)
  - [VectorOfVectorOfMmod\_rect::size](#vectorofvectorofmmod%5C_rectsize)
  - [VectorOfVectorOfMmod\_rect::slice](#vectorofvectorofmmod%5C_rectslice)
  - [VectorOfVectorOfMmod\_rect::sort](#vectorofvectorofmmod%5C_rectsort)
  - [VectorOfVectorOfMmod\_rect::sort\_variant](#vectorofvectorofmmod%5C_rectsort%5C_variant)
  - [VectorOfVectorOfMmod\_rect::start](#vectorofvectorofmmod%5C_rectstart)
- [VectorOfSimple\_object\_detector\_com](#vectorofsimple%5C_object%5C_detector%5C_com)
  - [VectorOfSimple\_object\_detector\_com.Count](#vectorofsimple%5C_object%5C_detector%5C_comcount)
  - [VectorOfSimple\_object\_detector\_com::create](#vectorofsimple%5C_object%5C_detector%5C_comcreate)
  - [VectorOfSimple\_object\_detector\_com::Add](#vectorofsimple%5C_object%5C_detector%5C_comadd)
  - [VectorOfSimple\_object\_detector\_com::Items](#vectorofsimple%5C_object%5C_detector%5C_comitems)
  - [VectorOfSimple\_object\_detector\_com::Keys](#vectorofsimple%5C_object%5C_detector%5C_comkeys)
  - [VectorOfSimple\_object\_detector\_com::Remove](#vectorofsimple%5C_object%5C_detector%5C_comremove)
  - [VectorOfSimple\_object\_detector\_com::append](#vectorofsimple%5C_object%5C_detector%5C_comappend)
  - [VectorOfSimple\_object\_detector\_com::at](#vectorofsimple%5C_object%5C_detector%5C_comat)
  - [VectorOfSimple\_object\_detector\_com::clear](#vectorofsimple%5C_object%5C_detector%5C_comclear)
  - [VectorOfSimple\_object\_detector\_com::empty](#vectorofsimple%5C_object%5C_detector%5C_comempty)
  - [VectorOfSimple\_object\_detector\_com::end](#vectorofsimple%5C_object%5C_detector%5C_comend)
  - [VectorOfSimple\_object\_detector\_com::get\_Item](#vectorofsimple%5C_object%5C_detector%5C_comget%5C_item)
  - [VectorOfSimple\_object\_detector\_com::get\_\_NewEnum](#vectorofsimple%5C_object%5C_detector%5C_comget%5C_%5C_newenum)
  - [VectorOfSimple\_object\_detector\_com::push\_back](#vectorofsimple%5C_object%5C_detector%5C_compush%5C_back)
  - [VectorOfSimple\_object\_detector\_com::push\_vector](#vectorofsimple%5C_object%5C_detector%5C_compush%5C_vector)
  - [VectorOfSimple\_object\_detector\_com::put\_Item](#vectorofsimple%5C_object%5C_detector%5C_comput%5C_item)
  - [VectorOfSimple\_object\_detector\_com::size](#vectorofsimple%5C_object%5C_detector%5C_comsize)
  - [VectorOfSimple\_object\_detector\_com::slice](#vectorofsimple%5C_object%5C_detector%5C_comslice)
  - [VectorOfSimple\_object\_detector\_com::sort](#vectorofsimple%5C_object%5C_detector%5C_comsort)
  - [VectorOfSimple\_object\_detector\_com::sort\_variant](#vectorofsimple%5C_object%5C_detector%5C_comsort%5C_variant)
  - [VectorOfSimple\_object\_detector\_com::start](#vectorofsimple%5C_object%5C_detector%5C_comstart)
- [VectorOfFhog\_object\_detector](#vectoroffhog%5C_object%5C_detector)
  - [VectorOfFhog\_object\_detector.Count](#vectoroffhog%5C_object%5C_detectorcount)
  - [VectorOfFhog\_object\_detector::create](#vectoroffhog%5C_object%5C_detectorcreate)
  - [VectorOfFhog\_object\_detector::Add](#vectoroffhog%5C_object%5C_detectoradd)
  - [VectorOfFhog\_object\_detector::Items](#vectoroffhog%5C_object%5C_detectoritems)
  - [VectorOfFhog\_object\_detector::Keys](#vectoroffhog%5C_object%5C_detectorkeys)
  - [VectorOfFhog\_object\_detector::Remove](#vectoroffhog%5C_object%5C_detectorremove)
  - [VectorOfFhog\_object\_detector::append](#vectoroffhog%5C_object%5C_detectorappend)
  - [VectorOfFhog\_object\_detector::at](#vectoroffhog%5C_object%5C_detectorat)
  - [VectorOfFhog\_object\_detector::clear](#vectoroffhog%5C_object%5C_detectorclear)
  - [VectorOfFhog\_object\_detector::empty](#vectoroffhog%5C_object%5C_detectorempty)
  - [VectorOfFhog\_object\_detector::end](#vectoroffhog%5C_object%5C_detectorend)
  - [VectorOfFhog\_object\_detector::get\_Item](#vectoroffhog%5C_object%5C_detectorget%5C_item)
  - [VectorOfFhog\_object\_detector::get\_\_NewEnum](#vectoroffhog%5C_object%5C_detectorget%5C_%5C_newenum)
  - [VectorOfFhog\_object\_detector::push\_back](#vectoroffhog%5C_object%5C_detectorpush%5C_back)
  - [VectorOfFhog\_object\_detector::push\_vector](#vectoroffhog%5C_object%5C_detectorpush%5C_vector)
  - [VectorOfFhog\_object\_detector::put\_Item](#vectoroffhog%5C_object%5C_detectorput%5C_item)
  - [VectorOfFhog\_object\_detector::size](#vectoroffhog%5C_object%5C_detectorsize)
  - [VectorOfFhog\_object\_detector::slice](#vectoroffhog%5C_object%5C_detectorslice)
  - [VectorOfFhog\_object\_detector::sort](#vectoroffhog%5C_object%5C_detectorsort)
  - [VectorOfFhog\_object\_detector::sort\_variant](#vectoroffhog%5C_object%5C_detectorsort%5C_variant)
  - [VectorOfFhog\_object\_detector::start](#vectoroffhog%5C_object%5C_detectorstart)
- [VectorOfUchar](#vectorofuchar)
  - [VectorOfUchar.Count](#vectorofucharcount)
  - [VectorOfUchar::create](#vectorofucharcreate)
  - [VectorOfUchar::Add](#vectorofucharadd)
  - [VectorOfUchar::Items](#vectorofucharitems)
  - [VectorOfUchar::Keys](#vectorofucharkeys)
  - [VectorOfUchar::Remove](#vectorofucharremove)
  - [VectorOfUchar::append](#vectorofucharappend)
  - [VectorOfUchar::at](#vectorofucharat)
  - [VectorOfUchar::clear](#vectorofucharclear)
  - [VectorOfUchar::empty](#vectorofucharempty)
  - [VectorOfUchar::end](#vectorofucharend)
  - [VectorOfUchar::get\_Item](#vectorofucharget%5C_item)
  - [VectorOfUchar::get\_\_NewEnum](#vectorofucharget%5C_%5C_newenum)
  - [VectorOfUchar::push\_back](#vectorofucharpush%5C_back)
  - [VectorOfUchar::push\_vector](#vectorofucharpush%5C_vector)
  - [VectorOfUchar::put\_Item](#vectorofucharput%5C_item)
  - [VectorOfUchar::size](#vectorofucharsize)
  - [VectorOfUchar::slice](#vectorofucharslice)
  - [VectorOfUchar::sort](#vectorofucharsort)
  - [VectorOfUchar::sort\_variant](#vectorofucharsort%5C_variant)
  - [VectorOfUchar::start](#vectorofucharstart)
- [VectorOfInt](#vectorofint)
  - [VectorOfInt.Count](#vectorofintcount)
  - [VectorOfInt::create](#vectorofintcreate)
  - [VectorOfInt::Add](#vectorofintadd)
  - [VectorOfInt::Items](#vectorofintitems)
  - [VectorOfInt::Keys](#vectorofintkeys)
  - [VectorOfInt::Remove](#vectorofintremove)
  - [VectorOfInt::append](#vectorofintappend)
  - [VectorOfInt::at](#vectorofintat)
  - [VectorOfInt::clear](#vectorofintclear)
  - [VectorOfInt::empty](#vectorofintempty)
  - [VectorOfInt::end](#vectorofintend)
  - [VectorOfInt::get\_Item](#vectorofintget%5C_item)
  - [VectorOfInt::get\_\_NewEnum](#vectorofintget%5C_%5C_newenum)
  - [VectorOfInt::push\_back](#vectorofintpush%5C_back)
  - [VectorOfInt::push\_vector](#vectorofintpush%5C_vector)
  - [VectorOfInt::put\_Item](#vectorofintput%5C_item)
  - [VectorOfInt::size](#vectorofintsize)
  - [VectorOfInt::slice](#vectorofintslice)
  - [VectorOfInt::sort](#vectorofintsort)
  - [VectorOfInt::sort\_variant](#vectorofintsort%5C_variant)
  - [VectorOfInt::start](#vectorofintstart)
- [VectorOfFunction\_spec](#vectoroffunction%5C_spec)
  - [VectorOfFunction\_spec.Count](#vectoroffunction%5C_speccount)
  - [VectorOfFunction\_spec::create](#vectoroffunction%5C_speccreate)
  - [VectorOfFunction\_spec::Add](#vectoroffunction%5C_specadd)
  - [VectorOfFunction\_spec::Items](#vectoroffunction%5C_specitems)
  - [VectorOfFunction\_spec::Keys](#vectoroffunction%5C_speckeys)
  - [VectorOfFunction\_spec::Remove](#vectoroffunction%5C_specremove)
  - [VectorOfFunction\_spec::append](#vectoroffunction%5C_specappend)
  - [VectorOfFunction\_spec::at](#vectoroffunction%5C_specat)
  - [VectorOfFunction\_spec::clear](#vectoroffunction%5C_specclear)
  - [VectorOfFunction\_spec::empty](#vectoroffunction%5C_specempty)
  - [VectorOfFunction\_spec::end](#vectoroffunction%5C_specend)
  - [VectorOfFunction\_spec::get\_Item](#vectoroffunction%5C_specget%5C_item)
  - [VectorOfFunction\_spec::get\_\_NewEnum](#vectoroffunction%5C_specget%5C_%5C_newenum)
  - [VectorOfFunction\_spec::push\_back](#vectoroffunction%5C_specpush%5C_back)
  - [VectorOfFunction\_spec::push\_vector](#vectoroffunction%5C_specpush%5C_vector)
  - [VectorOfFunction\_spec::put\_Item](#vectoroffunction%5C_specput%5C_item)
  - [VectorOfFunction\_spec::size](#vectoroffunction%5C_specsize)
  - [VectorOfFunction\_spec::slice](#vectoroffunction%5C_specslice)
  - [VectorOfFunction\_spec::sort](#vectoroffunction%5C_specsort)
  - [VectorOfFunction\_spec::sort\_variant](#vectoroffunction%5C_specsort%5C_variant)
  - [VectorOfFunction\_spec::start](#vectoroffunction%5C_specstart)
- [VectorOfFunction\_evaluation](#vectoroffunction%5C_evaluation)
  - [VectorOfFunction\_evaluation.Count](#vectoroffunction%5C_evaluationcount)
  - [VectorOfFunction\_evaluation::create](#vectoroffunction%5C_evaluationcreate)
  - [VectorOfFunction\_evaluation::Add](#vectoroffunction%5C_evaluationadd)
  - [VectorOfFunction\_evaluation::Items](#vectoroffunction%5C_evaluationitems)
  - [VectorOfFunction\_evaluation::Keys](#vectoroffunction%5C_evaluationkeys)
  - [VectorOfFunction\_evaluation::Remove](#vectoroffunction%5C_evaluationremove)
  - [VectorOfFunction\_evaluation::append](#vectoroffunction%5C_evaluationappend)
  - [VectorOfFunction\_evaluation::at](#vectoroffunction%5C_evaluationat)
  - [VectorOfFunction\_evaluation::clear](#vectoroffunction%5C_evaluationclear)
  - [VectorOfFunction\_evaluation::empty](#vectoroffunction%5C_evaluationempty)
  - [VectorOfFunction\_evaluation::end](#vectoroffunction%5C_evaluationend)
  - [VectorOfFunction\_evaluation::get\_Item](#vectoroffunction%5C_evaluationget%5C_item)
  - [VectorOfFunction\_evaluation::get\_\_NewEnum](#vectoroffunction%5C_evaluationget%5C_%5C_newenum)
  - [VectorOfFunction\_evaluation::push\_back](#vectoroffunction%5C_evaluationpush%5C_back)
  - [VectorOfFunction\_evaluation::push\_vector](#vectoroffunction%5C_evaluationpush%5C_vector)
  - [VectorOfFunction\_evaluation::put\_Item](#vectoroffunction%5C_evaluationput%5C_item)
  - [VectorOfFunction\_evaluation::size](#vectoroffunction%5C_evaluationsize)
  - [VectorOfFunction\_evaluation::slice](#vectoroffunction%5C_evaluationslice)
  - [VectorOfFunction\_evaluation::sort](#vectoroffunction%5C_evaluationsort)
  - [VectorOfFunction\_evaluation::sort\_variant](#vectoroffunction%5C_evaluationsort%5C_variant)
  - [VectorOfFunction\_evaluation::start](#vectoroffunction%5C_evaluationstart)
- [VectorOfVectorOfFunction\_evaluation](#vectorofvectoroffunction%5C_evaluation)
  - [VectorOfVectorOfFunction\_evaluation.Count](#vectorofvectoroffunction%5C_evaluationcount)
  - [VectorOfVectorOfFunction\_evaluation::create](#vectorofvectoroffunction%5C_evaluationcreate)
  - [VectorOfVectorOfFunction\_evaluation::Add](#vectorofvectoroffunction%5C_evaluationadd)
  - [VectorOfVectorOfFunction\_evaluation::Items](#vectorofvectoroffunction%5C_evaluationitems)
  - [VectorOfVectorOfFunction\_evaluation::Keys](#vectorofvectoroffunction%5C_evaluationkeys)
  - [VectorOfVectorOfFunction\_evaluation::Remove](#vectorofvectoroffunction%5C_evaluationremove)
  - [VectorOfVectorOfFunction\_evaluation::append](#vectorofvectoroffunction%5C_evaluationappend)
  - [VectorOfVectorOfFunction\_evaluation::at](#vectorofvectoroffunction%5C_evaluationat)
  - [VectorOfVectorOfFunction\_evaluation::clear](#vectorofvectoroffunction%5C_evaluationclear)
  - [VectorOfVectorOfFunction\_evaluation::empty](#vectorofvectoroffunction%5C_evaluationempty)
  - [VectorOfVectorOfFunction\_evaluation::end](#vectorofvectoroffunction%5C_evaluationend)
  - [VectorOfVectorOfFunction\_evaluation::get\_Item](#vectorofvectoroffunction%5C_evaluationget%5C_item)
  - [VectorOfVectorOfFunction\_evaluation::get\_\_NewEnum](#vectorofvectoroffunction%5C_evaluationget%5C_%5C_newenum)
  - [VectorOfVectorOfFunction\_evaluation::push\_back](#vectorofvectoroffunction%5C_evaluationpush%5C_back)
  - [VectorOfVectorOfFunction\_evaluation::push\_vector](#vectorofvectoroffunction%5C_evaluationpush%5C_vector)
  - [VectorOfVectorOfFunction\_evaluation::put\_Item](#vectorofvectoroffunction%5C_evaluationput%5C_item)
  - [VectorOfVectorOfFunction\_evaluation::size](#vectorofvectoroffunction%5C_evaluationsize)
  - [VectorOfVectorOfFunction\_evaluation::slice](#vectorofvectoroffunction%5C_evaluationslice)
  - [VectorOfVectorOfFunction\_evaluation::sort](#vectorofvectoroffunction%5C_evaluationsort)
  - [VectorOfVectorOfFunction\_evaluation::sort\_variant](#vectorofvectoroffunction%5C_evaluationsort%5C_variant)
  - [VectorOfVectorOfFunction\_evaluation::start](#vectorofvectoroffunction%5C_evaluationstart)
- [VectorOfDrectangle](#vectorofdrectangle)
  - [VectorOfDrectangle.Count](#vectorofdrectanglecount)
  - [VectorOfDrectangle::create](#vectorofdrectanglecreate)
  - [VectorOfDrectangle::Add](#vectorofdrectangleadd)
  - [VectorOfDrectangle::Items](#vectorofdrectangleitems)
  - [VectorOfDrectangle::Keys](#vectorofdrectanglekeys)
  - [VectorOfDrectangle::Remove](#vectorofdrectangleremove)
  - [VectorOfDrectangle::append](#vectorofdrectangleappend)
  - [VectorOfDrectangle::at](#vectorofdrectangleat)
  - [VectorOfDrectangle::clear](#vectorofdrectangleclear)
  - [VectorOfDrectangle::empty](#vectorofdrectangleempty)
  - [VectorOfDrectangle::end](#vectorofdrectangleend)
  - [VectorOfDrectangle::get\_Item](#vectorofdrectangleget%5C_item)
  - [VectorOfDrectangle::get\_\_NewEnum](#vectorofdrectangleget%5C_%5C_newenum)
  - [VectorOfDrectangle::push\_back](#vectorofdrectanglepush%5C_back)
  - [VectorOfDrectangle::push\_vector](#vectorofdrectanglepush%5C_vector)
  - [VectorOfDrectangle::put\_Item](#vectorofdrectangleput%5C_item)
  - [VectorOfDrectangle::size](#vectorofdrectanglesize)
  - [VectorOfDrectangle::slice](#vectorofdrectangleslice)
  - [VectorOfDrectangle::sort](#vectorofdrectanglesort)
  - [VectorOfDrectangle::sort\_variant](#vectorofdrectanglesort%5C_variant)
  - [VectorOfDrectangle::start](#vectorofdrectanglestart)
- [VectorOfImage\_window\_keyboard\_state\_masks](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masks)
  - [VectorOfImage\_window\_keyboard\_state\_masks.Count](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskscount)
  - [VectorOfImage\_window\_keyboard\_state\_masks::create](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskscreate)
  - [VectorOfImage\_window\_keyboard\_state\_masks::Add](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksadd)
  - [VectorOfImage\_window\_keyboard\_state\_masks::Items](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksitems)
  - [VectorOfImage\_window\_keyboard\_state\_masks::Keys](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskskeys)
  - [VectorOfImage\_window\_keyboard\_state\_masks::Remove](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksremove)
  - [VectorOfImage\_window\_keyboard\_state\_masks::append](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksappend)
  - [VectorOfImage\_window\_keyboard\_state\_masks::at](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksat)
  - [VectorOfImage\_window\_keyboard\_state\_masks::clear](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksclear)
  - [VectorOfImage\_window\_keyboard\_state\_masks::empty](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksempty)
  - [VectorOfImage\_window\_keyboard\_state\_masks::end](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksend)
  - [VectorOfImage\_window\_keyboard\_state\_masks::get\_Item](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksget%5C_item)
  - [VectorOfImage\_window\_keyboard\_state\_masks::get\_\_NewEnum](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksget%5C_%5C_newenum)
  - [VectorOfImage\_window\_keyboard\_state\_masks::push\_back](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskspush%5C_back)
  - [VectorOfImage\_window\_keyboard\_state\_masks::push\_vector](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskspush%5C_vector)
  - [VectorOfImage\_window\_keyboard\_state\_masks::put\_Item](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksput%5C_item)
  - [VectorOfImage\_window\_keyboard\_state\_masks::size](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskssize)
  - [VectorOfImage\_window\_keyboard\_state\_masks::slice](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksslice)
  - [VectorOfImage\_window\_keyboard\_state\_masks::sort](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskssort)
  - [VectorOfImage\_window\_keyboard\_state\_masks::sort\_variant](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_maskssort%5C_variant)
  - [VectorOfImage\_window\_keyboard\_state\_masks::start](#vectorofimage%5C_window%5C_keyboard%5C_state%5C_masksstart)
- [MapOfStringAndPoint](#mapofstringandpoint)
  - [MapOfStringAndPoint::create](#mapofstringandpointcreate)
  - [MapOfStringAndPoint::Add](#mapofstringandpointadd)
  - [MapOfStringAndPoint::Get](#mapofstringandpointget)
  - [MapOfStringAndPoint::Items](#mapofstringandpointitems)
  - [MapOfStringAndPoint::Keys](#mapofstringandpointkeys)
  - [MapOfStringAndPoint::Remove](#mapofstringandpointremove)
  - [MapOfStringAndPoint::clear](#mapofstringandpointclear)
  - [MapOfStringAndPoint::contains](#mapofstringandpointcontains)
  - [MapOfStringAndPoint::count](#mapofstringandpointcount)
  - [MapOfStringAndPoint::empty](#mapofstringandpointempty)
  - [MapOfStringAndPoint::erase](#mapofstringandpointerase)
  - [MapOfStringAndPoint::get\_Item](#mapofstringandpointget%5C_item)
  - [MapOfStringAndPoint::get\_\_NewEnum](#mapofstringandpointget%5C_%5C_newenum)
  - [MapOfStringAndPoint::has](#mapofstringandpointhas)
  - [MapOfStringAndPoint::max\_size](#mapofstringandpointmax%5C_size)
  - [MapOfStringAndPoint::merge](#mapofstringandpointmerge)
  - [MapOfStringAndPoint::put\_Item](#mapofstringandpointput%5C_item)
  - [MapOfStringAndPoint::size](#mapofstringandpointsize)
- [VectorOfPairOfStringAndPoint](#vectorofpairofstringandpoint)
  - [VectorOfPairOfStringAndPoint.Count](#vectorofpairofstringandpointcount)
  - [VectorOfPairOfStringAndPoint::create](#vectorofpairofstringandpointcreate)
  - [VectorOfPairOfStringAndPoint::Add](#vectorofpairofstringandpointadd)
  - [VectorOfPairOfStringAndPoint::Items](#vectorofpairofstringandpointitems)
  - [VectorOfPairOfStringAndPoint::Keys](#vectorofpairofstringandpointkeys)
  - [VectorOfPairOfStringAndPoint::Remove](#vectorofpairofstringandpointremove)
  - [VectorOfPairOfStringAndPoint::append](#vectorofpairofstringandpointappend)
  - [VectorOfPairOfStringAndPoint::at](#vectorofpairofstringandpointat)
  - [VectorOfPairOfStringAndPoint::clear](#vectorofpairofstringandpointclear)
  - [VectorOfPairOfStringAndPoint::empty](#vectorofpairofstringandpointempty)
  - [VectorOfPairOfStringAndPoint::end](#vectorofpairofstringandpointend)
  - [VectorOfPairOfStringAndPoint::get\_Item](#vectorofpairofstringandpointget%5C_item)
  - [VectorOfPairOfStringAndPoint::get\_\_NewEnum](#vectorofpairofstringandpointget%5C_%5C_newenum)
  - [VectorOfPairOfStringAndPoint::push\_back](#vectorofpairofstringandpointpush%5C_back)
  - [VectorOfPairOfStringAndPoint::push\_vector](#vectorofpairofstringandpointpush%5C_vector)
  - [VectorOfPairOfStringAndPoint::put\_Item](#vectorofpairofstringandpointput%5C_item)
  - [VectorOfPairOfStringAndPoint::size](#vectorofpairofstringandpointsize)
  - [VectorOfPairOfStringAndPoint::slice](#vectorofpairofstringandpointslice)
  - [VectorOfPairOfStringAndPoint::sort](#vectorofpairofstringandpointsort)
  - [VectorOfPairOfStringAndPoint::sort\_variant](#vectorofpairofstringandpointsort%5C_variant)
  - [VectorOfPairOfStringAndPoint::start](#vectorofpairofstringandpointstart)
- [VectorOfImage\_dataset\_metadata\_box](#vectorofimage%5C_dataset%5C_metadata%5C_box)
  - [VectorOfImage\_dataset\_metadata\_box.Count](#vectorofimage%5C_dataset%5C_metadata%5C_boxcount)
  - [VectorOfImage\_dataset\_metadata\_box::create](#vectorofimage%5C_dataset%5C_metadata%5C_boxcreate)
  - [VectorOfImage\_dataset\_metadata\_box::Add](#vectorofimage%5C_dataset%5C_metadata%5C_boxadd)
  - [VectorOfImage\_dataset\_metadata\_box::Items](#vectorofimage%5C_dataset%5C_metadata%5C_boxitems)
  - [VectorOfImage\_dataset\_metadata\_box::Keys](#vectorofimage%5C_dataset%5C_metadata%5C_boxkeys)
  - [VectorOfImage\_dataset\_metadata\_box::Remove](#vectorofimage%5C_dataset%5C_metadata%5C_boxremove)
  - [VectorOfImage\_dataset\_metadata\_box::append](#vectorofimage%5C_dataset%5C_metadata%5C_boxappend)
  - [VectorOfImage\_dataset\_metadata\_box::at](#vectorofimage%5C_dataset%5C_metadata%5C_boxat)
  - [VectorOfImage\_dataset\_metadata\_box::clear](#vectorofimage%5C_dataset%5C_metadata%5C_boxclear)
  - [VectorOfImage\_dataset\_metadata\_box::empty](#vectorofimage%5C_dataset%5C_metadata%5C_boxempty)
  - [VectorOfImage\_dataset\_metadata\_box::end](#vectorofimage%5C_dataset%5C_metadata%5C_boxend)
  - [VectorOfImage\_dataset\_metadata\_box::get\_Item](#vectorofimage%5C_dataset%5C_metadata%5C_boxget%5C_item)
  - [VectorOfImage\_dataset\_metadata\_box::get\_\_NewEnum](#vectorofimage%5C_dataset%5C_metadata%5C_boxget%5C_%5C_newenum)
  - [VectorOfImage\_dataset\_metadata\_box::push\_back](#vectorofimage%5C_dataset%5C_metadata%5C_boxpush%5C_back)
  - [VectorOfImage\_dataset\_metadata\_box::push\_vector](#vectorofimage%5C_dataset%5C_metadata%5C_boxpush%5C_vector)
  - [VectorOfImage\_dataset\_metadata\_box::put\_Item](#vectorofimage%5C_dataset%5C_metadata%5C_boxput%5C_item)
  - [VectorOfImage\_dataset\_metadata\_box::size](#vectorofimage%5C_dataset%5C_metadata%5C_boxsize)
  - [VectorOfImage\_dataset\_metadata\_box::slice](#vectorofimage%5C_dataset%5C_metadata%5C_boxslice)
  - [VectorOfImage\_dataset\_metadata\_box::sort](#vectorofimage%5C_dataset%5C_metadata%5C_boxsort)
  - [VectorOfImage\_dataset\_metadata\_box::sort\_variant](#vectorofimage%5C_dataset%5C_metadata%5C_boxsort%5C_variant)
  - [VectorOfImage\_dataset\_metadata\_box::start](#vectorofimage%5C_dataset%5C_metadata%5C_boxstart)
- [VectorOfImage\_dataset\_metadata\_image](#vectorofimage%5C_dataset%5C_metadata%5C_image)
  - [VectorOfImage\_dataset\_metadata\_image.Count](#vectorofimage%5C_dataset%5C_metadata%5C_imagecount)
  - [VectorOfImage\_dataset\_metadata\_image::create](#vectorofimage%5C_dataset%5C_metadata%5C_imagecreate)
  - [VectorOfImage\_dataset\_metadata\_image::Add](#vectorofimage%5C_dataset%5C_metadata%5C_imageadd)
  - [VectorOfImage\_dataset\_metadata\_image::Items](#vectorofimage%5C_dataset%5C_metadata%5C_imageitems)
  - [VectorOfImage\_dataset\_metadata\_image::Keys](#vectorofimage%5C_dataset%5C_metadata%5C_imagekeys)
  - [VectorOfImage\_dataset\_metadata\_image::Remove](#vectorofimage%5C_dataset%5C_metadata%5C_imageremove)
  - [VectorOfImage\_dataset\_metadata\_image::append](#vectorofimage%5C_dataset%5C_metadata%5C_imageappend)
  - [VectorOfImage\_dataset\_metadata\_image::at](#vectorofimage%5C_dataset%5C_metadata%5C_imageat)
  - [VectorOfImage\_dataset\_metadata\_image::clear](#vectorofimage%5C_dataset%5C_metadata%5C_imageclear)
  - [VectorOfImage\_dataset\_metadata\_image::empty](#vectorofimage%5C_dataset%5C_metadata%5C_imageempty)
  - [VectorOfImage\_dataset\_metadata\_image::end](#vectorofimage%5C_dataset%5C_metadata%5C_imageend)
  - [VectorOfImage\_dataset\_metadata\_image::get\_Item](#vectorofimage%5C_dataset%5C_metadata%5C_imageget%5C_item)
  - [VectorOfImage\_dataset\_metadata\_image::get\_\_NewEnum](#vectorofimage%5C_dataset%5C_metadata%5C_imageget%5C_%5C_newenum)
  - [VectorOfImage\_dataset\_metadata\_image::push\_back](#vectorofimage%5C_dataset%5C_metadata%5C_imagepush%5C_back)
  - [VectorOfImage\_dataset\_metadata\_image::push\_vector](#vectorofimage%5C_dataset%5C_metadata%5C_imagepush%5C_vector)
  - [VectorOfImage\_dataset\_metadata\_image::put\_Item](#vectorofimage%5C_dataset%5C_metadata%5C_imageput%5C_item)
  - [VectorOfImage\_dataset\_metadata\_image::size](#vectorofimage%5C_dataset%5C_metadata%5C_imagesize)
  - [VectorOfImage\_dataset\_metadata\_image::slice](#vectorofimage%5C_dataset%5C_metadata%5C_imageslice)
  - [VectorOfImage\_dataset\_metadata\_image::sort](#vectorofimage%5C_dataset%5C_metadata%5C_imagesort)
  - [VectorOfImage\_dataset\_metadata\_image::sort\_variant](#vectorofimage%5C_dataset%5C_metadata%5C_imagesort%5C_variant)
  - [VectorOfImage\_dataset\_metadata\_image::start](#vectorofimage%5C_dataset%5C_metadata%5C_imagestart)
- [VectorOfSize\_t](#vectorofsize%5C_t)
  - [VectorOfSize\_t.Count](#vectorofsize%5C_tcount)
  - [VectorOfSize\_t::create](#vectorofsize%5C_tcreate)
  - [VectorOfSize\_t::Add](#vectorofsize%5C_tadd)
  - [VectorOfSize\_t::Items](#vectorofsize%5C_titems)
  - [VectorOfSize\_t::Keys](#vectorofsize%5C_tkeys)
  - [VectorOfSize\_t::Remove](#vectorofsize%5C_tremove)
  - [VectorOfSize\_t::append](#vectorofsize%5C_tappend)
  - [VectorOfSize\_t::at](#vectorofsize%5C_tat)
  - [VectorOfSize\_t::clear](#vectorofsize%5C_tclear)
  - [VectorOfSize\_t::empty](#vectorofsize%5C_tempty)
  - [VectorOfSize\_t::end](#vectorofsize%5C_tend)
  - [VectorOfSize\_t::get\_Item](#vectorofsize%5C_tget%5C_item)
  - [VectorOfSize\_t::get\_\_NewEnum](#vectorofsize%5C_tget%5C_%5C_newenum)
  - [VectorOfSize\_t::push\_back](#vectorofsize%5C_tpush%5C_back)
  - [VectorOfSize\_t::push\_vector](#vectorofsize%5C_tpush%5C_vector)
  - [VectorOfSize\_t::put\_Item](#vectorofsize%5C_tput%5C_item)
  - [VectorOfSize\_t::size](#vectorofsize%5C_tsize)
  - [VectorOfSize\_t::slice](#vectorofsize%5C_tslice)
  - [VectorOfSize\_t::sort](#vectorofsize%5C_tsort)
  - [VectorOfSize\_t::sort\_variant](#vectorofsize%5C_tsort%5C_variant)
  - [VectorOfSize\_t::start](#vectorofsize%5C_tstart)
- [VectorOfRange](#vectorofrange)
  - [VectorOfRange.Count](#vectorofrangecount)
  - [VectorOfRange::create](#vectorofrangecreate)
  - [VectorOfRange::Add](#vectorofrangeadd)
  - [VectorOfRange::Items](#vectorofrangeitems)
  - [VectorOfRange::Keys](#vectorofrangekeys)
  - [VectorOfRange::Remove](#vectorofrangeremove)
  - [VectorOfRange::append](#vectorofrangeappend)
  - [VectorOfRange::at](#vectorofrangeat)
  - [VectorOfRange::clear](#vectorofrangeclear)
  - [VectorOfRange::empty](#vectorofrangeempty)
  - [VectorOfRange::end](#vectorofrangeend)
  - [VectorOfRange::get\_Item](#vectorofrangeget%5C_item)
  - [VectorOfRange::get\_\_NewEnum](#vectorofrangeget%5C_%5C_newenum)
  - [VectorOfRange::push\_back](#vectorofrangepush%5C_back)
  - [VectorOfRange::push\_vector](#vectorofrangepush%5C_vector)
  - [VectorOfRange::put\_Item](#vectorofrangeput%5C_item)
  - [VectorOfRange::size](#vectorofrangesize)
  - [VectorOfRange::slice](#vectorofrangeslice)
  - [VectorOfRange::sort](#vectorofrangesort)
  - [VectorOfRange::sort\_variant](#vectorofrangesort%5C_variant)
  - [VectorOfRange::start](#vectorofrangestart)
- [VectorOfFloat](#vectoroffloat)
  - [VectorOfFloat.Count](#vectoroffloatcount)
  - [VectorOfFloat::create](#vectoroffloatcreate)
  - [VectorOfFloat::Add](#vectoroffloatadd)
  - [VectorOfFloat::Items](#vectoroffloatitems)
  - [VectorOfFloat::Keys](#vectoroffloatkeys)
  - [VectorOfFloat::Remove](#vectoroffloatremove)
  - [VectorOfFloat::append](#vectoroffloatappend)
  - [VectorOfFloat::at](#vectoroffloatat)
  - [VectorOfFloat::clear](#vectoroffloatclear)
  - [VectorOfFloat::empty](#vectoroffloatempty)
  - [VectorOfFloat::end](#vectoroffloatend)
  - [VectorOfFloat::get\_Item](#vectoroffloatget%5C_item)
  - [VectorOfFloat::get\_\_NewEnum](#vectoroffloatget%5C_%5C_newenum)
  - [VectorOfFloat::push\_back](#vectoroffloatpush%5C_back)
  - [VectorOfFloat::push\_vector](#vectoroffloatpush%5C_vector)
  - [VectorOfFloat::put\_Item](#vectoroffloatput%5C_item)
  - [VectorOfFloat::size](#vectoroffloatsize)
  - [VectorOfFloat::slice](#vectoroffloatslice)
  - [VectorOfFloat::sort](#vectoroffloatsort)
  - [VectorOfFloat::sort\_variant](#vectoroffloatsort%5C_variant)
  - [VectorOfFloat::start](#vectoroffloatstart)
- [VectorOfVec2b](#vectorofvec2b)
  - [VectorOfVec2b.Count](#vectorofvec2bcount)
  - [VectorOfVec2b::create](#vectorofvec2bcreate)
  - [VectorOfVec2b::Add](#vectorofvec2badd)
  - [VectorOfVec2b::Items](#vectorofvec2bitems)
  - [VectorOfVec2b::Keys](#vectorofvec2bkeys)
  - [VectorOfVec2b::Remove](#vectorofvec2bremove)
  - [VectorOfVec2b::append](#vectorofvec2bappend)
  - [VectorOfVec2b::at](#vectorofvec2bat)
  - [VectorOfVec2b::clear](#vectorofvec2bclear)
  - [VectorOfVec2b::empty](#vectorofvec2bempty)
  - [VectorOfVec2b::end](#vectorofvec2bend)
  - [VectorOfVec2b::get\_Item](#vectorofvec2bget%5C_item)
  - [VectorOfVec2b::get\_\_NewEnum](#vectorofvec2bget%5C_%5C_newenum)
  - [VectorOfVec2b::push\_back](#vectorofvec2bpush%5C_back)
  - [VectorOfVec2b::push\_vector](#vectorofvec2bpush%5C_vector)
  - [VectorOfVec2b::put\_Item](#vectorofvec2bput%5C_item)
  - [VectorOfVec2b::size](#vectorofvec2bsize)
  - [VectorOfVec2b::slice](#vectorofvec2bslice)
  - [VectorOfVec2b::sort](#vectorofvec2bsort)
  - [VectorOfVec2b::sort\_variant](#vectorofvec2bsort%5C_variant)
  - [VectorOfVec2b::start](#vectorofvec2bstart)
- [VectorOfVec3b](#vectorofvec3b)
  - [VectorOfVec3b.Count](#vectorofvec3bcount)
  - [VectorOfVec3b::create](#vectorofvec3bcreate)
  - [VectorOfVec3b::Add](#vectorofvec3badd)
  - [VectorOfVec3b::Items](#vectorofvec3bitems)
  - [VectorOfVec3b::Keys](#vectorofvec3bkeys)
  - [VectorOfVec3b::Remove](#vectorofvec3bremove)
  - [VectorOfVec3b::append](#vectorofvec3bappend)
  - [VectorOfVec3b::at](#vectorofvec3bat)
  - [VectorOfVec3b::clear](#vectorofvec3bclear)
  - [VectorOfVec3b::empty](#vectorofvec3bempty)
  - [VectorOfVec3b::end](#vectorofvec3bend)
  - [VectorOfVec3b::get\_Item](#vectorofvec3bget%5C_item)
  - [VectorOfVec3b::get\_\_NewEnum](#vectorofvec3bget%5C_%5C_newenum)
  - [VectorOfVec3b::push\_back](#vectorofvec3bpush%5C_back)
  - [VectorOfVec3b::push\_vector](#vectorofvec3bpush%5C_vector)
  - [VectorOfVec3b::put\_Item](#vectorofvec3bput%5C_item)
  - [VectorOfVec3b::size](#vectorofvec3bsize)
  - [VectorOfVec3b::slice](#vectorofvec3bslice)
  - [VectorOfVec3b::sort](#vectorofvec3bsort)
  - [VectorOfVec3b::sort\_variant](#vectorofvec3bsort%5C_variant)
  - [VectorOfVec3b::start](#vectorofvec3bstart)
- [VectorOfVec4b](#vectorofvec4b)
  - [VectorOfVec4b.Count](#vectorofvec4bcount)
  - [VectorOfVec4b::create](#vectorofvec4bcreate)
  - [VectorOfVec4b::Add](#vectorofvec4badd)
  - [VectorOfVec4b::Items](#vectorofvec4bitems)
  - [VectorOfVec4b::Keys](#vectorofvec4bkeys)
  - [VectorOfVec4b::Remove](#vectorofvec4bremove)
  - [VectorOfVec4b::append](#vectorofvec4bappend)
  - [VectorOfVec4b::at](#vectorofvec4bat)
  - [VectorOfVec4b::clear](#vectorofvec4bclear)
  - [VectorOfVec4b::empty](#vectorofvec4bempty)
  - [VectorOfVec4b::end](#vectorofvec4bend)
  - [VectorOfVec4b::get\_Item](#vectorofvec4bget%5C_item)
  - [VectorOfVec4b::get\_\_NewEnum](#vectorofvec4bget%5C_%5C_newenum)
  - [VectorOfVec4b::push\_back](#vectorofvec4bpush%5C_back)
  - [VectorOfVec4b::push\_vector](#vectorofvec4bpush%5C_vector)
  - [VectorOfVec4b::put\_Item](#vectorofvec4bput%5C_item)
  - [VectorOfVec4b::size](#vectorofvec4bsize)
  - [VectorOfVec4b::slice](#vectorofvec4bslice)
  - [VectorOfVec4b::sort](#vectorofvec4bsort)
  - [VectorOfVec4b::sort\_variant](#vectorofvec4bsort%5C_variant)
  - [VectorOfVec4b::start](#vectorofvec4bstart)
- [VectorOfVec2s](#vectorofvec2s)
  - [VectorOfVec2s.Count](#vectorofvec2scount)
  - [VectorOfVec2s::create](#vectorofvec2screate)
  - [VectorOfVec2s::Add](#vectorofvec2sadd)
  - [VectorOfVec2s::Items](#vectorofvec2sitems)
  - [VectorOfVec2s::Keys](#vectorofvec2skeys)
  - [VectorOfVec2s::Remove](#vectorofvec2sremove)
  - [VectorOfVec2s::append](#vectorofvec2sappend)
  - [VectorOfVec2s::at](#vectorofvec2sat)
  - [VectorOfVec2s::clear](#vectorofvec2sclear)
  - [VectorOfVec2s::empty](#vectorofvec2sempty)
  - [VectorOfVec2s::end](#vectorofvec2send)
  - [VectorOfVec2s::get\_Item](#vectorofvec2sget%5C_item)
  - [VectorOfVec2s::get\_\_NewEnum](#vectorofvec2sget%5C_%5C_newenum)
  - [VectorOfVec2s::push\_back](#vectorofvec2spush%5C_back)
  - [VectorOfVec2s::push\_vector](#vectorofvec2spush%5C_vector)
  - [VectorOfVec2s::put\_Item](#vectorofvec2sput%5C_item)
  - [VectorOfVec2s::size](#vectorofvec2ssize)
  - [VectorOfVec2s::slice](#vectorofvec2sslice)
  - [VectorOfVec2s::sort](#vectorofvec2ssort)
  - [VectorOfVec2s::sort\_variant](#vectorofvec2ssort%5C_variant)
  - [VectorOfVec2s::start](#vectorofvec2sstart)
- [VectorOfVec3s](#vectorofvec3s)
  - [VectorOfVec3s.Count](#vectorofvec3scount)
  - [VectorOfVec3s::create](#vectorofvec3screate)
  - [VectorOfVec3s::Add](#vectorofvec3sadd)
  - [VectorOfVec3s::Items](#vectorofvec3sitems)
  - [VectorOfVec3s::Keys](#vectorofvec3skeys)
  - [VectorOfVec3s::Remove](#vectorofvec3sremove)
  - [VectorOfVec3s::append](#vectorofvec3sappend)
  - [VectorOfVec3s::at](#vectorofvec3sat)
  - [VectorOfVec3s::clear](#vectorofvec3sclear)
  - [VectorOfVec3s::empty](#vectorofvec3sempty)
  - [VectorOfVec3s::end](#vectorofvec3send)
  - [VectorOfVec3s::get\_Item](#vectorofvec3sget%5C_item)
  - [VectorOfVec3s::get\_\_NewEnum](#vectorofvec3sget%5C_%5C_newenum)
  - [VectorOfVec3s::push\_back](#vectorofvec3spush%5C_back)
  - [VectorOfVec3s::push\_vector](#vectorofvec3spush%5C_vector)
  - [VectorOfVec3s::put\_Item](#vectorofvec3sput%5C_item)
  - [VectorOfVec3s::size](#vectorofvec3ssize)
  - [VectorOfVec3s::slice](#vectorofvec3sslice)
  - [VectorOfVec3s::sort](#vectorofvec3ssort)
  - [VectorOfVec3s::sort\_variant](#vectorofvec3ssort%5C_variant)
  - [VectorOfVec3s::start](#vectorofvec3sstart)
- [VectorOfVec4s](#vectorofvec4s)
  - [VectorOfVec4s.Count](#vectorofvec4scount)
  - [VectorOfVec4s::create](#vectorofvec4screate)
  - [VectorOfVec4s::Add](#vectorofvec4sadd)
  - [VectorOfVec4s::Items](#vectorofvec4sitems)
  - [VectorOfVec4s::Keys](#vectorofvec4skeys)
  - [VectorOfVec4s::Remove](#vectorofvec4sremove)
  - [VectorOfVec4s::append](#vectorofvec4sappend)
  - [VectorOfVec4s::at](#vectorofvec4sat)
  - [VectorOfVec4s::clear](#vectorofvec4sclear)
  - [VectorOfVec4s::empty](#vectorofvec4sempty)
  - [VectorOfVec4s::end](#vectorofvec4send)
  - [VectorOfVec4s::get\_Item](#vectorofvec4sget%5C_item)
  - [VectorOfVec4s::get\_\_NewEnum](#vectorofvec4sget%5C_%5C_newenum)
  - [VectorOfVec4s::push\_back](#vectorofvec4spush%5C_back)
  - [VectorOfVec4s::push\_vector](#vectorofvec4spush%5C_vector)
  - [VectorOfVec4s::put\_Item](#vectorofvec4sput%5C_item)
  - [VectorOfVec4s::size](#vectorofvec4ssize)
  - [VectorOfVec4s::slice](#vectorofvec4sslice)
  - [VectorOfVec4s::sort](#vectorofvec4ssort)
  - [VectorOfVec4s::sort\_variant](#vectorofvec4ssort%5C_variant)
  - [VectorOfVec4s::start](#vectorofvec4sstart)
- [VectorOfVec2w](#vectorofvec2w)
  - [VectorOfVec2w.Count](#vectorofvec2wcount)
  - [VectorOfVec2w::create](#vectorofvec2wcreate)
  - [VectorOfVec2w::Add](#vectorofvec2wadd)
  - [VectorOfVec2w::Items](#vectorofvec2witems)
  - [VectorOfVec2w::Keys](#vectorofvec2wkeys)
  - [VectorOfVec2w::Remove](#vectorofvec2wremove)
  - [VectorOfVec2w::append](#vectorofvec2wappend)
  - [VectorOfVec2w::at](#vectorofvec2wat)
  - [VectorOfVec2w::clear](#vectorofvec2wclear)
  - [VectorOfVec2w::empty](#vectorofvec2wempty)
  - [VectorOfVec2w::end](#vectorofvec2wend)
  - [VectorOfVec2w::get\_Item](#vectorofvec2wget%5C_item)
  - [VectorOfVec2w::get\_\_NewEnum](#vectorofvec2wget%5C_%5C_newenum)
  - [VectorOfVec2w::push\_back](#vectorofvec2wpush%5C_back)
  - [VectorOfVec2w::push\_vector](#vectorofvec2wpush%5C_vector)
  - [VectorOfVec2w::put\_Item](#vectorofvec2wput%5C_item)
  - [VectorOfVec2w::size](#vectorofvec2wsize)
  - [VectorOfVec2w::slice](#vectorofvec2wslice)
  - [VectorOfVec2w::sort](#vectorofvec2wsort)
  - [VectorOfVec2w::sort\_variant](#vectorofvec2wsort%5C_variant)
  - [VectorOfVec2w::start](#vectorofvec2wstart)
- [VectorOfVec3w](#vectorofvec3w)
  - [VectorOfVec3w.Count](#vectorofvec3wcount)
  - [VectorOfVec3w::create](#vectorofvec3wcreate)
  - [VectorOfVec3w::Add](#vectorofvec3wadd)
  - [VectorOfVec3w::Items](#vectorofvec3witems)
  - [VectorOfVec3w::Keys](#vectorofvec3wkeys)
  - [VectorOfVec3w::Remove](#vectorofvec3wremove)
  - [VectorOfVec3w::append](#vectorofvec3wappend)
  - [VectorOfVec3w::at](#vectorofvec3wat)
  - [VectorOfVec3w::clear](#vectorofvec3wclear)
  - [VectorOfVec3w::empty](#vectorofvec3wempty)
  - [VectorOfVec3w::end](#vectorofvec3wend)
  - [VectorOfVec3w::get\_Item](#vectorofvec3wget%5C_item)
  - [VectorOfVec3w::get\_\_NewEnum](#vectorofvec3wget%5C_%5C_newenum)
  - [VectorOfVec3w::push\_back](#vectorofvec3wpush%5C_back)
  - [VectorOfVec3w::push\_vector](#vectorofvec3wpush%5C_vector)
  - [VectorOfVec3w::put\_Item](#vectorofvec3wput%5C_item)
  - [VectorOfVec3w::size](#vectorofvec3wsize)
  - [VectorOfVec3w::slice](#vectorofvec3wslice)
  - [VectorOfVec3w::sort](#vectorofvec3wsort)
  - [VectorOfVec3w::sort\_variant](#vectorofvec3wsort%5C_variant)
  - [VectorOfVec3w::start](#vectorofvec3wstart)
- [VectorOfVec4w](#vectorofvec4w)
  - [VectorOfVec4w.Count](#vectorofvec4wcount)
  - [VectorOfVec4w::create](#vectorofvec4wcreate)
  - [VectorOfVec4w::Add](#vectorofvec4wadd)
  - [VectorOfVec4w::Items](#vectorofvec4witems)
  - [VectorOfVec4w::Keys](#vectorofvec4wkeys)
  - [VectorOfVec4w::Remove](#vectorofvec4wremove)
  - [VectorOfVec4w::append](#vectorofvec4wappend)
  - [VectorOfVec4w::at](#vectorofvec4wat)
  - [VectorOfVec4w::clear](#vectorofvec4wclear)
  - [VectorOfVec4w::empty](#vectorofvec4wempty)
  - [VectorOfVec4w::end](#vectorofvec4wend)
  - [VectorOfVec4w::get\_Item](#vectorofvec4wget%5C_item)
  - [VectorOfVec4w::get\_\_NewEnum](#vectorofvec4wget%5C_%5C_newenum)
  - [VectorOfVec4w::push\_back](#vectorofvec4wpush%5C_back)
  - [VectorOfVec4w::push\_vector](#vectorofvec4wpush%5C_vector)
  - [VectorOfVec4w::put\_Item](#vectorofvec4wput%5C_item)
  - [VectorOfVec4w::size](#vectorofvec4wsize)
  - [VectorOfVec4w::slice](#vectorofvec4wslice)
  - [VectorOfVec4w::sort](#vectorofvec4wsort)
  - [VectorOfVec4w::sort\_variant](#vectorofvec4wsort%5C_variant)
  - [VectorOfVec4w::start](#vectorofvec4wstart)
- [VectorOfVec2i](#vectorofvec2i)
  - [VectorOfVec2i.Count](#vectorofvec2icount)
  - [VectorOfVec2i::create](#vectorofvec2icreate)
  - [VectorOfVec2i::Add](#vectorofvec2iadd)
  - [VectorOfVec2i::Items](#vectorofvec2iitems)
  - [VectorOfVec2i::Keys](#vectorofvec2ikeys)
  - [VectorOfVec2i::Remove](#vectorofvec2iremove)
  - [VectorOfVec2i::append](#vectorofvec2iappend)
  - [VectorOfVec2i::at](#vectorofvec2iat)
  - [VectorOfVec2i::clear](#vectorofvec2iclear)
  - [VectorOfVec2i::empty](#vectorofvec2iempty)
  - [VectorOfVec2i::end](#vectorofvec2iend)
  - [VectorOfVec2i::get\_Item](#vectorofvec2iget%5C_item)
  - [VectorOfVec2i::get\_\_NewEnum](#vectorofvec2iget%5C_%5C_newenum)
  - [VectorOfVec2i::push\_back](#vectorofvec2ipush%5C_back)
  - [VectorOfVec2i::push\_vector](#vectorofvec2ipush%5C_vector)
  - [VectorOfVec2i::put\_Item](#vectorofvec2iput%5C_item)
  - [VectorOfVec2i::size](#vectorofvec2isize)
  - [VectorOfVec2i::slice](#vectorofvec2islice)
  - [VectorOfVec2i::sort](#vectorofvec2isort)
  - [VectorOfVec2i::sort\_variant](#vectorofvec2isort%5C_variant)
  - [VectorOfVec2i::start](#vectorofvec2istart)
- [VectorOfVec3i](#vectorofvec3i)
  - [VectorOfVec3i.Count](#vectorofvec3icount)
  - [VectorOfVec3i::create](#vectorofvec3icreate)
  - [VectorOfVec3i::Add](#vectorofvec3iadd)
  - [VectorOfVec3i::Items](#vectorofvec3iitems)
  - [VectorOfVec3i::Keys](#vectorofvec3ikeys)
  - [VectorOfVec3i::Remove](#vectorofvec3iremove)
  - [VectorOfVec3i::append](#vectorofvec3iappend)
  - [VectorOfVec3i::at](#vectorofvec3iat)
  - [VectorOfVec3i::clear](#vectorofvec3iclear)
  - [VectorOfVec3i::empty](#vectorofvec3iempty)
  - [VectorOfVec3i::end](#vectorofvec3iend)
  - [VectorOfVec3i::get\_Item](#vectorofvec3iget%5C_item)
  - [VectorOfVec3i::get\_\_NewEnum](#vectorofvec3iget%5C_%5C_newenum)
  - [VectorOfVec3i::push\_back](#vectorofvec3ipush%5C_back)
  - [VectorOfVec3i::push\_vector](#vectorofvec3ipush%5C_vector)
  - [VectorOfVec3i::put\_Item](#vectorofvec3iput%5C_item)
  - [VectorOfVec3i::size](#vectorofvec3isize)
  - [VectorOfVec3i::slice](#vectorofvec3islice)
  - [VectorOfVec3i::sort](#vectorofvec3isort)
  - [VectorOfVec3i::sort\_variant](#vectorofvec3isort%5C_variant)
  - [VectorOfVec3i::start](#vectorofvec3istart)
- [VectorOfVec4i](#vectorofvec4i)
  - [VectorOfVec4i.Count](#vectorofvec4icount)
  - [VectorOfVec4i::create](#vectorofvec4icreate)
  - [VectorOfVec4i::Add](#vectorofvec4iadd)
  - [VectorOfVec4i::Items](#vectorofvec4iitems)
  - [VectorOfVec4i::Keys](#vectorofvec4ikeys)
  - [VectorOfVec4i::Remove](#vectorofvec4iremove)
  - [VectorOfVec4i::append](#vectorofvec4iappend)
  - [VectorOfVec4i::at](#vectorofvec4iat)
  - [VectorOfVec4i::clear](#vectorofvec4iclear)
  - [VectorOfVec4i::empty](#vectorofvec4iempty)
  - [VectorOfVec4i::end](#vectorofvec4iend)
  - [VectorOfVec4i::get\_Item](#vectorofvec4iget%5C_item)
  - [VectorOfVec4i::get\_\_NewEnum](#vectorofvec4iget%5C_%5C_newenum)
  - [VectorOfVec4i::push\_back](#vectorofvec4ipush%5C_back)
  - [VectorOfVec4i::push\_vector](#vectorofvec4ipush%5C_vector)
  - [VectorOfVec4i::put\_Item](#vectorofvec4iput%5C_item)
  - [VectorOfVec4i::size](#vectorofvec4isize)
  - [VectorOfVec4i::slice](#vectorofvec4islice)
  - [VectorOfVec4i::sort](#vectorofvec4isort)
  - [VectorOfVec4i::sort\_variant](#vectorofvec4isort%5C_variant)
  - [VectorOfVec4i::start](#vectorofvec4istart)
- [VectorOfVec6i](#vectorofvec6i)
  - [VectorOfVec6i.Count](#vectorofvec6icount)
  - [VectorOfVec6i::create](#vectorofvec6icreate)
  - [VectorOfVec6i::Add](#vectorofvec6iadd)
  - [VectorOfVec6i::Items](#vectorofvec6iitems)
  - [VectorOfVec6i::Keys](#vectorofvec6ikeys)
  - [VectorOfVec6i::Remove](#vectorofvec6iremove)
  - [VectorOfVec6i::append](#vectorofvec6iappend)
  - [VectorOfVec6i::at](#vectorofvec6iat)
  - [VectorOfVec6i::clear](#vectorofvec6iclear)
  - [VectorOfVec6i::empty](#vectorofvec6iempty)
  - [VectorOfVec6i::end](#vectorofvec6iend)
  - [VectorOfVec6i::get\_Item](#vectorofvec6iget%5C_item)
  - [VectorOfVec6i::get\_\_NewEnum](#vectorofvec6iget%5C_%5C_newenum)
  - [VectorOfVec6i::push\_back](#vectorofvec6ipush%5C_back)
  - [VectorOfVec6i::push\_vector](#vectorofvec6ipush%5C_vector)
  - [VectorOfVec6i::put\_Item](#vectorofvec6iput%5C_item)
  - [VectorOfVec6i::size](#vectorofvec6isize)
  - [VectorOfVec6i::slice](#vectorofvec6islice)
  - [VectorOfVec6i::sort](#vectorofvec6isort)
  - [VectorOfVec6i::sort\_variant](#vectorofvec6isort%5C_variant)
  - [VectorOfVec6i::start](#vectorofvec6istart)
- [VectorOfVec8i](#vectorofvec8i)
  - [VectorOfVec8i.Count](#vectorofvec8icount)
  - [VectorOfVec8i::create](#vectorofvec8icreate)
  - [VectorOfVec8i::Add](#vectorofvec8iadd)
  - [VectorOfVec8i::Items](#vectorofvec8iitems)
  - [VectorOfVec8i::Keys](#vectorofvec8ikeys)
  - [VectorOfVec8i::Remove](#vectorofvec8iremove)
  - [VectorOfVec8i::append](#vectorofvec8iappend)
  - [VectorOfVec8i::at](#vectorofvec8iat)
  - [VectorOfVec8i::clear](#vectorofvec8iclear)
  - [VectorOfVec8i::empty](#vectorofvec8iempty)
  - [VectorOfVec8i::end](#vectorofvec8iend)
  - [VectorOfVec8i::get\_Item](#vectorofvec8iget%5C_item)
  - [VectorOfVec8i::get\_\_NewEnum](#vectorofvec8iget%5C_%5C_newenum)
  - [VectorOfVec8i::push\_back](#vectorofvec8ipush%5C_back)
  - [VectorOfVec8i::push\_vector](#vectorofvec8ipush%5C_vector)
  - [VectorOfVec8i::put\_Item](#vectorofvec8iput%5C_item)
  - [VectorOfVec8i::size](#vectorofvec8isize)
  - [VectorOfVec8i::slice](#vectorofvec8islice)
  - [VectorOfVec8i::sort](#vectorofvec8isort)
  - [VectorOfVec8i::sort\_variant](#vectorofvec8isort%5C_variant)
  - [VectorOfVec8i::start](#vectorofvec8istart)
- [VectorOfVec2f](#vectorofvec2f)
  - [VectorOfVec2f.Count](#vectorofvec2fcount)
  - [VectorOfVec2f::create](#vectorofvec2fcreate)
  - [VectorOfVec2f::Add](#vectorofvec2fadd)
  - [VectorOfVec2f::Items](#vectorofvec2fitems)
  - [VectorOfVec2f::Keys](#vectorofvec2fkeys)
  - [VectorOfVec2f::Remove](#vectorofvec2fremove)
  - [VectorOfVec2f::append](#vectorofvec2fappend)
  - [VectorOfVec2f::at](#vectorofvec2fat)
  - [VectorOfVec2f::clear](#vectorofvec2fclear)
  - [VectorOfVec2f::empty](#vectorofvec2fempty)
  - [VectorOfVec2f::end](#vectorofvec2fend)
  - [VectorOfVec2f::get\_Item](#vectorofvec2fget%5C_item)
  - [VectorOfVec2f::get\_\_NewEnum](#vectorofvec2fget%5C_%5C_newenum)
  - [VectorOfVec2f::push\_back](#vectorofvec2fpush%5C_back)
  - [VectorOfVec2f::push\_vector](#vectorofvec2fpush%5C_vector)
  - [VectorOfVec2f::put\_Item](#vectorofvec2fput%5C_item)
  - [VectorOfVec2f::size](#vectorofvec2fsize)
  - [VectorOfVec2f::slice](#vectorofvec2fslice)
  - [VectorOfVec2f::sort](#vectorofvec2fsort)
  - [VectorOfVec2f::sort\_variant](#vectorofvec2fsort%5C_variant)
  - [VectorOfVec2f::start](#vectorofvec2fstart)
- [VectorOfVec3f](#vectorofvec3f)
  - [VectorOfVec3f.Count](#vectorofvec3fcount)
  - [VectorOfVec3f::create](#vectorofvec3fcreate)
  - [VectorOfVec3f::Add](#vectorofvec3fadd)
  - [VectorOfVec3f::Items](#vectorofvec3fitems)
  - [VectorOfVec3f::Keys](#vectorofvec3fkeys)
  - [VectorOfVec3f::Remove](#vectorofvec3fremove)
  - [VectorOfVec3f::append](#vectorofvec3fappend)
  - [VectorOfVec3f::at](#vectorofvec3fat)
  - [VectorOfVec3f::clear](#vectorofvec3fclear)
  - [VectorOfVec3f::empty](#vectorofvec3fempty)
  - [VectorOfVec3f::end](#vectorofvec3fend)
  - [VectorOfVec3f::get\_Item](#vectorofvec3fget%5C_item)
  - [VectorOfVec3f::get\_\_NewEnum](#vectorofvec3fget%5C_%5C_newenum)
  - [VectorOfVec3f::push\_back](#vectorofvec3fpush%5C_back)
  - [VectorOfVec3f::push\_vector](#vectorofvec3fpush%5C_vector)
  - [VectorOfVec3f::put\_Item](#vectorofvec3fput%5C_item)
  - [VectorOfVec3f::size](#vectorofvec3fsize)
  - [VectorOfVec3f::slice](#vectorofvec3fslice)
  - [VectorOfVec3f::sort](#vectorofvec3fsort)
  - [VectorOfVec3f::sort\_variant](#vectorofvec3fsort%5C_variant)
  - [VectorOfVec3f::start](#vectorofvec3fstart)
- [VectorOfVec4f](#vectorofvec4f)
  - [VectorOfVec4f.Count](#vectorofvec4fcount)
  - [VectorOfVec4f::create](#vectorofvec4fcreate)
  - [VectorOfVec4f::Add](#vectorofvec4fadd)
  - [VectorOfVec4f::Items](#vectorofvec4fitems)
  - [VectorOfVec4f::Keys](#vectorofvec4fkeys)
  - [VectorOfVec4f::Remove](#vectorofvec4fremove)
  - [VectorOfVec4f::append](#vectorofvec4fappend)
  - [VectorOfVec4f::at](#vectorofvec4fat)
  - [VectorOfVec4f::clear](#vectorofvec4fclear)
  - [VectorOfVec4f::empty](#vectorofvec4fempty)
  - [VectorOfVec4f::end](#vectorofvec4fend)
  - [VectorOfVec4f::get\_Item](#vectorofvec4fget%5C_item)
  - [VectorOfVec4f::get\_\_NewEnum](#vectorofvec4fget%5C_%5C_newenum)
  - [VectorOfVec4f::push\_back](#vectorofvec4fpush%5C_back)
  - [VectorOfVec4f::push\_vector](#vectorofvec4fpush%5C_vector)
  - [VectorOfVec4f::put\_Item](#vectorofvec4fput%5C_item)
  - [VectorOfVec4f::size](#vectorofvec4fsize)
  - [VectorOfVec4f::slice](#vectorofvec4fslice)
  - [VectorOfVec4f::sort](#vectorofvec4fsort)
  - [VectorOfVec4f::sort\_variant](#vectorofvec4fsort%5C_variant)
  - [VectorOfVec4f::start](#vectorofvec4fstart)
- [VectorOfVec6f](#vectorofvec6f)
  - [VectorOfVec6f.Count](#vectorofvec6fcount)
  - [VectorOfVec6f::create](#vectorofvec6fcreate)
  - [VectorOfVec6f::Add](#vectorofvec6fadd)
  - [VectorOfVec6f::Items](#vectorofvec6fitems)
  - [VectorOfVec6f::Keys](#vectorofvec6fkeys)
  - [VectorOfVec6f::Remove](#vectorofvec6fremove)
  - [VectorOfVec6f::append](#vectorofvec6fappend)
  - [VectorOfVec6f::at](#vectorofvec6fat)
  - [VectorOfVec6f::clear](#vectorofvec6fclear)
  - [VectorOfVec6f::empty](#vectorofvec6fempty)
  - [VectorOfVec6f::end](#vectorofvec6fend)
  - [VectorOfVec6f::get\_Item](#vectorofvec6fget%5C_item)
  - [VectorOfVec6f::get\_\_NewEnum](#vectorofvec6fget%5C_%5C_newenum)
  - [VectorOfVec6f::push\_back](#vectorofvec6fpush%5C_back)
  - [VectorOfVec6f::push\_vector](#vectorofvec6fpush%5C_vector)
  - [VectorOfVec6f::put\_Item](#vectorofvec6fput%5C_item)
  - [VectorOfVec6f::size](#vectorofvec6fsize)
  - [VectorOfVec6f::slice](#vectorofvec6fslice)
  - [VectorOfVec6f::sort](#vectorofvec6fsort)
  - [VectorOfVec6f::sort\_variant](#vectorofvec6fsort%5C_variant)
  - [VectorOfVec6f::start](#vectorofvec6fstart)
- [VectorOfVec2d](#vectorofvec2d)
  - [VectorOfVec2d.Count](#vectorofvec2dcount)
  - [VectorOfVec2d::create](#vectorofvec2dcreate)
  - [VectorOfVec2d::Add](#vectorofvec2dadd)
  - [VectorOfVec2d::Items](#vectorofvec2ditems)
  - [VectorOfVec2d::Keys](#vectorofvec2dkeys)
  - [VectorOfVec2d::Remove](#vectorofvec2dremove)
  - [VectorOfVec2d::append](#vectorofvec2dappend)
  - [VectorOfVec2d::at](#vectorofvec2dat)
  - [VectorOfVec2d::clear](#vectorofvec2dclear)
  - [VectorOfVec2d::empty](#vectorofvec2dempty)
  - [VectorOfVec2d::end](#vectorofvec2dend)
  - [VectorOfVec2d::get\_Item](#vectorofvec2dget%5C_item)
  - [VectorOfVec2d::get\_\_NewEnum](#vectorofvec2dget%5C_%5C_newenum)
  - [VectorOfVec2d::push\_back](#vectorofvec2dpush%5C_back)
  - [VectorOfVec2d::push\_vector](#vectorofvec2dpush%5C_vector)
  - [VectorOfVec2d::put\_Item](#vectorofvec2dput%5C_item)
  - [VectorOfVec2d::size](#vectorofvec2dsize)
  - [VectorOfVec2d::slice](#vectorofvec2dslice)
  - [VectorOfVec2d::sort](#vectorofvec2dsort)
  - [VectorOfVec2d::sort\_variant](#vectorofvec2dsort%5C_variant)
  - [VectorOfVec2d::start](#vectorofvec2dstart)
- [VectorOfVec3d](#vectorofvec3d)
  - [VectorOfVec3d.Count](#vectorofvec3dcount)
  - [VectorOfVec3d::create](#vectorofvec3dcreate)
  - [VectorOfVec3d::Add](#vectorofvec3dadd)
  - [VectorOfVec3d::Items](#vectorofvec3ditems)
  - [VectorOfVec3d::Keys](#vectorofvec3dkeys)
  - [VectorOfVec3d::Remove](#vectorofvec3dremove)
  - [VectorOfVec3d::append](#vectorofvec3dappend)
  - [VectorOfVec3d::at](#vectorofvec3dat)
  - [VectorOfVec3d::clear](#vectorofvec3dclear)
  - [VectorOfVec3d::empty](#vectorofvec3dempty)
  - [VectorOfVec3d::end](#vectorofvec3dend)
  - [VectorOfVec3d::get\_Item](#vectorofvec3dget%5C_item)
  - [VectorOfVec3d::get\_\_NewEnum](#vectorofvec3dget%5C_%5C_newenum)
  - [VectorOfVec3d::push\_back](#vectorofvec3dpush%5C_back)
  - [VectorOfVec3d::push\_vector](#vectorofvec3dpush%5C_vector)
  - [VectorOfVec3d::put\_Item](#vectorofvec3dput%5C_item)
  - [VectorOfVec3d::size](#vectorofvec3dsize)
  - [VectorOfVec3d::slice](#vectorofvec3dslice)
  - [VectorOfVec3d::sort](#vectorofvec3dsort)
  - [VectorOfVec3d::sort\_variant](#vectorofvec3dsort%5C_variant)
  - [VectorOfVec3d::start](#vectorofvec3dstart)
- [VectorOfVec4d](#vectorofvec4d)
  - [VectorOfVec4d.Count](#vectorofvec4dcount)
  - [VectorOfVec4d::create](#vectorofvec4dcreate)
  - [VectorOfVec4d::Add](#vectorofvec4dadd)
  - [VectorOfVec4d::Items](#vectorofvec4ditems)
  - [VectorOfVec4d::Keys](#vectorofvec4dkeys)
  - [VectorOfVec4d::Remove](#vectorofvec4dremove)
  - [VectorOfVec4d::append](#vectorofvec4dappend)
  - [VectorOfVec4d::at](#vectorofvec4dat)
  - [VectorOfVec4d::clear](#vectorofvec4dclear)
  - [VectorOfVec4d::empty](#vectorofvec4dempty)
  - [VectorOfVec4d::end](#vectorofvec4dend)
  - [VectorOfVec4d::get\_Item](#vectorofvec4dget%5C_item)
  - [VectorOfVec4d::get\_\_NewEnum](#vectorofvec4dget%5C_%5C_newenum)
  - [VectorOfVec4d::push\_back](#vectorofvec4dpush%5C_back)
  - [VectorOfVec4d::push\_vector](#vectorofvec4dpush%5C_vector)
  - [VectorOfVec4d::put\_Item](#vectorofvec4dput%5C_item)
  - [VectorOfVec4d::size](#vectorofvec4dsize)
  - [VectorOfVec4d::slice](#vectorofvec4dslice)
  - [VectorOfVec4d::sort](#vectorofvec4dsort)
  - [VectorOfVec4d::sort\_variant](#vectorofvec4dsort%5C_variant)
  - [VectorOfVec4d::start](#vectorofvec4dstart)
- [VectorOfVec6d](#vectorofvec6d)
  - [VectorOfVec6d.Count](#vectorofvec6dcount)
  - [VectorOfVec6d::create](#vectorofvec6dcreate)
  - [VectorOfVec6d::Add](#vectorofvec6dadd)
  - [VectorOfVec6d::Items](#vectorofvec6ditems)
  - [VectorOfVec6d::Keys](#vectorofvec6dkeys)
  - [VectorOfVec6d::Remove](#vectorofvec6dremove)
  - [VectorOfVec6d::append](#vectorofvec6dappend)
  - [VectorOfVec6d::at](#vectorofvec6dat)
  - [VectorOfVec6d::clear](#vectorofvec6dclear)
  - [VectorOfVec6d::empty](#vectorofvec6dempty)
  - [VectorOfVec6d::end](#vectorofvec6dend)
  - [VectorOfVec6d::get\_Item](#vectorofvec6dget%5C_item)
  - [VectorOfVec6d::get\_\_NewEnum](#vectorofvec6dget%5C_%5C_newenum)
  - [VectorOfVec6d::push\_back](#vectorofvec6dpush%5C_back)
  - [VectorOfVec6d::push\_vector](#vectorofvec6dpush%5C_vector)
  - [VectorOfVec6d::put\_Item](#vectorofvec6dput%5C_item)
  - [VectorOfVec6d::size](#vectorofvec6dsize)
  - [VectorOfVec6d::slice](#vectorofvec6dslice)
  - [VectorOfVec6d::sort](#vectorofvec6dsort)
  - [VectorOfVec6d::sort\_variant](#vectorofvec6dsort%5C_variant)
  - [VectorOfVec6d::start](#vectorofvec6dstart)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## NamedParameters

### NamedParameters::create

```cpp
static NamedParameters NamedParameters::create();
AutoIt:
    _Dlib_ObjCreate("NamedParameters").create() -> <NamedParameters object>
```

```cpp
static std::shared_ptr<NamedParameters> NamedParameters::create( std::vector<std::pair<std::string, _variant_t>> pairs );
AutoIt:
    _Dlib_ObjCreate("NamedParameters").create( $pairs ) -> retval
```

### NamedParameters::Add

```cpp
void NamedParameters::Add( std::string key,
                           _variant_t  value );
AutoIt:
    $oNamedParameters.Add( $key, $value ) -> None
```

### NamedParameters::Get

```cpp
_variant_t NamedParameters::Get( std::string key );
AutoIt:
    $oNamedParameters.Get( $key ) -> retval
```

### NamedParameters::Items

```cpp
std::vector<_variant_t> NamedParameters::Items();
AutoIt:
    $oNamedParameters.Items() -> retval
```

### NamedParameters::Keys

```cpp
std::vector<std::string> NamedParameters::Keys();
AutoIt:
    $oNamedParameters.Keys() -> retval
```

### NamedParameters::Remove

```cpp
size_t NamedParameters::Remove( std::string key );
AutoIt:
    $oNamedParameters.Remove( $key ) -> retval
```

### NamedParameters::clear

```cpp
void NamedParameters::clear();
AutoIt:
    $oNamedParameters.clear() -> None
```

### NamedParameters::contains

```cpp
bool NamedParameters::contains( std::string key );
AutoIt:
    $oNamedParameters.contains( $key ) -> retval
```

### NamedParameters::count

```cpp
size_t NamedParameters::count( std::string key );
AutoIt:
    $oNamedParameters.count( $key ) -> retval
```

### NamedParameters::empty

```cpp
bool NamedParameters::empty();
AutoIt:
    $oNamedParameters.empty() -> retval
```

### NamedParameters::erase

```cpp
size_t NamedParameters::erase( std::string key );
AutoIt:
    $oNamedParameters.erase( $key ) -> retval
```

### NamedParameters::get\_Item

```cpp
_variant_t NamedParameters::get_Item( std::string key );
AutoIt:
    $oNamedParameters.Item( $key ) -> retval
    $oNamedParameters( $key ) -> retval
```

### NamedParameters::get\_\_NewEnum

```cpp
IUnknown* NamedParameters::get__NewEnum();
AutoIt:
    $oNamedParameters._NewEnum() -> retval
```

### NamedParameters::has

```cpp
bool NamedParameters::has( std::string key );
AutoIt:
    $oNamedParameters.has( $key ) -> retval
```

### NamedParameters::isNamedParameters

```cpp
static bool NamedParameters::isNamedParameters( const NamedParameters& value );
AutoIt:
    _Dlib_ObjCreate("NamedParameters").isNamedParameters( $value ) -> retval
```

```cpp
static bool NamedParameters::isNamedParameters( VARIANT* value = nullptr );
AutoIt:
    _Dlib_ObjCreate("NamedParameters").isNamedParameters( [$value] ) -> retval
```

### NamedParameters::max\_size

```cpp
size_t NamedParameters::max_size();
AutoIt:
    $oNamedParameters.max_size() -> retval
```

### NamedParameters::merge

```cpp
void NamedParameters::merge( MapOfStringAndVariant other );
AutoIt:
    $oNamedParameters.merge( $other ) -> None
```

### NamedParameters::put\_Item

```cpp
void NamedParameters::put_Item( std::string key,
                                _variant_t  item );
AutoIt:
    $oNamedParameters.Item( $key ) = $item
```

### NamedParameters::size

```cpp
size_t NamedParameters::size();
AutoIt:
    $oNamedParameters.size() -> retval
```

## autoit

### autoit::findFile

```cpp
std::string autoit::findFile( const std::string&              path,
                              const std::string&              directory,
                              const std::string&              filter = "",
                              const std::vector<std::string>& hints = std::vector<std::string>(1, "." ) );
AutoIt:
    _Dlib_ObjCreate("autoit").findFile( $path, $directory[, $filter[, $hints]] ) -> retval
```

### autoit::findFiles

```cpp
void autoit::findFiles( std::vector<std::string>& matches,
                        const std::string&        path,
                        const std::string&        directory,
                        int                       flags = FLTA_FILESFOLDERS,
                        bool                      relative = true );
AutoIt:
    _Dlib_ObjCreate("autoit").findFiles( $path, $directory[, $flags[, $relative[, $matches]]] ) -> $matches
```

## com

### com.Thread

```cpp
static com::Thread
AutoIt:
    [propget] $ocom.Thread
```

### com.ThreadSafeQueue

```cpp
static com::ThreadSafeQueue
AutoIt:
    [propget] $ocom.ThreadSafeQueue
```

## com::Thread

### com::Thread::get\_create

```cpp
static com::Thread com::Thread::get_create( void* func );
AutoIt:
    _Dlib_ObjCreate("com.Thread").create( $func ) -> <com.Thread object>
    $oThread( $func ) -> <com.Thread object>
```

### com::Thread::join

```cpp
void com::Thread::join();
AutoIt:
    $oThread.join() -> None
```

### com::Thread::start

```cpp
void com::Thread::start();
AutoIt:
    $oThread.start() -> None
```

## com::ThreadSafeQueue

### com::ThreadSafeQueue::get\_create

```cpp
static com::ThreadSafeQueue com::ThreadSafeQueue::get_create();
AutoIt:
    _Dlib_ObjCreate("com.ThreadSafeQueue").create() -> <com.ThreadSafeQueue object>
```

### com::ThreadSafeQueue::clear

```cpp
void com::ThreadSafeQueue::clear();
AutoIt:
    $oThreadSafeQueue.clear() -> None
```

### com::ThreadSafeQueue::get

```cpp
VARIANT* com::ThreadSafeQueue::get();
AutoIt:
    $oThreadSafeQueue.get() -> retval
```

### com::ThreadSafeQueue::push

```cpp
void com::ThreadSafeQueue::push( VARIANT* entry );
AutoIt:
    $oThreadSafeQueue.push( $entry ) -> None
```

## dlib

### dlib.binary\_test

```cpp
static dlib::binary_test
AutoIt:
    [propget] $odlib.binary_test
```

### dlib.regression\_test

```cpp
static dlib::regression_test
AutoIt:
    [propget] $odlib.regression_test
```

### dlib.ranking\_test

```cpp
static dlib::ranking_test
AutoIt:
    [propget] $odlib.ranking_test
```

### dlib.cca\_outputs

```cpp
static dlib::cca_outputs
AutoIt:
    [propget] $odlib.cca_outputs
```

### dlib.cnn\_face\_detection\_model\_v1

```cpp
static dlib::cnn_face_detection_model_v1
AutoIt:
    [propget] $odlib.cnn_face_detection_model_v1
```

### dlib.face\_recognition\_model\_v1

```cpp
static dlib::face_recognition_model_v1
AutoIt:
    [propget] $odlib.face_recognition_model_v1
```

### dlib.\_row

```cpp
static dlib::_row
AutoIt:
    [propget] $odlib._row
```

### dlib.segmenter\_type

```cpp
static dlib::segmenter_type
AutoIt:
    [propget] $odlib.segmenter_type
```

### dlib.segmenter\_params

```cpp
static dlib::segmenter_params
AutoIt:
    [propget] $odlib.segmenter_params
```

### dlib.segmenter\_test

```cpp
static dlib::segmenter_test
AutoIt:
    [propget] $odlib.segmenter_test
```

### dlib.shape\_predictor\_training\_options

```cpp
static dlib::shape_predictor_training_options
AutoIt:
    [propget] $odlib.shape_predictor_training_options
```

### dlib.simple\_object\_detector\_training\_options

```cpp
static dlib::simple_object_detector_training_options
AutoIt:
    [propget] $odlib.simple_object_detector_training_options
```

### dlib.simple\_test\_results

```cpp
static dlib::simple_test_results
AutoIt:
    [propget] $odlib.simple_test_results
```

### dlib.simple\_object\_detector\_com

```cpp
static dlib::simple_object_detector_com
AutoIt:
    [propget] $odlib.simple_object_detector_com
```

### dlib.simple\_structural\_svm\_problem

```cpp
static dlib::simple_structural_svm_problem
AutoIt:
    [propget] $odlib.simple_structural_svm_problem
```

### dlib.mmod\_rect

```cpp
static dlib::mmod_rect
AutoIt:
    [propget] $odlib.mmod_rect
```

### dlib.cuda

```cpp
static dlib::cuda
AutoIt:
    [propget] $odlib.cuda
```

### dlib.correlation\_tracker

```cpp
static dlib::correlation_tracker
AutoIt:
    [propget] $odlib.correlation_tracker
```

### dlib.\_radial\_basis\_kernel

```cpp
static dlib::_radial_basis_kernel
AutoIt:
    [propget] $odlib._radial_basis_kernel
```

### dlib.\_linear\_kernel

```cpp
static dlib::_linear_kernel
AutoIt:
    [propget] $odlib._linear_kernel
```

### dlib.\_decision\_function\_linear

```cpp
static dlib::_decision_function_linear
AutoIt:
    [propget] $odlib._decision_function_linear
```

### dlib.\_decision\_function\_sparse\_linear

```cpp
static dlib::_decision_function_sparse_linear
AutoIt:
    [propget] $odlib._decision_function_sparse_linear
```

### dlib.\_decision\_function\_histogram\_intersection

```cpp
static dlib::_decision_function_histogram_intersection
AutoIt:
    [propget] $odlib._decision_function_histogram_intersection
```

### dlib.\_decision\_function\_sparse\_histogram\_intersection

```cpp
static dlib::_decision_function_sparse_histogram_intersection
AutoIt:
    [propget] $odlib._decision_function_sparse_histogram_intersection
```

### dlib.\_decision\_function\_polynomial

```cpp
static dlib::_decision_function_polynomial
AutoIt:
    [propget] $odlib._decision_function_polynomial
```

### dlib.\_decision\_function\_sparse\_polynomial

```cpp
static dlib::_decision_function_sparse_polynomial
AutoIt:
    [propget] $odlib._decision_function_sparse_polynomial
```

### dlib.\_decision\_function\_radial\_basis

```cpp
static dlib::_decision_function_radial_basis
AutoIt:
    [propget] $odlib._decision_function_radial_basis
```

### dlib.\_decision\_function\_sparse\_radial\_basis

```cpp
static dlib::_decision_function_sparse_radial_basis
AutoIt:
    [propget] $odlib._decision_function_sparse_radial_basis
```

### dlib.\_decision\_function\_sigmoid

```cpp
static dlib::_decision_function_sigmoid
AutoIt:
    [propget] $odlib._decision_function_sigmoid
```

### dlib.\_decision\_function\_sparse\_sigmoid

```cpp
static dlib::_decision_function_sparse_sigmoid
AutoIt:
    [propget] $odlib._decision_function_sparse_sigmoid
```

### dlib.\_normalized\_decision\_function\_radial\_basis

```cpp
static dlib::_normalized_decision_function_radial_basis
AutoIt:
    [propget] $odlib._normalized_decision_function_radial_basis
```

### dlib.extended

```cpp
static _variant_t dlib::extended
AutoIt:
    [propget] $odlib.extended
```

### dlib.version

```cpp
static std::string dlib::version
AutoIt:
    [propget] $odlib.version
```

### dlib.time\_compiled

```cpp
static std::string dlib::time_compiled
AutoIt:
    [propget] $odlib.time_compiled
```

### dlib.DLIB\_USE\_CUDA

```cpp
static bool dlib::DLIB_USE_CUDA
AutoIt:
    [propget] $odlib.DLIB_USE_CUDA
```

### dlib.DLIB\_USE\_BLAS

```cpp
static bool dlib::DLIB_USE_BLAS
AutoIt:
    [propget] $odlib.DLIB_USE_BLAS
```

### dlib.DLIB\_USE\_LAPACK

```cpp
static bool dlib::DLIB_USE_LAPACK
AutoIt:
    [propget] $odlib.DLIB_USE_LAPACK
```

### dlib.USE\_AVX\_INSTRUCTIONS

```cpp
static bool dlib::USE_AVX_INSTRUCTIONS
AutoIt:
    [propget] $odlib.USE_AVX_INSTRUCTIONS
```

### dlib.USE\_NEON\_INSTRUCTIONS

```cpp
static bool dlib::USE_NEON_INSTRUCTIONS
AutoIt:
    [propget] $odlib.USE_NEON_INSTRUCTIONS
```

### dlib.function\_evaluation

```cpp
static dlib::function_evaluation
AutoIt:
    [propget] $odlib.function_evaluation
```

### dlib.function\_spec

```cpp
static dlib::function_spec
AutoIt:
    [propget] $odlib.function_spec
```

### dlib.function\_evaluation\_request

```cpp
static dlib::function_evaluation_request
AutoIt:
    [propget] $odlib.function_evaluation_request
```

### dlib.global\_function\_search

```cpp
static dlib::global_function_search
AutoIt:
    [propget] $odlib.global_function_search
```

### dlib.image\_window

```cpp
static dlib::image_window
AutoIt:
    [propget] $odlib.image_window
```

### dlib.rgb\_pixel

```cpp
static dlib::rgb_pixel
AutoIt:
    [propget] $odlib.rgb_pixel
```

### dlib.image\_dataset\_metadata

```cpp
static dlib::image_dataset_metadata
AutoIt:
    [propget] $odlib.image_dataset_metadata
```

### dlib.line

```cpp
static dlib::line
AutoIt:
    [propget] $odlib.line
```

### dlib.Matrix

```cpp
static dlib::Matrix
AutoIt:
    [propget] $odlib.Matrix
```

### dlib.fhog\_object\_detector

```cpp
static dlib::fhog_object_detector
AutoIt:
    [propget] $odlib.fhog_object_detector
```

### dlib.rect\_filter

```cpp
static dlib::rect_filter
AutoIt:
    [propget] $odlib.rect_filter
```

### dlib.rectangle

```cpp
static dlib::rectangle
AutoIt:
    [propget] $odlib.rectangle
```

### dlib.drectangle

```cpp
static dlib::drectangle
AutoIt:
    [propget] $odlib.drectangle
```

### dlib.full\_object\_detection

```cpp
static dlib::full_object_detection
AutoIt:
    [propget] $odlib.full_object_detection
```

### dlib.shape\_predictor

```cpp
static dlib::shape_predictor
AutoIt:
    [propget] $odlib.shape_predictor
```

### dlib.svm\_c\_trainer\_radial\_basis

```cpp
static dlib::svm_c_trainer_radial_basis
AutoIt:
    [propget] $odlib.svm_c_trainer_radial_basis
```

### dlib.svm\_c\_trainer\_sparse\_radial\_basis

```cpp
static dlib::svm_c_trainer_sparse_radial_basis
AutoIt:
    [propget] $odlib.svm_c_trainer_sparse_radial_basis
```

### dlib.svm\_c\_trainer\_histogram\_intersection

```cpp
static dlib::svm_c_trainer_histogram_intersection
AutoIt:
    [propget] $odlib.svm_c_trainer_histogram_intersection
```

### dlib.svm\_c\_trainer\_sparse\_histogram\_intersection

```cpp
static dlib::svm_c_trainer_sparse_histogram_intersection
AutoIt:
    [propget] $odlib.svm_c_trainer_sparse_histogram_intersection
```

### dlib.svm\_c\_trainer\_linear

```cpp
static dlib::svm_c_trainer_linear
AutoIt:
    [propget] $odlib.svm_c_trainer_linear
```

### dlib.svm\_c\_trainer\_sparse\_linear

```cpp
static dlib::svm_c_trainer_sparse_linear
AutoIt:
    [propget] $odlib.svm_c_trainer_sparse_linear
```

### dlib.rvm\_trainer\_radial\_basis

```cpp
static dlib::rvm_trainer_radial_basis
AutoIt:
    [propget] $odlib.rvm_trainer_radial_basis
```

### dlib.rvm\_trainer\_sparse\_radial\_basis

```cpp
static dlib::rvm_trainer_sparse_radial_basis
AutoIt:
    [propget] $odlib.rvm_trainer_sparse_radial_basis
```

### dlib.rvm\_trainer\_histogram\_intersection

```cpp
static dlib::rvm_trainer_histogram_intersection
AutoIt:
    [propget] $odlib.rvm_trainer_histogram_intersection
```

### dlib.rvm\_trainer\_sparse\_histogram\_intersection

```cpp
static dlib::rvm_trainer_sparse_histogram_intersection
AutoIt:
    [propget] $odlib.rvm_trainer_sparse_histogram_intersection
```

### dlib.rvm\_trainer\_linear

```cpp
static dlib::rvm_trainer_linear
AutoIt:
    [propget] $odlib.rvm_trainer_linear
```

### dlib.rvm\_trainer\_sparse\_linear

```cpp
static dlib::rvm_trainer_sparse_linear
AutoIt:
    [propget] $odlib.rvm_trainer_sparse_linear
```

### dlib.vec\_ranking\_pair

```cpp
static dlib::vec_ranking_pair
AutoIt:
    [propget] $odlib.vec_ranking_pair
```

### dlib.sparse\_ranking\_pair

```cpp
static dlib::sparse_ranking_pair
AutoIt:
    [propget] $odlib.sparse_ranking_pair
```

### dlib.vec\_svm\_rank\_trainer

```cpp
static dlib::vec_svm_rank_trainer
AutoIt:
    [propget] $odlib.vec_svm_rank_trainer
```

### dlib.svm\_rank\_trainer\_sparse

```cpp
static dlib::svm_rank_trainer_sparse
AutoIt:
    [propget] $odlib.svm_rank_trainer_sparse
```

### dlib.SpaceVector

```cpp
static dlib::SpaceVector
AutoIt:
    [propget] $odlib.SpaceVector
```

### dlib.point\_transform\_projective

```cpp
static dlib::point_transform_projective
AutoIt:
    [propget] $odlib.point_transform_projective
```

### dlib.dpoint

```cpp
static dlib::dpoint
AutoIt:
    [propget] $odlib.dpoint
```

### dlib.point

```cpp
static dlib::point
AutoIt:
    [propget] $odlib.point
```

### dlib::angle\_between\_lines

```cpp
double dlib::angle_between_lines( dlib::line a,
                                  dlib::line b );
AutoIt:
    _Dlib_ObjCreate("dlib").angle_between_lines( $a, $b ) -> retval
```

### dlib::apply\_cca\_transform

```cpp
dlib::SpaceVector dlib::apply_cca_transform( const dlib::Matrix&                          m,
                                             const std::vector<std::pair<ULONG, double>>& v );
AutoIt:
    _Dlib_ObjCreate("dlib").apply_cca_transform( $m, $v ) -> retval
```

### dlib::assignment\_cost

```cpp
double dlib::assignment_cost( const dlib::Matrix& cost,
                              std::vector<long>&  assignment );
AutoIt:
    _Dlib_ObjCreate("dlib").assignment_cost( $cost, $assignment ) -> retval
```

### dlib::auto\_train\_rbf\_classifier

```cpp
dlib::_normalized_decision_function_radial_basis dlib::auto_train_rbf_classifier( std::vector<dlib::SpaceVector>& x,
                                                                                  std::vector<double>&            y,
                                                                                  double                          max_runtime_seconds,
                                                                                  bool                            be_verbose = true );
AutoIt:
    _Dlib_ObjCreate("dlib").auto_train_rbf_classifier( $x, $y, $max_runtime_seconds[, $be_verbose] ) -> retval
```

```cpp
dlib::_normalized_decision_function_radial_basis dlib::auto_train_rbf_classifier( cv::Mat&             x,
                                                                                  std::vector<double>& y,
                                                                                  double               max_runtime_seconds,
                                                                                  bool                 be_verbose = true );
AutoIt:
    _Dlib_ObjCreate("dlib").auto_train_rbf_classifier( $x, $y, $max_runtime_seconds[, $be_verbose] ) -> retval
```

### dlib::cca

```cpp
dlib::cca_outputs dlib::cca( const std::vector<std::vector<std::pair<ULONG, double>>>& L,
                             const std::vector<std::vector<std::pair<ULONG, double>>>& R,
                             ULONG                                                     num_correlations,
                             ULONG                                                     extra_rank = 5,
                             ULONG                                                     q = 2,
                             double                                                    regularization = 0 );
AutoIt:
    _Dlib_ObjCreate("dlib").cca( $L, $R, $num_correlations[, $extra_rank[, $q[, $regularization]]] ) -> retval
```

### dlib::center

```cpp
dlib::point dlib::center( dlib::rectangle rect );
AutoIt:
    _Dlib_ObjCreate("dlib").center( $rect ) -> retval
```

```cpp
dlib::dpoint dlib::center( dlib::drectangle rect );
AutoIt:
    _Dlib_ObjCreate("dlib").center( $rect ) -> retval
```

### dlib::centered\_drect

```cpp
dlib::drectangle dlib::centered_drect( dlib::dpoint p,
                                       double       width,
                                       double       height );
AutoIt:
    _Dlib_ObjCreate("dlib").centered_drect( $p, $width, $height ) -> retval
```

```cpp
dlib::drectangle dlib::centered_drect( dlib::drectangle rect,
                                       double           width,
                                       double           height );
AutoIt:
    _Dlib_ObjCreate("dlib").centered_drect( $rect, $width, $height ) -> retval
```

### dlib::centered\_rect

```cpp
dlib::rectangle dlib::centered_rect( dlib::point p,
                                     ULONG       width,
                                     ULONG       height );
AutoIt:
    _Dlib_ObjCreate("dlib").centered_rect( $p, $width, $height ) -> retval
```

```cpp
dlib::rectangle dlib::centered_rect( dlib::rectangle rect,
                                     ULONG           width,
                                     ULONG           height );
AutoIt:
    _Dlib_ObjCreate("dlib").centered_rect( $rect, $width, $height ) -> retval
```

```cpp
dlib::rectangle dlib::centered_rect( long  x,
                                     long  y,
                                     ULONG width,
                                     ULONG height );
AutoIt:
    _Dlib_ObjCreate("dlib").centered_rect( $x, $y, $width, $height ) -> retval
```

### dlib::centered\_rects

```cpp
std::vector<dlib::rectangle> dlib::centered_rects( std::vector<dlib::point> pts,
                                                   ULONG                    width,
                                                   ULONG                    height );
AutoIt:
    _Dlib_ObjCreate("dlib").centered_rects( $pts, $width, $height ) -> retval
```

### dlib::chinese\_whispers

```cpp
std::vector<ULONG> dlib::chinese_whispers( std::vector<dlib::SpaceVector> edges );
AutoIt:
    _Dlib_ObjCreate("dlib").chinese_whispers( $edges ) -> retval
```

### dlib::chinese\_whispers\_clustering

```cpp
std::vector<ULONG> dlib::chinese_whispers_clustering( std::vector<dlib::SpaceVector> descriptors,
                                                      float                          threshold );
AutoIt:
    _Dlib_ObjCreate("dlib").chinese_whispers_clustering( $descriptors, $threshold ) -> retval
```

### dlib::count\_points\_between\_lines

```cpp
double dlib::count_points_between_lines( dlib::line                l1,
                                         dlib::line                l2,
                                         dlib::dpoint              reference_point,
                                         std::vector<dlib::dpoint> pts );
AutoIt:
    _Dlib_ObjCreate("dlib").count_points_between_lines( $l1, $l2, $reference_point, $pts ) -> retval
```

```cpp
double dlib::count_points_between_lines( dlib::line               l1,
                                         dlib::line               l2,
                                         dlib::dpoint             reference_point,
                                         std::vector<dlib::point> pts );
AutoIt:
    _Dlib_ObjCreate("dlib").count_points_between_lines( $l1, $l2, $reference_point, $pts ) -> retval
```

### dlib::count\_points\_on\_side\_of\_line

```cpp
double dlib::count_points_on_side_of_line( dlib::line                l,
                                           dlib::dpoint              reference_point,
                                           std::vector<dlib::dpoint> pts,
                                           double                    dist_thresh_min = 0,
                                           double                    dist_thresh_max = std::numeric_limits<double>::infinity() );
AutoIt:
    _Dlib_ObjCreate("dlib").count_points_on_side_of_line( $l, $reference_point, $pts[, $dist_thresh_min[, $dist_thresh_max]] ) -> retval
```

```cpp
double dlib::count_points_on_side_of_line( dlib::line               l,
                                           dlib::dpoint             reference_point,
                                           std::vector<dlib::point> pts,
                                           double                   dist_thresh_min = 0,
                                           double                   dist_thresh_max = std::numeric_limits<double>::infinity() );
AutoIt:
    _Dlib_ObjCreate("dlib").count_points_on_side_of_line( $l, $reference_point, $pts[, $dist_thresh_min[, $dist_thresh_max]] ) -> retval
```

### dlib::count\_steps\_without\_decrease

```cpp
size_t dlib::count_steps_without_decrease( std::vector<double>& time_series,
                                           double               probability_of_decrease = 0.51 );
AutoIt:
    _Dlib_ObjCreate("dlib").count_steps_without_decrease( $time_series[, $probability_of_decrease] ) -> retval
```

### dlib::count\_steps\_without\_decrease\_robust

```cpp
size_t dlib::count_steps_without_decrease_robust( std::vector<double>& time_series,
                                                  double               probability_of_decrease = 0.51,
                                                  double               quantile_discard = 0.1 );
AutoIt:
    _Dlib_ObjCreate("dlib").count_steps_without_decrease_robust( $time_series[, $probability_of_decrease[, $quantile_discard]] ) -> retval
```

### dlib::cross\_validate\_ranking\_trainer

```cpp
dlib::ranking_test dlib::cross_validate_ranking_trainer( dlib::vec_svm_rank_trainer          trainer,
                                                         std::vector<dlib::vec_ranking_pair> samples,
                                                         ULONG                               folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_ranking_trainer( $trainer, $samples, $folds ) -> retval
```

```cpp
dlib::ranking_test dlib::cross_validate_ranking_trainer( dlib::svm_rank_trainer_sparse          trainer,
                                                         std::vector<dlib::sparse_ranking_pair> samples,
                                                         ULONG                                  folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_ranking_trainer( $trainer, $samples, $folds ) -> retval
```

### dlib::cross\_validate\_sequence\_segmenter

```cpp
dlib::segmenter_test dlib::cross_validate_sequence_segmenter( const std::vector<std::vector<dlib::SpaceVector>>&       samples,
                                                              const std::vector<std::vector<std::pair<ULONG, ULONG>>>& segments,
                                                              long                                                     folds,
                                                              dlib::segmenter_params                                   params = segmenter_params() );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_sequence_segmenter( $samples, $segments, $folds[, $params] ) -> retval
```

```cpp
dlib::segmenter_test dlib::cross_validate_sequence_segmenter( const std::vector<std::vector<std::vector<std::pair<ULONG, double>>>>& samples,
                                                              const std::vector<std::vector<std::pair<ULONG, ULONG>>>&               segments,
                                                              long                                                                   folds,
                                                              dlib::segmenter_params                                                 params = segmenter_params() );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_sequence_segmenter( $samples, $segments, $folds[, $params] ) -> retval
```

### dlib::cross\_validate\_trainer

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_radial_basis samples,
                                                std::vector<dlib::SpaceVector>   x,
                                                std::vector<double>              y,
                                                ULONG                            folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_sparse_radial_basis            samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_histogram_intersection samples,
                                                std::vector<dlib::SpaceVector>             x,
                                                std::vector<double>                        y,
                                                ULONG                                      folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_sparse_histogram_intersection  samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_linear     samples,
                                                std::vector<dlib::SpaceVector> x,
                                                std::vector<double>            y,
                                                ULONG                          folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::svm_c_trainer_sparse_linear                  samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_radial_basis samples,
                                                std::vector<dlib::SpaceVector> x,
                                                std::vector<double>            y,
                                                ULONG                          folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_sparse_radial_basis              samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_histogram_intersection samples,
                                                std::vector<dlib::SpaceVector>           x,
                                                std::vector<double>                      y,
                                                ULONG                                    folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_sparse_histogram_intersection    samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_linear       samples,
                                                std::vector<dlib::SpaceVector> x,
                                                std::vector<double>            y,
                                                ULONG                          folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer( dlib::rvm_trainer_sparse_linear                    samples,
                                                std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                std::vector<double>                                y,
                                                ULONG                                              folds );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer( $samples, $x, $y, $folds ) -> retval
```

### dlib::cross\_validate\_trainer\_threaded

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_radial_basis samples,
                                                         std::vector<dlib::SpaceVector>   x,
                                                         std::vector<double>              y,
                                                         ULONG                            folds,
                                                         ULONG                            num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_sparse_radial_basis            samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_histogram_intersection samples,
                                                         std::vector<dlib::SpaceVector>             x,
                                                         std::vector<double>                        y,
                                                         ULONG                                      folds,
                                                         ULONG                                      num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_sparse_histogram_intersection  samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_linear     samples,
                                                         std::vector<dlib::SpaceVector> x,
                                                         std::vector<double>            y,
                                                         ULONG                          folds,
                                                         ULONG                          num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::svm_c_trainer_sparse_linear                  samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_radial_basis samples,
                                                         std::vector<dlib::SpaceVector> x,
                                                         std::vector<double>            y,
                                                         ULONG                          folds,
                                                         ULONG                          num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_sparse_radial_basis              samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_histogram_intersection samples,
                                                         std::vector<dlib::SpaceVector>           x,
                                                         std::vector<double>                      y,
                                                         ULONG                                    folds,
                                                         ULONG                                    num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_sparse_histogram_intersection    samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_linear       samples,
                                                         std::vector<dlib::SpaceVector> x,
                                                         std::vector<double>            y,
                                                         ULONG                          folds,
                                                         ULONG                          num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

```cpp
dlib::binary_test dlib::cross_validate_trainer_threaded( dlib::rvm_trainer_sparse_linear                    samples,
                                                         std::vector<std::vector<std::pair<ULONG, double>>> x,
                                                         std::vector<double>                                y,
                                                         ULONG                                              folds,
                                                         ULONG                                              num_threads );
AutoIt:
    _Dlib_ObjCreate("dlib").cross_validate_trainer_threaded( $samples, $x, $y, $folds, $num_threads ) -> retval
```

### dlib::distance\_to\_line

```cpp
double dlib::distance_to_line( dlib::line   l,
                               dlib::dpoint p );
AutoIt:
    _Dlib_ObjCreate("dlib").distance_to_line( $l, $p ) -> retval
```

```cpp
double dlib::distance_to_line( dlib::line  l,
                               dlib::point p );
AutoIt:
    _Dlib_ObjCreate("dlib").distance_to_line( $l, $p ) -> retval
```

### dlib::dnn\_prefer\_fastest\_algorithms

```cpp
bool dlib::dnn_prefer_fastest_algorithms();
AutoIt:
    _Dlib_ObjCreate("dlib").dnn_prefer_fastest_algorithms() -> retval
```

### dlib::dot

```cpp
double dlib::dot( dlib::Matrix& a,
                  dlib::Matrix& b );
AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

```cpp
double dlib::dot( dlib::SpaceVector& a,
                  dlib::SpaceVector& b );
AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

```cpp
double dlib::dot( dlib::dpoint& a,
                  dlib::dpoint& b );
AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

```cpp
double dlib::dot( dlib::point& a,
                  dlib::point& b );
AutoIt:
    _Dlib_ObjCreate("dlib").dot( $a, $b ) -> retval
```

### dlib::find\_candidate\_object\_locations

```cpp
void dlib::find_candidate_object_locations( cv::Mat&                         image,
                                            std::vector<dlib::rectangle>&    rects,
                                            std::tuple<double, double, long> kvals = std::tuple<double, double, long>(50, 200, 3),
                                            ULONG                            min_size = 20,
                                            ULONG                            max_merging_iterations = 50 );
AutoIt:
    _Dlib_ObjCreate("dlib").find_candidate_object_locations( $image[, $kvals[, $min_size[, $max_merging_iterations[, $rects]]]] ) -> $rects
```

### dlib::find\_max\_global

```cpp
void dlib::find_max_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            std::vector<bool>&   is_integer_variable,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );
AutoIt:
    _Dlib_ObjCreate("dlib").find_max_global( $f, $bound1, $bound2, $is_integer_variable, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

```cpp
void dlib::find_max_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );
AutoIt:
    _Dlib_ObjCreate("dlib").find_max_global( $f, $bound1, $bound2, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

### dlib::find\_min\_global

```cpp
void dlib::find_min_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            std::vector<bool>&   is_integer_variable,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );
AutoIt:
    _Dlib_ObjCreate("dlib").find_min_global( $f, $bound1, $bound2, $is_integer_variable, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

```cpp
void dlib::find_min_global( void*                f,
                            std::vector<double>& bound1,
                            std::vector<double>& bound2,
                            ULONG                num_function_calls,
                            double               solver_epsilon = 0,
                            std::vector<double>& x,
                            float*               y );
AutoIt:
    _Dlib_ObjCreate("dlib").find_min_global( $f, $bound1, $bound2, $num_function_calls[, $solver_epsilon[, $x[, $y]]] ) -> $x, $y
```

### dlib::find\_optimal\_rect\_filter

```cpp
dlib::rect_filter dlib::find_optimal_rect_filter( std::vector<dlib::rectangle> rects,
                                                  double                       smoothness = 1 );
AutoIt:
    _Dlib_ObjCreate("dlib").find_optimal_rect_filter( $rects[, $smoothness] ) -> retval
```

### dlib::find\_projective\_transform

```cpp
dlib::point_transform_projective dlib::find_projective_transform( std::vector<dlib::dpoint>& from_points,
                                                                  std::vector<dlib::dpoint>& to_points );
AutoIt:
    _Dlib_ObjCreate("dlib").find_projective_transform( $from_points, $to_points ) -> retval
```

```cpp
dlib::point_transform_projective dlib::find_projective_transform( dlib::Matrix& from_points,
                                                                  dlib::Matrix& to_points );
AutoIt:
    _Dlib_ObjCreate("dlib").find_projective_transform( $from_points, $to_points ) -> retval
```

```cpp
dlib::point_transform_projective dlib::find_projective_transform( cv::Mat& from_points,
                                                                  cv::Mat& to_points );
AutoIt:
    _Dlib_ObjCreate("dlib").find_projective_transform( $from_points, $to_points ) -> retval
```

### dlib::get\_face\_chip

```cpp
cv::Mat dlib::get_face_chip( const cv::Mat&                     img,
                             const dlib::full_object_detection& face,
                             size_t                             size = 150,
                             float                              padding = 0.25 );
AutoIt:
    _Dlib_ObjCreate("dlib").get_face_chip( $img, $face[, $size[, $padding]] ) -> retval
```

### dlib::get\_face\_chips

```cpp
std::vector<cv::Mat> dlib::get_face_chips( const cv::Mat&                                  img,
                                           const std::vector<dlib::full_object_detection>& faces,
                                           size_t                                          size = 150,
                                           float                                           padding = 0.25 );
AutoIt:
    _Dlib_ObjCreate("dlib").get_face_chips( $img, $faces[, $size[, $padding]] ) -> retval
```

### dlib::get\_frontal\_face\_detector

```cpp
dlib::fhog_object_detector dlib::get_frontal_face_detector();
AutoIt:
    _Dlib_ObjCreate("dlib").get_frontal_face_detector() -> retval
```

### dlib::hit\_enter\_to\_continue

```cpp
void dlib::hit_enter_to_continue();
AutoIt:
    _Dlib_ObjCreate("dlib").hit_enter_to_continue() -> None
```

### dlib::intersect

```cpp
dlib::dpoint dlib::intersect( dlib::line a,
                              dlib::line b );
AutoIt:
    _Dlib_ObjCreate("dlib").intersect( $a, $b ) -> retval
```

### dlib::inv

```cpp
dlib::point_transform_projective dlib::inv( dlib::point_transform_projective& trans );
AutoIt:
    _Dlib_ObjCreate("dlib").inv( $trans ) -> retval
```

### dlib::jitter\_image

```cpp
std::vector<cv::Mat> dlib::jitter_image( const cv::Mat& img,
                                         size_t         num_jitters = 1,
                                         bool           disturb_colors = false );
AutoIt:
    _Dlib_ObjCreate("dlib").jitter_image( $img[, $num_jitters[, $disturb_colors]] ) -> retval
```

### dlib::length

```cpp
double dlib::length( dlib::dpoint& p );
AutoIt:
    _Dlib_ObjCreate("dlib").length( $p ) -> retval
```

```cpp
double dlib::length( dlib::point& p );
AutoIt:
    _Dlib_ObjCreate("dlib").length( $p ) -> retval
```

### dlib::load\_grayscale\_image

```cpp
cv::Mat dlib::load_grayscale_image( const std::string& path );
AutoIt:
    _Dlib_ObjCreate("dlib").load_grayscale_image( $path ) -> retval
```

### dlib::load\_libsvm\_formatted\_data

```cpp
void dlib::load_libsvm_formatted_data( std::string&                                        file_name,
                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                       std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").load_libsvm_formatted_data( $file_name[, $samples[, $labels]] ) -> $samples, $labels
```

### dlib::load\_rgb\_image

```cpp
cv::Mat dlib::load_rgb_image( const std::string& path );
AutoIt:
    _Dlib_ObjCreate("dlib").load_rgb_image( $path ) -> retval
```

### dlib::make\_sparse\_vector

```cpp
void dlib::make_sparse_vector( std::vector<std::pair<ULONG, double>>& v );
AutoIt:
    _Dlib_ObjCreate("dlib").make_sparse_vector( [$v] ) -> $v
```

```cpp
void dlib::make_sparse_vector( std::vector<std::vector<std::pair<ULONG, double>>>& v );
AutoIt:
    _Dlib_ObjCreate("dlib").make_sparse_vector( [$v] ) -> $v
```

### dlib::max\_cost\_assignment

```cpp
std::vector<long> dlib::max_cost_assignment( const dlib::Matrix& cost );
AutoIt:
    _Dlib_ObjCreate("dlib").max_cost_assignment( $cost ) -> retval
```

### dlib::max\_index\_plus\_one

```cpp
ULONG dlib::max_index_plus_one( std::vector<std::pair<ULONG, double>>& v );
AutoIt:
    _Dlib_ObjCreate("dlib").max_index_plus_one( $v ) -> retval
```

### dlib::num\_separable\_filters

```cpp
ULONG dlib::num_separable_filters( dlib::fhog_object_detector& detector );
AutoIt:
    _Dlib_ObjCreate("dlib").num_separable_filters( $detector ) -> retval
```

```cpp
ULONG dlib::num_separable_filters( dlib::simple_object_detector_com& detector );
AutoIt:
    _Dlib_ObjCreate("dlib").num_separable_filters( $detector ) -> retval
```

### dlib::polygon\_area

```cpp
double dlib::polygon_area( std::vector<dlib::dpoint>& pts );
AutoIt:
    _Dlib_ObjCreate("dlib").polygon_area( $pts ) -> retval
```

### dlib::probability\_that\_sequence\_is\_increasing

```cpp
double dlib::probability_that_sequence_is_increasing( std::vector<double>& time_series,
                                                      double               thresh = 0 );
AutoIt:
    _Dlib_ObjCreate("dlib").probability_that_sequence_is_increasing( $time_series[, $thresh] ) -> retval
```

### dlib::reduce

```cpp
dlib::_normalized_decision_function_radial_basis dlib::reduce( dlib::_normalized_decision_function_radial_basis& df,
                                                               std::vector<dlib::SpaceVector>&                   x,
                                                               long                                              num_basis_vectors,
                                                               double                                            eps = 1e-3 );
AutoIt:
    _Dlib_ObjCreate("dlib").reduce( $df, $x, $num_basis_vectors[, $eps] ) -> retval
```

```cpp
dlib::_normalized_decision_function_radial_basis dlib::reduce( dlib::_normalized_decision_function_radial_basis& df,
                                                               cv::Mat&                                          x,
                                                               long                                              num_basis_vectors,
                                                               double                                            eps = 1e-3 );
AutoIt:
    _Dlib_ObjCreate("dlib").reduce( $df, $x, $num_basis_vectors[, $eps] ) -> retval
```

### dlib::save\_face\_chip

```cpp
void dlib::save_face_chip( const cv::Mat&                     img,
                           const dlib::full_object_detection& face,
                           const std::string&                 chip_filename,
                           size_t                             size = 150,
                           float                              padding = 0.25 );
AutoIt:
    _Dlib_ObjCreate("dlib").save_face_chip( $img, $face, $chip_filename[, $size[, $padding]] ) -> None
```

### dlib::save\_face\_chips

```cpp
void dlib::save_face_chips( const cv::Mat&                                  img,
                            const std::vector<dlib::full_object_detection>& faces,
                            const std::string&                              chip_filename,
                            size_t                                          size = 150,
                            float                                           padding = 0.25 );
AutoIt:
    _Dlib_ObjCreate("dlib").save_face_chips( $img, $faces, $chip_filename[, $size[, $padding]] ) -> None
```

### dlib::save\_image

```cpp
void dlib::save_image( const cv::Mat&     img,
                       const std::string& path );
AutoIt:
    _Dlib_ObjCreate("dlib").save_image( $img, $path ) -> None
```

### dlib::save\_libsvm\_formatted\_data

```cpp
void dlib::save_libsvm_formatted_data( const std::string&                                        file_name,
                                       const std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                       const std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").save_libsvm_formatted_data( $file_name, $samples, $labels ) -> None
```

### dlib::scale\_rect

```cpp
dlib::rectangle dlib::scale_rect( dlib::rectangle rect,
                                  double          scale );
AutoIt:
    _Dlib_ObjCreate("dlib").scale_rect( $rect, $scale ) -> retval
```

```cpp
dlib::drectangle dlib::scale_rect( dlib::drectangle rect,
                                   double           scale );
AutoIt:
    _Dlib_ObjCreate("dlib").scale_rect( $rect, $scale ) -> retval
```

### dlib::set\_dnn\_prefer\_fastest\_algorithms

```cpp
void dlib::set_dnn_prefer_fastest_algorithms();
AutoIt:
    _Dlib_ObjCreate("dlib").set_dnn_prefer_fastest_algorithms() -> None
```

### dlib::set\_dnn\_prefer\_smallest\_algorithms

```cpp
void dlib::set_dnn_prefer_smallest_algorithms();
AutoIt:
    _Dlib_ObjCreate("dlib").set_dnn_prefer_smallest_algorithms() -> None
```

### dlib::shrink\_rect

```cpp
dlib::rectangle dlib::shrink_rect( dlib::rectangle rect,
                                   long            num );
AutoIt:
    _Dlib_ObjCreate("dlib").shrink_rect( $rect, $num ) -> retval
```

```cpp
dlib::drectangle dlib::shrink_rect( dlib::drectangle rect,
                                    double           num );
AutoIt:
    _Dlib_ObjCreate("dlib").shrink_rect( $rect, $num ) -> retval
```

### dlib::signed\_distance\_to\_line

```cpp
double dlib::signed_distance_to_line( dlib::line   l,
                                      dlib::dpoint p );
AutoIt:
    _Dlib_ObjCreate("dlib").signed_distance_to_line( $l, $p ) -> retval
```

```cpp
double dlib::signed_distance_to_line( dlib::line  l,
                                      dlib::point p );
AutoIt:
    _Dlib_ObjCreate("dlib").signed_distance_to_line( $l, $p ) -> retval
```

### dlib::solve\_structural\_svm\_problem

```cpp
dlib::SpaceVector dlib::solve_structural_svm_problem( dlib::simple_structural_svm_problem& problem );
AutoIt:
    _Dlib_ObjCreate("dlib").solve_structural_svm_problem( $problem ) -> retval
```

### dlib::test\_binary\_decision\_function

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_normalized_decision_function_radial_basis& dec_funct,
                                                       std::vector<dlib::SpaceVector>&                   samples,
                                                       std::vector<double>&                              labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_normalized_decision_function_radial_basis& dec_funct,
                                                       cv::Mat&                                          samples,
                                                       std::vector<double>&                              labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_linear& dec_funct,
                                                       std::vector<dlib::SpaceVector>&  samples,
                                                       std::vector<double>&             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_linear& dec_funct,
                                                       cv::Mat&                         samples,
                                                       std::vector<double>&             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_linear&             dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_radial_basis& dec_funct,
                                                       std::vector<dlib::SpaceVector>&        samples,
                                                       std::vector<double>&                   labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_radial_basis& dec_funct,
                                                       cv::Mat&                               samples,
                                                       std::vector<double>&                   labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_radial_basis&       dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_polynomial& dec_funct,
                                                       std::vector<dlib::SpaceVector>&      samples,
                                                       std::vector<double>&                 labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_polynomial& dec_funct,
                                                       cv::Mat&                             samples,
                                                       std::vector<double>&                 labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_polynomial&         dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                       std::vector<dlib::SpaceVector>&                  samples,
                                                       std::vector<double>&                             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                       cv::Mat&                                         samples,
                                                       std::vector<double>&                             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_histogram_intersection& dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>&     samples,
                                                       std::vector<double>&                                    labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sigmoid& dec_funct,
                                                       std::vector<dlib::SpaceVector>&   samples,
                                                       std::vector<double>&              labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sigmoid& dec_funct,
                                                       cv::Mat&                          samples,
                                                       std::vector<double>&              labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::binary_test dlib::test_binary_decision_function( dlib::_decision_function_sparse_sigmoid&            dec_funct,
                                                       std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                       std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_binary_decision_function( $dec_funct, $samples, $labels ) -> retval
```

### dlib::test\_ranking\_function

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_linear&     dec_funct,
                                                std::vector<dlib::vec_ranking_pair>& samples );
AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $samples ) -> retval
```

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_linear& dec_funct,
                                                dlib::vec_ranking_pair&          sample );
AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $sample ) -> retval
```

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_sparse_linear& dec_funct,
                                                std::vector<dlib::sparse_ranking_pair>& samples );
AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $samples ) -> retval
```

```cpp
dlib::ranking_test dlib::test_ranking_function( dlib::_decision_function_sparse_linear& dec_funct,
                                                dlib::sparse_ranking_pair&              sample );
AutoIt:
    _Dlib_ObjCreate("dlib").test_ranking_function( $dec_funct, $sample ) -> retval
```

### dlib::test\_regression\_function

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_linear& dec_funct,
                                                      std::vector<dlib::SpaceVector>&  samples,
                                                      std::vector<double>&             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_linear& dec_funct,
                                                      cv::Mat&                         samples,
                                                      std::vector<double>&             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_linear&             dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_radial_basis& dec_funct,
                                                      std::vector<dlib::SpaceVector>&        samples,
                                                      std::vector<double>&                   labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_radial_basis& dec_funct,
                                                      cv::Mat&                               samples,
                                                      std::vector<double>&                   labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_radial_basis&       dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_polynomial& dec_funct,
                                                      std::vector<dlib::SpaceVector>&      samples,
                                                      std::vector<double>&                 labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_polynomial& dec_funct,
                                                      cv::Mat&                             samples,
                                                      std::vector<double>&                 labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_polynomial&         dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                      std::vector<dlib::SpaceVector>&                  samples,
                                                      std::vector<double>&                             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_histogram_intersection& dec_funct,
                                                      cv::Mat&                                         samples,
                                                      std::vector<double>&                             labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_histogram_intersection& dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>&     samples,
                                                      std::vector<double>&                                    labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sigmoid& dec_funct,
                                                      std::vector<dlib::SpaceVector>&   samples,
                                                      std::vector<double>&              labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sigmoid& dec_funct,
                                                      cv::Mat&                          samples,
                                                      std::vector<double>&              labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

```cpp
dlib::regression_test dlib::test_regression_function( dlib::_decision_function_sparse_sigmoid&            dec_funct,
                                                      std::vector<std::vector<std::pair<ULONG, double>>>& samples,
                                                      std::vector<double>&                                labels );
AutoIt:
    _Dlib_ObjCreate("dlib").test_regression_function( $dec_funct, $samples, $labels ) -> retval
```

### dlib::test\_sequence\_segmenter

```cpp
dlib::segmenter_test dlib::test_sequence_segmenter( const dlib::segmenter_type&                              segmenter,
                                                    const std::vector<std::vector<dlib::SpaceVector>>&       samples,
                                                    const std::vector<std::vector<std::pair<ULONG, ULONG>>>& segments );
AutoIt:
    _Dlib_ObjCreate("dlib").test_sequence_segmenter( $segmenter, $samples, $segments ) -> retval
```

```cpp
dlib::segmenter_test dlib::test_sequence_segmenter( const dlib::segmenter_type&                                            segmenter,
                                                    const std::vector<std::vector<std::vector<std::pair<ULONG, double>>>>& samples,
                                                    const std::vector<std::vector<std::pair<ULONG, ULONG>>>&               segments );
AutoIt:
    _Dlib_ObjCreate("dlib").test_sequence_segmenter( $segmenter, $samples, $segments ) -> retval
```

### dlib::test\_shape\_predictor

```cpp
double dlib::test_shape_predictor( std::string dataset_filename,
                                   std::string predictor_filename );
AutoIt:
    _Dlib_ObjCreate("dlib").test_shape_predictor( $dataset_filename, $predictor_filename ) -> retval
```

```cpp
double dlib::test_shape_predictor( std::vector<cv::Mat>&                                  images,
                                   std::vector<std::vector<dlib::full_object_detection>>& detections,
                                   std::vector<std::vector<double>>&                      scales,
                                   dlib::shape_predictor&                                 predictor );
AutoIt:
    _Dlib_ObjCreate("dlib").test_shape_predictor( $images, $detections, $scales, $predictor ) -> retval
```

```cpp
double dlib::test_shape_predictor( std::vector<cv::Mat>&                                  images,
                                   std::vector<std::vector<dlib::full_object_detection>>& detections,
                                   dlib::shape_predictor&                                 predictor,
                                   std::vector<std::vector<double>>&                      scales = vector_vector_double() );
AutoIt:
    _Dlib_ObjCreate("dlib").test_shape_predictor( $images, $detections, $predictor[, $scales] ) -> retval
```

### dlib::test\_simple\_object\_detector

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const std::string& dataset_filename,
                                                             const std::string& detector_filename,
                                                             const int          upsampling_amount = -1 );
AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $dataset_filename, $detector_filename[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const std::string&          dataset_filename,
                                                             dlib::fhog_object_detector& detector,
                                                             const int                   upsampling_amount = -1 );
AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $dataset_filename, $detector[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const std::string&                dataset_filename,
                                                             dlib::simple_object_detector_com& detector,
                                                             const int                         upsampling_amount = -1 );
AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $dataset_filename, $detector[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const std::vector<cv::Mat>&                images,
                                                             std::vector<std::vector<dlib::rectangle>>& boxes,
                                                             dlib::fhog_object_detector&                detector,
                                                             const int                                  upsampling_amount = -1 );
AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $images, $boxes, $detector[, $upsampling_amount] ) -> retval
```

```cpp
dlib::simple_test_results dlib::test_simple_object_detector( const std::vector<cv::Mat>&                images,
                                                             std::vector<std::vector<dlib::rectangle>>& boxes,
                                                             dlib::simple_object_detector_com&          detector,
                                                             const int                                  upsampling_amount = -1 );
AutoIt:
    _Dlib_ObjCreate("dlib").test_simple_object_detector( $images, $boxes, $detector[, $upsampling_amount] ) -> retval
```

### dlib::threshold\_filter\_singular\_values

```cpp
dlib::fhog_object_detector dlib::threshold_filter_singular_values( dlib::fhog_object_detector& detector,
                                                                   double                      thresh,
                                                                   ULONG                       weight_index = 0 );
AutoIt:
    _Dlib_ObjCreate("dlib").threshold_filter_singular_values( $detector, $thresh[, $weight_index] ) -> retval
```

```cpp
dlib::simple_object_detector_com dlib::threshold_filter_singular_values( dlib::simple_object_detector_com& detector,
                                                                         double                            thresh,
                                                                         ULONG                             weight_index = 0 );
AutoIt:
    _Dlib_ObjCreate("dlib").threshold_filter_singular_values( $detector, $thresh[, $weight_index] ) -> retval
```

### dlib::train\_sequence\_segmenter

```cpp
dlib::segmenter_type dlib::train_sequence_segmenter( const std::vector<std::vector<dlib::SpaceVector>>&       samples,
                                                     const std::vector<std::vector<std::pair<ULONG, ULONG>>>& segments,
                                                     dlib::segmenter_params                                   params = segmenter_params() );
AutoIt:
    _Dlib_ObjCreate("dlib").train_sequence_segmenter( $samples, $segments[, $params] ) -> retval
```

```cpp
dlib::segmenter_type dlib::train_sequence_segmenter( const std::vector<std::vector<std::vector<std::pair<ULONG, double>>>>& samples,
                                                     const std::vector<std::vector<std::pair<ULONG, ULONG>>>&               segments,
                                                     dlib::segmenter_params                                                 params = segmenter_params() );
AutoIt:
    _Dlib_ObjCreate("dlib").train_sequence_segmenter( $samples, $segments[, $params] ) -> retval
```

### dlib::train\_shape\_predictor

```cpp
void dlib::train_shape_predictor( const std::string&                            dataset_filename,
                                  const std::string&                            predictor_output_filename,
                                  const dlib::shape_predictor_training_options& options );
AutoIt:
    _Dlib_ObjCreate("dlib").train_shape_predictor( $dataset_filename, $predictor_output_filename, $options ) -> None
```

```cpp
dlib::shape_predictor dlib::train_shape_predictor( std::vector<cv::Mat>&                                  images,
                                                   std::vector<std::vector<dlib::full_object_detection>>& detections,
                                                   dlib::shape_predictor_training_options&                options );
AutoIt:
    _Dlib_ObjCreate("dlib").train_shape_predictor( $images, $detections, $options ) -> retval
```

### dlib::train\_simple\_object\_detector

```cpp
void dlib::train_simple_object_detector( const std::string&                                   dataset_filename,
                                         const std::string&                                   detector_output_filename,
                                         const dlib::simple_object_detector_training_options& options );
AutoIt:
    _Dlib_ObjCreate("dlib").train_simple_object_detector( $dataset_filename, $detector_output_filename, $options ) -> None
```

```cpp
dlib::simple_object_detector_com dlib::train_simple_object_detector( const std::vector<cv::Mat>&                          images,
                                                                     std::vector<std::vector<dlib::rectangle>>&           boxes,
                                                                     const dlib::simple_object_detector_training_options& options );
AutoIt:
    _Dlib_ObjCreate("dlib").train_simple_object_detector( $images, $boxes, $options ) -> retval
```

### dlib::translate\_rect

```cpp
dlib::rectangle dlib::translate_rect( dlib::rectangle rect,
                                      dlib::point     p );
AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

```cpp
dlib::rectangle dlib::translate_rect( dlib::rectangle rect,
                                      dlib::dpoint    p );
AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

```cpp
dlib::drectangle dlib::translate_rect( dlib::drectangle rect,
                                       dlib::point      p );
AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

```cpp
dlib::drectangle dlib::translate_rect( dlib::drectangle rect,
                                       dlib::dpoint     p );
AutoIt:
    _Dlib_ObjCreate("dlib").translate_rect( $rect, $p ) -> retval
```

### dlib::variant

```cpp
_variant_t dlib::variant( void* ptr );
AutoIt:
    _Dlib_ObjCreate("dlib").variant( $ptr ) -> retval
```

## dlib::binary\_test

### binary\_test.class1\_accuracy

```cpp
double dlib::binary_test::class1_accuracy
AutoIt:
    [propget, propput] $obinary_test.class1_accuracy
```

### binary\_test.class2\_accuracy

```cpp
double dlib::binary_test::class2_accuracy
AutoIt:
    [propget, propput] $obinary_test.class2_accuracy
```

### dlib::binary\_test::get\_create

```cpp
static dlib::binary_test dlib::binary_test::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.binary_test").create() -> <dlib.binary_test object>
```

### dlib::binary\_test::ToString

```cpp
std::string dlib::binary_test::ToString() const;
AutoIt:
    $obinary_test.ToString() -> retval
```

## dlib::regression\_test

### regression\_test.mean\_squared\_error

```cpp
double dlib::regression_test::mean_squared_error
AutoIt:
    [propget, propput] $oregression_test.mean_squared_error
```

### regression\_test.R\_squared

```cpp
double dlib::regression_test::R_squared
AutoIt:
    [propget, propput] $oregression_test.R_squared
```

### regression\_test.mean\_average\_error

```cpp
double dlib::regression_test::mean_average_error
AutoIt:
    [propget, propput] $oregression_test.mean_average_error
```

### regression\_test.mean\_error\_stddev

```cpp
double dlib::regression_test::mean_error_stddev
AutoIt:
    [propget, propput] $oregression_test.mean_error_stddev
```

### dlib::regression\_test::get\_create

```cpp
static dlib::regression_test dlib::regression_test::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.regression_test").create() -> <dlib.regression_test object>
```

### dlib::regression\_test::ToString

```cpp
std::string dlib::regression_test::ToString() const;
AutoIt:
    $oregression_test.ToString() -> retval
```

## dlib::ranking\_test

### ranking\_test.ranking\_accuracy

```cpp
double dlib::ranking_test::ranking_accuracy
AutoIt:
    [propget, propput] $oranking_test.ranking_accuracy
```

### ranking\_test.mean\_ap

```cpp
double dlib::ranking_test::mean_ap
AutoIt:
    [propget, propput] $oranking_test.mean_ap
```

### dlib::ranking\_test::get\_create

```cpp
static dlib::ranking_test dlib::ranking_test::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.ranking_test").create() -> <dlib.ranking_test object>
```

### dlib::ranking\_test::ToString

```cpp
std::string dlib::ranking_test::ToString() const;
AutoIt:
    $oranking_test.ToString() -> retval
```

## dlib::cca\_outputs

### cca\_outputs.correlations

```cpp
dlib::SpaceVector dlib::cca_outputs::correlations
AutoIt:
    [propget, propput] $occa_outputs.correlations
```

### cca\_outputs.Ltrans

```cpp
dlib::Matrix dlib::cca_outputs::Ltrans
AutoIt:
    [propget, propput] $occa_outputs.Ltrans
```

### cca\_outputs.Rtrans

```cpp
dlib::Matrix dlib::cca_outputs::Rtrans
AutoIt:
    [propget, propput] $occa_outputs.Rtrans
```

### dlib::cca\_outputs::get\_create

```cpp
static dlib::cca_outputs dlib::cca_outputs::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.cca_outputs").create() -> <dlib.cca_outputs object>
```

## dlib::cnn\_face\_detection\_model\_v1

### dlib::cnn\_face\_detection\_model\_v1::create

```cpp
static dlib::cnn_face_detection_model_v1 dlib::cnn_face_detection_model_v1::create( const std::string& model_filename );
AutoIt:
    _Dlib_ObjCreate("dlib.cnn_face_detection_model_v1").create( $model_filename ) -> <dlib.cnn_face_detection_model_v1 object>
```

### dlib::cnn\_face\_detection\_model\_v1::detect

```cpp
std::vector<dlib::mmod_rect> dlib::cnn_face_detection_model_v1::detect( const cv::Mat& img,
                                                                        const int      upsample_num_times = 0 );
AutoIt:
    $ocnn_face_detection_model_v1.detect( $img[, $upsample_num_times] ) -> retval
```

### dlib::cnn\_face\_detection\_model\_v1::detect\_multi

```cpp
std::vector<std::vector<dlib::mmod_rect>> dlib::cnn_face_detection_model_v1::detect_multi( const std::vector<cv::Mat>& imgs,
                                                                                           const int                   upsample_num_times = 0,
                                                                                           const int                   batch_size = 128 );
AutoIt:
    $ocnn_face_detection_model_v1.detect_multi( $imgs[, $upsample_num_times[, $batch_size]] ) -> retval
```

### dlib::cnn\_face\_detection\_model\_v1::get\_call

```cpp
std::vector<dlib::mmod_rect> dlib::cnn_face_detection_model_v1::get_call( const cv::Mat& img,
                                                                          const int      upsample_num_times = 0 );
AutoIt:
    $ocnn_face_detection_model_v1.call( $img[, $upsample_num_times] ) -> retval
    $ocnn_face_detection_model_v1( $img[, $upsample_num_times] ) -> retval
```

```cpp
std::vector<std::vector<dlib::mmod_rect>> dlib::cnn_face_detection_model_v1::get_call( const std::vector<cv::Mat>& imgs,
                                                                                       const int                   upsample_num_times = 0,
                                                                                       const int                   batch_size = 128 );
AutoIt:
    $ocnn_face_detection_model_v1.call( $imgs[, $upsample_num_times[, $batch_size]] ) -> retval
    $ocnn_face_detection_model_v1( $imgs[, $upsample_num_times[, $batch_size]] ) -> retval
```

## dlib::face\_recognition\_model\_v1

### dlib::face\_recognition\_model\_v1::get\_create

```cpp
static dlib::face_recognition_model_v1 dlib::face_recognition_model_v1::get_create( const std::string& model_filename );
AutoIt:
    _Dlib_ObjCreate("dlib.face_recognition_model_v1").create( $model_filename ) -> <dlib.face_recognition_model_v1 object>
    $oface_recognition_model_v1( $model_filename ) -> <dlib.face_recognition_model_v1 object>
```

### dlib::face\_recognition\_model\_v1::compute\_face\_descriptor

```cpp
dlib::SpaceVector dlib::face_recognition_model_v1::compute_face_descriptor( const cv::Mat&                     image,
                                                                            const dlib::full_object_detection& face,
                                                                            const int                          num_jitters = 0,
                                                                            float                              padding = 0.25 );
AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $image, $face[, $num_jitters[, $padding]] ) -> retval
```

```cpp
dlib::SpaceVector dlib::face_recognition_model_v1::compute_face_descriptor( const cv::Mat& image,
                                                                            const int      num_jitters = 0 );
AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $image[, $num_jitters] ) -> retval
```

```cpp
std::vector<dlib::SpaceVector> dlib::face_recognition_model_v1::compute_face_descriptor( const cv::Mat&                                  image,
                                                                                         const std::vector<dlib::full_object_detection>& faces,
                                                                                         const int                                       num_jitters = 0,
                                                                                         float                                           padding = 0.25 );
AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $image, $faces[, $num_jitters[, $padding]] ) -> retval
```

```cpp
std::vector<std::vector<dlib::SpaceVector>> dlib::face_recognition_model_v1::compute_face_descriptor( const std::vector<cv::Mat>&                                  images,
                                                                                                      const std::vector<std::vector<dlib::full_object_detection>>& batch_faces,
                                                                                                      const int                                                    num_jitters = 0,
                                                                                                      float                                                        padding = 0.25 );
AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $images, $batch_faces[, $num_jitters[, $padding]] ) -> retval
```

```cpp
std::vector<dlib::SpaceVector> dlib::face_recognition_model_v1::compute_face_descriptor( const std::vector<cv::Mat>& images,
                                                                                         const int                   num_jitters = 0 );
AutoIt:
    $oface_recognition_model_v1.compute_face_descriptor( $images[, $num_jitters] ) -> retval
```

## dlib::\_row

### dlib::\_row::get\_create

```cpp
static dlib::_row dlib::_row::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib._row").create() -> <dlib._row object>
```

```cpp
static dlib::_row dlib::_row::get_create( double* data_,
                                          long    size_ );
AutoIt:
    _Dlib_ObjCreate("dlib._row").create( $size_[, $data_] ) -> <dlib._row object>
    $o_row( $size_[, $data_] ) -> <dlib._row object>
```

### dlib::\_row::ToString

```cpp
std::string dlib::_row::ToString();
AutoIt:
    $o_row.ToString() -> retval
```

### dlib::\_row::get

```cpp
double dlib::_row::get( long r );
AutoIt:
    $o_row.get( $r ) -> retval
```

### dlib::\_row::set

```cpp
void dlib::_row::set( long   r,
                      double val );
AutoIt:
    $o_row.set( $r, $val ) -> None
```

## dlib::segmenter\_type

### segmenter\_type.weights

```cpp
dlib::SpaceVector dlib::segmenter_type::get_weights()
AutoIt:
    [propget] $osegmenter_type.weights
```

### dlib::segmenter\_type::create

```cpp
static dlib::segmenter_type dlib::segmenter_type::create();
AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_type").create() -> <dlib.segmenter_type object>
```

### dlib::segmenter\_type::get\_call

```cpp
std::vector<std::pair<ULONG, ULONG>> dlib::segmenter_type::get_call( const std::vector<dlib::SpaceVector>& x ) const;
AutoIt:
    $osegmenter_type.call( $x ) -> retval
    $osegmenter_type( $x ) -> retval
```

```cpp
std::vector<std::pair<ULONG, ULONG>> dlib::segmenter_type::get_call( const std::vector<std::vector<std::pair<ULONG, double>>>& x ) const;
AutoIt:
    $osegmenter_type.call( $x ) -> retval
    $osegmenter_type( $x ) -> retval
```

## dlib::segmenter\_params

### segmenter\_params.use\_BIO\_model

```cpp
bool dlib::segmenter_params::use_BIO_model
AutoIt:
    [propget, propput] $osegmenter_params.use_BIO_model
```

### segmenter\_params.use\_high\_order\_features

```cpp
bool dlib::segmenter_params::use_high_order_features
AutoIt:
    [propget, propput] $osegmenter_params.use_high_order_features
```

### segmenter\_params.allow\_negative\_weights

```cpp
bool dlib::segmenter_params::allow_negative_weights
AutoIt:
    [propget, propput] $osegmenter_params.allow_negative_weights
```

### segmenter\_params.window\_size

```cpp
ULONG dlib::segmenter_params::window_size
AutoIt:
    [propget, propput] $osegmenter_params.window_size
```

### segmenter\_params.num\_threads

```cpp
ULONG dlib::segmenter_params::num_threads
AutoIt:
    [propget, propput] $osegmenter_params.num_threads
```

### segmenter\_params.epsilon

```cpp
double dlib::segmenter_params::epsilon
AutoIt:
    [propget, propput] $osegmenter_params.epsilon
```

### segmenter\_params.max\_cache\_size

```cpp
ULONG dlib::segmenter_params::max_cache_size
AutoIt:
    [propget, propput] $osegmenter_params.max_cache_size
```

### segmenter\_params.be\_verbose

```cpp
bool dlib::segmenter_params::be_verbose
AutoIt:
    [propget, propput] $osegmenter_params.be_verbose
```

### segmenter\_params.C

```cpp
double dlib::segmenter_params::C
AutoIt:
    [propget, propput] $osegmenter_params.C
```

### dlib::segmenter\_params::get\_create

```cpp
static dlib::segmenter_params dlib::segmenter_params::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_params").create() -> <dlib.segmenter_params object>
```

### dlib::segmenter\_params::ToString

```cpp
std::string dlib::segmenter_params::ToString() const;
AutoIt:
    $osegmenter_params.ToString() -> retval
```

## dlib::segmenter\_test

### segmenter\_test.precision

```cpp
double dlib::segmenter_test::precision
AutoIt:
    [propget, propput] $osegmenter_test.precision
```

### segmenter\_test.recall

```cpp
double dlib::segmenter_test::recall
AutoIt:
    [propget, propput] $osegmenter_test.recall
```

### segmenter\_test.f1

```cpp
double dlib::segmenter_test::f1
AutoIt:
    [propget, propput] $osegmenter_test.f1
```

### dlib::segmenter\_test::get\_create

```cpp
static dlib::segmenter_test dlib::segmenter_test::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.segmenter_test").create() -> <dlib.segmenter_test object>
```

### dlib::segmenter\_test::ToString

```cpp
std::string dlib::segmenter_test::ToString() const;
AutoIt:
    $osegmenter_test.ToString() -> retval
```

## dlib::shape\_predictor\_training\_options

### shape\_predictor\_training\_options.be\_verbose

```cpp
bool dlib::shape_predictor_training_options::be_verbose
AutoIt:
    [propget, propput] $oshape_predictor_training_options.be_verbose
```

### shape\_predictor\_training\_options.cascade\_depth

```cpp
ULONG dlib::shape_predictor_training_options::cascade_depth
AutoIt:
    [propget, propput] $oshape_predictor_training_options.cascade_depth
```

### shape\_predictor\_training\_options.tree\_depth

```cpp
ULONG dlib::shape_predictor_training_options::tree_depth
AutoIt:
    [propget, propput] $oshape_predictor_training_options.tree_depth
```

### shape\_predictor\_training\_options.num\_trees\_per\_cascade\_level

```cpp
ULONG dlib::shape_predictor_training_options::num_trees_per_cascade_level
AutoIt:
    [propget, propput] $oshape_predictor_training_options.num_trees_per_cascade_level
```

### shape\_predictor\_training\_options.nu

```cpp
double dlib::shape_predictor_training_options::nu
AutoIt:
    [propget, propput] $oshape_predictor_training_options.nu
```

### shape\_predictor\_training\_options.oversampling\_amount

```cpp
ULONG dlib::shape_predictor_training_options::oversampling_amount
AutoIt:
    [propget, propput] $oshape_predictor_training_options.oversampling_amount
```

### shape\_predictor\_training\_options.oversampling\_translation\_jitter

```cpp
double dlib::shape_predictor_training_options::oversampling_translation_jitter
AutoIt:
    [propget, propput] $oshape_predictor_training_options.oversampling_translation_jitter
```

### shape\_predictor\_training\_options.feature\_pool\_size

```cpp
ULONG dlib::shape_predictor_training_options::feature_pool_size
AutoIt:
    [propget, propput] $oshape_predictor_training_options.feature_pool_size
```

### shape\_predictor\_training\_options.lambda\_param

```cpp
double dlib::shape_predictor_training_options::lambda_param
AutoIt:
    [propget, propput] $oshape_predictor_training_options.lambda_param
```

### shape\_predictor\_training\_options.num\_test\_splits

```cpp
ULONG dlib::shape_predictor_training_options::num_test_splits
AutoIt:
    [propget, propput] $oshape_predictor_training_options.num_test_splits
```

### shape\_predictor\_training\_options.feature\_pool\_region\_padding

```cpp
double dlib::shape_predictor_training_options::feature_pool_region_padding
AutoIt:
    [propget, propput] $oshape_predictor_training_options.feature_pool_region_padding
```

### shape\_predictor\_training\_options.random\_seed

```cpp
std::string dlib::shape_predictor_training_options::random_seed
AutoIt:
    [propget, propput] $oshape_predictor_training_options.random_seed
```

### shape\_predictor\_training\_options.landmark\_relative\_padding\_mode

```cpp
bool dlib::shape_predictor_training_options::landmark_relative_padding_mode
AutoIt:
    [propget, propput] $oshape_predictor_training_options.landmark_relative_padding_mode
```

### shape\_predictor\_training\_options.num\_threads

```cpp
ULONG dlib::shape_predictor_training_options::num_threads
AutoIt:
    [propget, propput] $oshape_predictor_training_options.num_threads
```

### dlib::shape\_predictor\_training\_options::get\_create

```cpp
static dlib::shape_predictor_training_options dlib::shape_predictor_training_options::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.shape_predictor_training_options").create() -> <dlib.shape_predictor_training_options object>
```

### dlib::shape\_predictor\_training\_options::ToString

```cpp
std::string dlib::shape_predictor_training_options::ToString() const;
AutoIt:
    $oshape_predictor_training_options.ToString() -> retval
```

## dlib::simple\_object\_detector\_training\_options

### simple\_object\_detector\_training\_options.be\_verbose

```cpp
bool dlib::simple_object_detector_training_options::be_verbose
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.be_verbose
```

### simple\_object\_detector\_training\_options.add\_left\_right\_image\_flips

```cpp
bool dlib::simple_object_detector_training_options::add_left_right_image_flips
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.add_left_right_image_flips
```

### simple\_object\_detector\_training\_options.num\_threads

```cpp
ULONG dlib::simple_object_detector_training_options::num_threads
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.num_threads
```

### simple\_object\_detector\_training\_options.detection\_window\_size

```cpp
ULONG dlib::simple_object_detector_training_options::detection_window_size
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.detection_window_size
```

### simple\_object\_detector\_training\_options.C

```cpp
double dlib::simple_object_detector_training_options::C
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.C
```

### simple\_object\_detector\_training\_options.epsilon

```cpp
double dlib::simple_object_detector_training_options::epsilon
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.epsilon
```

### simple\_object\_detector\_training\_options.upsample\_limit

```cpp
ULONG dlib::simple_object_detector_training_options::upsample_limit
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.upsample_limit
```

### simple\_object\_detector\_training\_options.nuclear\_norm\_regularization\_strength

```cpp
double dlib::simple_object_detector_training_options::nuclear_norm_regularization_strength
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.nuclear_norm_regularization_strength
```

### simple\_object\_detector\_training\_options.max\_runtime\_seconds

```cpp
double dlib::simple_object_detector_training_options::max_runtime_seconds
AutoIt:
    [propget, propput] $osimple_object_detector_training_options.max_runtime_seconds
```

### dlib::simple\_object\_detector\_training\_options::get\_create

```cpp
static dlib::simple_object_detector_training_options dlib::simple_object_detector_training_options::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector_training_options").create() -> <dlib.simple_object_detector_training_options object>
```

### dlib::simple\_object\_detector\_training\_options::ToString

```cpp
std::string dlib::simple_object_detector_training_options::ToString() const;
AutoIt:
    $osimple_object_detector_training_options.ToString() -> retval
```

## dlib::simple\_test\_results

### simple\_test\_results.precision

```cpp
double dlib::simple_test_results::precision
AutoIt:
    [propget, propput] $osimple_test_results.precision
```

### simple\_test\_results.recall

```cpp
double dlib::simple_test_results::recall
AutoIt:
    [propget, propput] $osimple_test_results.recall
```

### simple\_test\_results.average\_precision

```cpp
double dlib::simple_test_results::average_precision
AutoIt:
    [propget, propput] $osimple_test_results.average_precision
```

### dlib::simple\_test\_results::get\_create

```cpp
static dlib::simple_test_results dlib::simple_test_results::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.simple_test_results").create() -> <dlib.simple_test_results object>
```

### dlib::simple\_test\_results::ToString

```cpp
std::string dlib::simple_test_results::ToString() const;
AutoIt:
    $osimple_test_results.ToString() -> retval
```

## dlib::simple\_object\_detector\_com

### simple\_object\_detector\_com.detector

```cpp
dlib::fhog_object_detector dlib::simple_object_detector_com::detector
AutoIt:
    [propget, propput] $osimple_object_detector_com.detector
```

### simple\_object\_detector\_com.upsampling\_amount

```cpp
uint dlib::simple_object_detector_com::upsampling_amount
AutoIt:
    [propget, propput] $osimple_object_detector_com.upsampling_amount
```

### simple\_object\_detector\_com.detection\_window\_width

```cpp
ULONG dlib::simple_object_detector_com::detector.get_scanner().get_detection_window_width()
AutoIt:
    [propget] $osimple_object_detector_com.detection_window_width
```

### simple\_object\_detector\_com.detection\_window\_height

```cpp
ULONG dlib::simple_object_detector_com::detector.get_scanner().get_detection_window_height()
AutoIt:
    [propget] $osimple_object_detector_com.detection_window_height
```

### simple\_object\_detector\_com.num\_detectors

```cpp
ULONG dlib::simple_object_detector_com::detector.num_detectors()
AutoIt:
    [propget] $osimple_object_detector_com.num_detectors
```

### dlib::simple\_object\_detector\_com::create

```cpp
static dlib::simple_object_detector_com dlib::simple_object_detector_com::create();
AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create() -> <dlib.simple_object_detector_com object>
```

```cpp
static dlib::simple_object_detector_com dlib::simple_object_detector_com::create( dlib::fhog_object_detector& _detector,
                                                                                  uint                        _upsampling_amount = 0 );
AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create( $_detector[, $_upsampling_amount] ) -> <dlib.simple_object_detector_com object>
```

```cpp
static dlib::simple_object_detector_com dlib::simple_object_detector_com::create( std::vector<dlib::simple_object_detector_com>& detectors );
AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create( $detectors ) -> <dlib.simple_object_detector_com object>
```

```cpp
static std::shared_ptr<dlib::simple_object_detector_com> dlib::simple_object_detector_com::create( const std::string& filename );
AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").create( $filename ) -> retval
```

### dlib::simple\_object\_detector\_com::get\_call

```cpp
std::vector<dlib::rectangle> dlib::simple_object_detector_com::get_call( cv::Mat&   img,
                                                                         const uint upsampling_amount_ );
AutoIt:
    $osimple_object_detector_com.call( $img, $upsampling_amount_ ) -> retval
    $osimple_object_detector_com( $img, $upsampling_amount_ ) -> retval
```

```cpp
std::vector<dlib::rectangle> dlib::simple_object_detector_com::get_call( cv::Mat& img );
AutoIt:
    $osimple_object_detector_com.call( $img ) -> retval
    $osimple_object_detector_com( $img ) -> retval
```

### dlib::simple\_object\_detector\_com::run\_multiple

```cpp
static void dlib::simple_object_detector_com::run_multiple( std::vector<dlib::fhog_object_detector> vectors,
                                                            cv::Mat                                 image,
                                                            std::vector<dlib::rectangle>            rectangles,
                                                            std::vector<double>                     detection_confidences,
                                                            std::vector<ULONG>                      weight_indices,
                                                            uint                                    upsample_num_times = 0,
                                                            double                                  adjust_threshold = 0.0 );
AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

```cpp
static void dlib::simple_object_detector_com::run_multiple( std::vector<dlib::simple_object_detector_com> vectors,
                                                            cv::Mat                                       image,
                                                            std::vector<dlib::rectangle>                  rectangles,
                                                            std::vector<double>                           detection_confidences,
                                                            std::vector<ULONG>                            weight_indices,
                                                            uint                                          upsample_num_times = 0,
                                                            double                                        adjust_threshold = 0.0 );
AutoIt:
    _Dlib_ObjCreate("dlib.simple_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

## dlib::simple\_structural\_svm\_problem

### simple\_structural\_svm\_problem.C

```cpp
double dlib::simple_structural_svm_problem::C
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.C
```

### simple\_structural\_svm\_problem.num\_samples

```cpp
long dlib::simple_structural_svm_problem::num_samples
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.num_samples
```

### simple\_structural\_svm\_problem.num\_dimensions

```cpp
long dlib::simple_structural_svm_problem::num_dimensions
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.num_dimensions
```

### simple\_structural\_svm\_problem.get\_truth\_joint\_feature\_vector

```cpp
get_truth_joint_feature_vector_function dlib::simple_structural_svm_problem::get_truth_joint_feature_vector
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.get_truth_joint_feature_vector
```

### simple\_structural\_svm\_problem.separation\_oracle

```cpp
separation_oracle_function dlib::simple_structural_svm_problem::separation_oracle
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.separation_oracle
```

### simple\_structural\_svm\_problem.epsilon

```cpp
double dlib::simple_structural_svm_problem::epsilon
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.epsilon
```

### simple\_structural\_svm\_problem.max\_cache\_size

```cpp
ULONG dlib::simple_structural_svm_problem::max_cache_size
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.max_cache_size
```

### simple\_structural\_svm\_problem.be\_verbose

```cpp
bool dlib::simple_structural_svm_problem::be_verbose
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.be_verbose
```

### simple\_structural\_svm\_problem.use\_sparse\_feature\_vectors

```cpp
bool dlib::simple_structural_svm_problem::use_sparse_feature_vectors
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.use_sparse_feature_vectors
```

### simple\_structural\_svm\_problem.learns\_nonnegative\_weights

```cpp
bool dlib::simple_structural_svm_problem::learns_nonnegative_weights
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.learns_nonnegative_weights
```

### simple\_structural\_svm\_problem.result

```cpp
_variant_t dlib::simple_structural_svm_problem::result
AutoIt:
    [propget, propput] $osimple_structural_svm_problem.result
```

### dlib::simple\_structural\_svm\_problem::get\_create

```cpp
static dlib::simple_structural_svm_problem dlib::simple_structural_svm_problem::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.structural_svm_problem").create() -> <dlib.simple_structural_svm_problem object>
```

## cv

### cv.cuda

```cpp
static cv::cuda
AutoIt:
    [propget] $ocv.cuda
```

### cv.\_InputArray

```cpp
static cv::_InputArray
AutoIt:
    [propget] $ocv._InputArray
```

### cv.\_OutputArray

```cpp
static cv::_OutputArray
AutoIt:
    [propget] $ocv._OutputArray
```

### cv.\_InputOutputArray

```cpp
static cv::_InputOutputArray
AutoIt:
    [propget] $ocv._InputOutputArray
```

### cv.Mat

```cpp
static cv::Mat
AutoIt:
    [propget] $ocv.Mat
```

### cv.Range

```cpp
static cv::Range
AutoIt:
    [propget] $ocv.Range
```

### cv.UMat

```cpp
static cv::UMat
AutoIt:
    [propget] $ocv.UMat
```

### cv::createMatFromBitmap

```cpp
cv::Mat cv::createMatFromBitmap( void* ptr,
                                 bool  copy = true );
AutoIt:
    _Dlib_ObjCreate("cv").createMatFromBitmap( $ptr[, $copy] ) -> retval
```

### cv::haveImageReader

```cpp
bool cv::haveImageReader( std::string filename );
AutoIt:
    _Dlib_ObjCreate("cv").haveImageReader( $filename ) -> retval
```

### cv::haveImageWriter

```cpp
bool cv::haveImageWriter( std::string filename );
AutoIt:
    _Dlib_ObjCreate("cv").haveImageWriter( $filename ) -> retval
```

### cv::imcount

```cpp
size_t cv::imcount( std::string filename,
                    int         flags = IMREAD_ANYCOLOR );
AutoIt:
    _Dlib_ObjCreate("cv").imcount( $filename[, $flags] ) -> retval
```

### cv::imdecode

```cpp
cv::Mat cv::imdecode( cv::Mat buf,
                      int     flags );
AutoIt:
    _Dlib_ObjCreate("cv").imdecode( $buf, $flags ) -> retval
```

### cv::imencode

```cpp
bool cv::imencode( std::string        ext,
                   cv::Mat            img,
                   std::vector<uchar> buf,
                   std::vector<int>   params = std::vector<int>() );
AutoIt:
    _Dlib_ObjCreate("cv").imencode( $ext, $img[, $params[, $buf]] ) -> retval, $buf
```

### cv::imread

```cpp
cv::Mat cv::imread( std::string filename,
                    int         flags = IMREAD_COLOR );
AutoIt:
    _Dlib_ObjCreate("cv").imread( $filename[, $flags] ) -> retval
```

### cv::imreadmulti

```cpp
bool cv::imreadmulti( std::string          filename,
                      std::vector<cv::Mat> mats,
                      int                  flags = IMREAD_ANYCOLOR );
AutoIt:
    _Dlib_ObjCreate("cv").imreadmulti( $filename[, $flags[, $mats]] ) -> retval, $mats
```

```cpp
bool cv::imreadmulti( std::string          filename,
                      std::vector<cv::Mat> mats,
                      int                  start,
                      int                  count,
                      int                  flags = IMREAD_ANYCOLOR );
AutoIt:
    _Dlib_ObjCreate("cv").imreadmulti( $filename, $start, $count[, $flags[, $mats]] ) -> retval, $mats
```

### cv::imwrite

```cpp
bool cv::imwrite( std::string      filename,
                  cv::Mat          img,
                  std::vector<int> params = std::vector<int>() );
AutoIt:
    _Dlib_ObjCreate("cv").imwrite( $filename, $img[, $params] ) -> retval
```

### cv::imwritemulti

```cpp
bool cv::imwritemulti( std::string          filename,
                       std::vector<cv::Mat> img,
                       std::vector<int>     params = std::vector<int>() );
AutoIt:
    _Dlib_ObjCreate("cv").imwritemulti( $filename, $img[, $params] ) -> retval
```

### cv.ACCESS\_READ\_

```cpp
static int cv::ACCESS_READ
AutoIt:
    [propget] $ocv.ACCESS_READ_
```

### cv.ACCESS\_WRITE\_

```cpp
static int cv::ACCESS_WRITE
AutoIt:
    [propget] $ocv.ACCESS_WRITE_
```

### cv.ACCESS\_RW\_

```cpp
static int cv::ACCESS_RW
AutoIt:
    [propget] $ocv.ACCESS_RW_
```

### cv.ACCESS\_MASK\_

```cpp
static int cv::ACCESS_MASK
AutoIt:
    [propget] $ocv.ACCESS_MASK_
```

### cv.ACCESS\_FAST\_

```cpp
static int cv::ACCESS_FAST
AutoIt:
    [propget] $ocv.ACCESS_FAST_
```

### cv.USAGE\_DEFAULT\_

```cpp
static int cv::USAGE_DEFAULT
AutoIt:
    [propget] $ocv.USAGE_DEFAULT_
```

### cv.USAGE\_ALLOCATE\_HOST\_MEMORY\_

```cpp
static int cv::USAGE_ALLOCATE_HOST_MEMORY
AutoIt:
    [propget] $ocv.USAGE_ALLOCATE_HOST_MEMORY_
```

### cv.USAGE\_ALLOCATE\_DEVICE\_MEMORY\_

```cpp
static int cv::USAGE_ALLOCATE_DEVICE_MEMORY
AutoIt:
    [propget] $ocv.USAGE_ALLOCATE_DEVICE_MEMORY_
```

### cv.USAGE\_ALLOCATE\_SHARED\_MEMORY\_

```cpp
static int cv::USAGE_ALLOCATE_SHARED_MEMORY
AutoIt:
    [propget] $ocv.USAGE_ALLOCATE_SHARED_MEMORY_
```

### cv.\_\_UMAT\_USAGE\_FLAGS\_32BIT\_

```cpp
static int cv::__UMAT_USAGE_FLAGS_32BIT
AutoIt:
    [propget] $ocv.__UMAT_USAGE_FLAGS_32BIT_
```

## dlib::mmod\_rect

### mmod\_rect.rect

```cpp
dlib::rectangle dlib::mmod_rect::rect
AutoIt:
    [propget, propput] $ommod_rect.rect
```

### mmod\_rect.confidence

```cpp
double dlib::mmod_rect::detection_confidence
AutoIt:
    [propget, propput] $ommod_rect.confidence
```

### mmod\_rect.label

```cpp
std::string dlib::mmod_rect::label
AutoIt:
    [propget, propput] $ommod_rect.label
```

### mmod\_rect.ignore

```cpp
bool dlib::mmod_rect::ignore
AutoIt:
    [propget, propput] $ommod_rect.ignore
```

### dlib::mmod\_rect::get\_create

```cpp
static dlib::mmod_rect dlib::mmod_rect::get_create( dlib::rectangle rect = rectangle(),
                                                    double          detection_confidence = 0,
                                                    std::string     label = string() );
AutoIt:
    _Dlib_ObjCreate("dlib.mmod_rectangle").create( [$rect[, $detection_confidence[, $label]]] ) -> <dlib.mmod_rect object>
    $ommod_rect( [$rect[, $detection_confidence[, $label]]] ) -> <dlib.mmod_rect object>
```

## dlib::cuda

### dlib::cuda::can\_access\_peer

```cpp
bool dlib::cuda::can_access_peer( int device_id,
                                  int peer_device_id );
AutoIt:
    _Dlib_ObjCreate("dlib.cuda").can_access_peer( $device_id, $peer_device_id ) -> retval
```

### dlib::cuda::device\_synchronize

```cpp
void dlib::cuda::device_synchronize( int device_id );
AutoIt:
    _Dlib_ObjCreate("dlib.cuda").device_synchronize( $device_id ) -> None
```

### dlib::cuda::get\_device

```cpp
int dlib::cuda::get_device();
AutoIt:
    _Dlib_ObjCreate("dlib.cuda").get_device() -> retval
```

### dlib::cuda::get\_device\_name

```cpp
std::string dlib::cuda::get_device_name( int device );
AutoIt:
    _Dlib_ObjCreate("dlib.cuda").get_device_name( $device ) -> retval
```

### dlib::cuda::set\_current\_device\_blocking\_sync

```cpp
void dlib::cuda::set_current_device_blocking_sync();
AutoIt:
    _Dlib_ObjCreate("dlib.cuda").set_current_device_blocking_sync() -> None
```

### dlib::cuda::set\_device

```cpp
void dlib::cuda::set_device( int device );
AutoIt:
    _Dlib_ObjCreate("dlib.cuda").set_device( $device ) -> None
```

## dlib::correlation\_tracker

### dlib::correlation\_tracker::get\_create

```cpp
static dlib::correlation_tracker dlib::correlation_tracker::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.correlation_tracker").create() -> <dlib.correlation_tracker object>
```

### dlib::correlation\_tracker::get\_position

```cpp
dlib::drectangle dlib::correlation_tracker::get_position();
AutoIt:
    $ocorrelation_tracker.get_position() -> retval
```

### dlib::correlation\_tracker::start\_track

```cpp
void dlib::correlation_tracker::start_track( cv::Mat          image,
                                             dlib::drectangle bounding_box );
AutoIt:
    $ocorrelation_tracker.start_track( $image, $bounding_box ) -> None
```

```cpp
void dlib::correlation_tracker::start_track( cv::Mat         image,
                                             dlib::rectangle bounding_box );
AutoIt:
    $ocorrelation_tracker.start_track( $image, $bounding_box ) -> None
```

### dlib::correlation\_tracker::update

```cpp
double dlib::correlation_tracker::update( cv::Mat image );
AutoIt:
    $ocorrelation_tracker.update( $image ) -> retval
```

```cpp
double dlib::correlation_tracker::update( cv::Mat          image,
                                          dlib::drectangle bounding_box );
AutoIt:
    $ocorrelation_tracker.update( $image, $bounding_box ) -> retval
```

```cpp
double dlib::correlation_tracker::update( cv::Mat         image,
                                          dlib::rectangle bounding_box );
AutoIt:
    $ocorrelation_tracker.update( $image, $bounding_box ) -> retval
```

## cv::cuda

### cuda.GpuMat

```cpp
static cv::cuda::GpuMat
AutoIt:
    [propget] $ocuda.GpuMat
```

## dlib::\_radial\_basis\_kernel

### \_radial\_basis\_kernel.gamma

```cpp
double dlib::_radial_basis_kernel::gamma
AutoIt:
    [propget] $o_radial_basis_kernel.gamma
```

### dlib::\_radial\_basis\_kernel::get\_create

```cpp
static dlib::_radial_basis_kernel dlib::_radial_basis_kernel::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib._radial_basis_kernel").create() -> <dlib._radial_basis_kernel object>
```

## dlib::\_linear\_kernel

### dlib::\_linear\_kernel::get\_create

```cpp
static dlib::_linear_kernel dlib::_linear_kernel::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib._linear_kernel").create() -> <dlib._linear_kernel object>
```

## dlib::\_decision\_function\_linear

### \_decision\_function\_linear.weights

```cpp
dlib::SpaceVector dlib::_decision_function_linear::weights
AutoIt:
    [propget] $o_decision_function_linear.weights
```

### \_decision\_function\_linear.bias

```cpp
double dlib::_decision_function_linear::bias
AutoIt:
    [propget, propput] $o_decision_function_linear.bias
```

### dlib::\_decision\_function\_linear::create

```cpp
static dlib::_decision_function_linear dlib::_decision_function_linear::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_linear").create() -> <dlib._decision_function_linear object>
```

### dlib::\_decision\_function\_linear::get\_call

```cpp
double dlib::_decision_function_linear::get_call( dlib::SpaceVector sample );
AutoIt:
    $o_decision_function_linear.call( $sample ) -> retval
    $o_decision_function_linear( $sample ) -> retval
```

## dlib::\_decision\_function\_sparse\_linear

### \_decision\_function\_sparse\_linear.weights

```cpp
std::vector<std::pair<ULONG, double>> dlib::_decision_function_sparse_linear::weights
AutoIt:
    [propget] $o_decision_function_sparse_linear.weights
```

### \_decision\_function\_sparse\_linear.bias

```cpp
double dlib::_decision_function_sparse_linear::bias
AutoIt:
    [propget, propput] $o_decision_function_sparse_linear.bias
```

### dlib::\_decision\_function\_sparse\_linear::create

```cpp
static dlib::_decision_function_sparse_linear dlib::_decision_function_sparse_linear::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_linear").create() -> <dlib._decision_function_sparse_linear object>
```

### dlib::\_decision\_function\_sparse\_linear::get\_call

```cpp
double dlib::_decision_function_sparse_linear::get_call( std::vector<std::pair<ULONG, double>> sample );
AutoIt:
    $o_decision_function_sparse_linear.call( $sample ) -> retval
    $o_decision_function_sparse_linear( $sample ) -> retval
```

## dlib::\_decision\_function\_histogram\_intersection

### \_decision\_function\_histogram\_intersection.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_histogram_intersection::alpha
AutoIt:
    [propget] $o_decision_function_histogram_intersection.alpha
```

### \_decision\_function\_histogram\_intersection.b

```cpp
double dlib::_decision_function_histogram_intersection::b
AutoIt:
    [propget] $o_decision_function_histogram_intersection.b
```

### \_decision\_function\_histogram\_intersection.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_histogram_intersection::basis_vectors
AutoIt:
    [propget] $o_decision_function_histogram_intersection.basis_vectors
```

### dlib::\_decision\_function\_histogram\_intersection::create

```cpp
static dlib::_decision_function_histogram_intersection dlib::_decision_function_histogram_intersection::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_histogram_intersection").create() -> <dlib._decision_function_histogram_intersection object>
```

### dlib::\_decision\_function\_histogram\_intersection::get\_call

```cpp
double dlib::_decision_function_histogram_intersection::get_call( dlib::SpaceVector sample );
AutoIt:
    $o_decision_function_histogram_intersection.call( $sample ) -> retval
    $o_decision_function_histogram_intersection( $sample ) -> retval
```

## dlib::\_decision\_function\_sparse\_histogram\_intersection

### \_decision\_function\_sparse\_histogram\_intersection.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_sparse_histogram_intersection::alpha
AutoIt:
    [propget] $o_decision_function_sparse_histogram_intersection.alpha
```

### \_decision\_function\_sparse\_histogram\_intersection.b

```cpp
double dlib::_decision_function_sparse_histogram_intersection::b
AutoIt:
    [propget] $o_decision_function_sparse_histogram_intersection.b
```

### \_decision\_function\_sparse\_histogram\_intersection.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_sparse_histogram_intersection::basis_vectors
AutoIt:
    [propget] $o_decision_function_sparse_histogram_intersection.basis_vectors
```

### dlib::\_decision\_function\_sparse\_histogram\_intersection::create

```cpp
static dlib::_decision_function_sparse_histogram_intersection dlib::_decision_function_sparse_histogram_intersection::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_histogram_intersection").create() -> <dlib._decision_function_sparse_histogram_intersection object>
```

### dlib::\_decision\_function\_sparse\_histogram\_intersection::get\_call

```cpp
double dlib::_decision_function_sparse_histogram_intersection::get_call( std::vector<std::pair<ULONG, double>> sample );
AutoIt:
    $o_decision_function_sparse_histogram_intersection.call( $sample ) -> retval
    $o_decision_function_sparse_histogram_intersection( $sample ) -> retval
```

## dlib::\_decision\_function\_polynomial

### \_decision\_function\_polynomial.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_polynomial::alpha
AutoIt:
    [propget] $o_decision_function_polynomial.alpha
```

### \_decision\_function\_polynomial.b

```cpp
double dlib::_decision_function_polynomial::b
AutoIt:
    [propget] $o_decision_function_polynomial.b
```

### \_decision\_function\_polynomial.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_polynomial::basis_vectors
AutoIt:
    [propget] $o_decision_function_polynomial.basis_vectors
```

### dlib::\_decision\_function\_polynomial::create

```cpp
static dlib::_decision_function_polynomial dlib::_decision_function_polynomial::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_polynomial").create() -> <dlib._decision_function_polynomial object>
```

### dlib::\_decision\_function\_polynomial::get\_call

```cpp
double dlib::_decision_function_polynomial::get_call( dlib::SpaceVector sample );
AutoIt:
    $o_decision_function_polynomial.call( $sample ) -> retval
    $o_decision_function_polynomial( $sample ) -> retval
```

## dlib::\_decision\_function\_sparse\_polynomial

### \_decision\_function\_sparse\_polynomial.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_sparse_polynomial::alpha
AutoIt:
    [propget] $o_decision_function_sparse_polynomial.alpha
```

### \_decision\_function\_sparse\_polynomial.b

```cpp
double dlib::_decision_function_sparse_polynomial::b
AutoIt:
    [propget] $o_decision_function_sparse_polynomial.b
```

### \_decision\_function\_sparse\_polynomial.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_sparse_polynomial::basis_vectors
AutoIt:
    [propget] $o_decision_function_sparse_polynomial.basis_vectors
```

### dlib::\_decision\_function\_sparse\_polynomial::create

```cpp
static dlib::_decision_function_sparse_polynomial dlib::_decision_function_sparse_polynomial::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_polynomial").create() -> <dlib._decision_function_sparse_polynomial object>
```

### dlib::\_decision\_function\_sparse\_polynomial::get\_call

```cpp
double dlib::_decision_function_sparse_polynomial::get_call( std::vector<std::pair<ULONG, double>> sample );
AutoIt:
    $o_decision_function_sparse_polynomial.call( $sample ) -> retval
    $o_decision_function_sparse_polynomial( $sample ) -> retval
```

## dlib::\_decision\_function\_radial\_basis

### \_decision\_function\_radial\_basis.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_radial_basis::alpha
AutoIt:
    [propget] $o_decision_function_radial_basis.alpha
```

### \_decision\_function\_radial\_basis.b

```cpp
double dlib::_decision_function_radial_basis::b
AutoIt:
    [propget] $o_decision_function_radial_basis.b
```

### \_decision\_function\_radial\_basis.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_radial_basis::basis_vectors
AutoIt:
    [propget] $o_decision_function_radial_basis.basis_vectors
```

### dlib::\_decision\_function\_radial\_basis::create

```cpp
static dlib::_decision_function_radial_basis dlib::_decision_function_radial_basis::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_radial_basis").create() -> <dlib._decision_function_radial_basis object>
```

### dlib::\_decision\_function\_radial\_basis::get\_call

```cpp
double dlib::_decision_function_radial_basis::get_call( dlib::SpaceVector sample );
AutoIt:
    $o_decision_function_radial_basis.call( $sample ) -> retval
    $o_decision_function_radial_basis( $sample ) -> retval
```

## dlib::\_decision\_function\_sparse\_radial\_basis

### \_decision\_function\_sparse\_radial\_basis.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_sparse_radial_basis::alpha
AutoIt:
    [propget] $o_decision_function_sparse_radial_basis.alpha
```

### \_decision\_function\_sparse\_radial\_basis.b

```cpp
double dlib::_decision_function_sparse_radial_basis::b
AutoIt:
    [propget] $o_decision_function_sparse_radial_basis.b
```

### \_decision\_function\_sparse\_radial\_basis.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_sparse_radial_basis::basis_vectors
AutoIt:
    [propget] $o_decision_function_sparse_radial_basis.basis_vectors
```

### dlib::\_decision\_function\_sparse\_radial\_basis::create

```cpp
static dlib::_decision_function_sparse_radial_basis dlib::_decision_function_sparse_radial_basis::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_radial_basis").create() -> <dlib._decision_function_sparse_radial_basis object>
```

### dlib::\_decision\_function\_sparse\_radial\_basis::get\_call

```cpp
double dlib::_decision_function_sparse_radial_basis::get_call( std::vector<std::pair<ULONG, double>> sample );
AutoIt:
    $o_decision_function_sparse_radial_basis.call( $sample ) -> retval
    $o_decision_function_sparse_radial_basis( $sample ) -> retval
```

## dlib::\_decision\_function\_sigmoid

### \_decision\_function\_sigmoid.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_sigmoid::alpha
AutoIt:
    [propget] $o_decision_function_sigmoid.alpha
```

### \_decision\_function\_sigmoid.b

```cpp
double dlib::_decision_function_sigmoid::b
AutoIt:
    [propget] $o_decision_function_sigmoid.b
```

### \_decision\_function\_sigmoid.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_sigmoid::basis_vectors
AutoIt:
    [propget] $o_decision_function_sigmoid.basis_vectors
```

### dlib::\_decision\_function\_sigmoid::create

```cpp
static dlib::_decision_function_sigmoid dlib::_decision_function_sigmoid::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sigmoid").create() -> <dlib._decision_function_sigmoid object>
```

### dlib::\_decision\_function\_sigmoid::get\_call

```cpp
double dlib::_decision_function_sigmoid::get_call( dlib::SpaceVector sample );
AutoIt:
    $o_decision_function_sigmoid.call( $sample ) -> retval
    $o_decision_function_sigmoid( $sample ) -> retval
```

## dlib::\_decision\_function\_sparse\_sigmoid

### \_decision\_function\_sparse\_sigmoid.alpha

```cpp
dlib::SpaceVector dlib::_decision_function_sparse_sigmoid::alpha
AutoIt:
    [propget] $o_decision_function_sparse_sigmoid.alpha
```

### \_decision\_function\_sparse\_sigmoid.b

```cpp
double dlib::_decision_function_sparse_sigmoid::b
AutoIt:
    [propget] $o_decision_function_sparse_sigmoid.b
```

### \_decision\_function\_sparse\_sigmoid.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_decision_function_sparse_sigmoid::basis_vectors
AutoIt:
    [propget] $o_decision_function_sparse_sigmoid.basis_vectors
```

### dlib::\_decision\_function\_sparse\_sigmoid::create

```cpp
static dlib::_decision_function_sparse_sigmoid dlib::_decision_function_sparse_sigmoid::create();
AutoIt:
    _Dlib_ObjCreate("dlib._decision_function_sparse_sigmoid").create() -> <dlib._decision_function_sparse_sigmoid object>
```

### dlib::\_decision\_function\_sparse\_sigmoid::get\_call

```cpp
double dlib::_decision_function_sparse_sigmoid::get_call( std::vector<std::pair<ULONG, double>> sample );
AutoIt:
    $o_decision_function_sparse_sigmoid.call( $sample ) -> retval
    $o_decision_function_sparse_sigmoid( $sample ) -> retval
```

## dlib::\_normalized\_decision\_function\_radial\_basis

### \_normalized\_decision\_function\_radial\_basis.alpha

```cpp
dlib::SpaceVector dlib::_normalized_decision_function_radial_basis::function.alpha
AutoIt:
    [propget] $o_normalized_decision_function_radial_basis.alpha
```

### \_normalized\_decision\_function\_radial\_basis.b

```cpp
double dlib::_normalized_decision_function_radial_basis::function.b
AutoIt:
    [propget] $o_normalized_decision_function_radial_basis.b
```

### \_normalized\_decision\_function\_radial\_basis.basis\_vectors

```cpp
std::vector<dlib::SpaceVector> dlib::_normalized_decision_function_radial_basis::basis_vectors
AutoIt:
    [propget] $o_normalized_decision_function_radial_basis.basis_vectors
```

### \_normalized\_decision\_function\_radial\_basis.means

```cpp
dlib::SpaceVector dlib::_normalized_decision_function_radial_basis::normalizer.means()
AutoIt:
    [propget] $o_normalized_decision_function_radial_basis.means
```

### \_normalized\_decision\_function\_radial\_basis.invstd\_devs

```cpp
dlib::SpaceVector dlib::_normalized_decision_function_radial_basis::normalizer.std_devs()
AutoIt:
    [propget] $o_normalized_decision_function_radial_basis.invstd_devs
```

### dlib::\_normalized\_decision\_function\_radial\_basis::create

```cpp
static dlib::_normalized_decision_function_radial_basis dlib::_normalized_decision_function_radial_basis::create();
AutoIt:
    _Dlib_ObjCreate("dlib._normalized_decision_function_radial_basis").create() -> <dlib._normalized_decision_function_radial_basis object>
```

### dlib::\_normalized\_decision\_function\_radial\_basis::batch\_predict

```cpp
std::vector<double> dlib::_normalized_decision_function_radial_basis::batch_predict( std::vector<dlib::SpaceVector>& samples );
AutoIt:
    $o_normalized_decision_function_radial_basis.batch_predict( $samples ) -> retval
```

```cpp
std::vector<double> dlib::_normalized_decision_function_radial_basis::batch_predict( cv::Mat& samples );
AutoIt:
    $o_normalized_decision_function_radial_basis.batch_predict( $samples ) -> retval
```

### dlib::\_normalized\_decision\_function\_radial\_basis::get\_call

```cpp
double dlib::_normalized_decision_function_radial_basis::get_call( dlib::SpaceVector& sample );
AutoIt:
    $o_normalized_decision_function_radial_basis.call( $sample ) -> retval
    $o_normalized_decision_function_radial_basis( $sample ) -> retval
```

## dlib::function\_evaluation

### function\_evaluation.x

```cpp
dlib::SpaceVector dlib::function_evaluation::x
AutoIt:
    [propget] $ofunction_evaluation.x
```

### function\_evaluation.y

```cpp
double dlib::function_evaluation::y
AutoIt:
    [propget] $ofunction_evaluation.y
```

### dlib::function\_evaluation::get\_create

```cpp
static dlib::function_evaluation dlib::function_evaluation::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.function_evaluation").create() -> <dlib.function_evaluation object>
```

```cpp
static dlib::function_evaluation dlib::function_evaluation::get_create( dlib::SpaceVector x,
                                                                        double            y );
AutoIt:
    _Dlib_ObjCreate("dlib.function_evaluation").create( $x, $y ) -> <dlib.function_evaluation object>
    $ofunction_evaluation( $x, $y ) -> <dlib.function_evaluation object>
```

```cpp
static dlib::function_evaluation dlib::function_evaluation::get_create( std::vector<double> x,
                                                                        double              y );
AutoIt:
    _Dlib_ObjCreate("dlib.function_evaluation").create( $x, $y ) -> <dlib.function_evaluation object>
    $ofunction_evaluation( $x, $y ) -> <dlib.function_evaluation object>
```

## dlib::function\_spec

### function\_spec.lower

```cpp
dlib::SpaceVector dlib::function_spec::lower
AutoIt:
    [propget] $ofunction_spec.lower
```

### function\_spec.upper

```cpp
dlib::SpaceVector dlib::function_spec::upper
AutoIt:
    [propget] $ofunction_spec.upper
```

### function\_spec.is\_integer\_variable

```cpp
std::vector<bool> dlib::function_spec::is_integer_variable
AutoIt:
    [propget] $ofunction_spec.is_integer_variable
```

### dlib::function\_spec::get\_create

```cpp
static dlib::function_spec dlib::function_spec::get_create( dlib::SpaceVector bound1,
                                                            dlib::SpaceVector bound2 );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::get_create( dlib::SpaceVector bound1,
                                                            dlib::SpaceVector bound2,
                                                            std::vector<bool> is_integer );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::get_create( std::vector<double> bound1,
                                                            dlib::SpaceVector   bound2 );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::get_create( std::vector<double> bound1,
                                                            dlib::SpaceVector   bound2,
                                                            std::vector<bool>   is_integer );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::get_create( dlib::SpaceVector   bound1,
                                                            std::vector<double> bound2 );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::get_create( dlib::SpaceVector   bound1,
                                                            std::vector<double> bound2,
                                                            std::vector<bool>   is_integer );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::get_create( std::vector<double> bound1,
                                                            std::vector<double> bound2 );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2 ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2 ) -> <dlib.function_spec object>
```

```cpp
static dlib::function_spec dlib::function_spec::get_create( std::vector<double> bound1,
                                                            std::vector<double> bound2,
                                                            std::vector<bool>   is_integer );
AutoIt:
    _Dlib_ObjCreate("dlib.function_spec").create( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
    $ofunction_spec( $bound1, $bound2, $is_integer ) -> <dlib.function_spec object>
```

## dlib::function\_evaluation\_request

### function\_evaluation\_request.function\_idx

```cpp
size_t dlib::function_evaluation_request::function_idx
AutoIt:
    [propget] $ofunction_evaluation_request.function_idx
```

### function\_evaluation\_request.x

```cpp
dlib::SpaceVector dlib::function_evaluation_request::x
AutoIt:
    [propget] $ofunction_evaluation_request.x
```

### function\_evaluation\_request.has\_been\_evaluated

```cpp
bool dlib::function_evaluation_request::has_been_evaluated
AutoIt:
    [propget] $ofunction_evaluation_request.has_been_evaluated
```

### dlib::function\_evaluation\_request::set

```cpp
void dlib::function_evaluation_request::set( double y );
AutoIt:
    $ofunction_evaluation_request.set( $y ) -> None
```

## dlib::global\_function\_search

### dlib::global\_function\_search::get\_create

```cpp
static dlib::global_function_search dlib::global_function_search::get_create( dlib::function_spec& function );
AutoIt:
    _Dlib_ObjCreate("dlib.global_function_search").create( $function ) -> <dlib.global_function_search object>
    $oglobal_function_search( $function ) -> <dlib.global_function_search object>
```

```cpp
static dlib::global_function_search dlib::global_function_search::get_create( std::vector<dlib::function_spec>& functions );
AutoIt:
    _Dlib_ObjCreate("dlib.global_function_search").create( $functions ) -> <dlib.global_function_search object>
    $oglobal_function_search( $functions ) -> <dlib.global_function_search object>
```

```cpp
static dlib::global_function_search dlib::global_function_search::get_create( std::vector<dlib::function_spec>                    functions,
                                                                              std::vector<std::vector<dlib::function_evaluation>> initial_function_evals,
                                                                              double                                              relative_noise_magnitude = 0.001 );
AutoIt:
    _Dlib_ObjCreate("dlib.global_function_search").create( $functions, $initial_function_evals[, $relative_noise_magnitude] ) -> <dlib.global_function_search object>
    $oglobal_function_search( $functions, $initial_function_evals[, $relative_noise_magnitude] ) -> <dlib.global_function_search object>
```

### dlib::global\_function\_search::get\_best\_function\_eval

```cpp
void dlib::global_function_search::get_best_function_eval( dlib::SpaceVector& x,
                                                           double&            y,
                                                           size_t&            idx );
AutoIt:
    $oglobal_function_search.get_best_function_eval( [$x[, $y[, $idx]]] ) -> $x, $y, $idx
```

### dlib::global\_function\_search::get\_function\_evaluations

```cpp
void dlib::global_function_search::get_function_evaluations( std::vector<dlib::function_spec>                    specs,
                                                             std::vector<std::vector<dlib::function_evaluation>> function_evals );
AutoIt:
    $oglobal_function_search.get_function_evaluations( [$specs[, $function_evals]] ) -> $specs, $function_evals
```

### dlib::global\_function\_search::get\_monte\_carlo\_upper\_bound\_sample\_num

```cpp
size_t dlib::global_function_search::get_monte_carlo_upper_bound_sample_num();
AutoIt:
    $oglobal_function_search.get_monte_carlo_upper_bound_sample_num() -> retval
```

### dlib::global\_function\_search::get\_next\_x

```cpp
std::shared_ptr<dlib::function_evaluation_request> dlib::global_function_search::get_next_x();
AutoIt:
    $oglobal_function_search.get_next_x() -> retval
```

### dlib::global\_function\_search::get\_pure\_random\_search\_probability

```cpp
double dlib::global_function_search::get_pure_random_search_probability();
AutoIt:
    $oglobal_function_search.get_pure_random_search_probability() -> retval
```

### dlib::global\_function\_search::get\_relative\_noise\_magnitude

```cpp
double dlib::global_function_search::get_relative_noise_magnitude();
AutoIt:
    $oglobal_function_search.get_relative_noise_magnitude() -> retval
```

### dlib::global\_function\_search::get\_solver\_epsilon

```cpp
double dlib::global_function_search::get_solver_epsilon();
AutoIt:
    $oglobal_function_search.get_solver_epsilon() -> retval
```

### dlib::global\_function\_search::num\_functions

```cpp
size_t dlib::global_function_search::num_functions();
AutoIt:
    $oglobal_function_search.num_functions() -> retval
```

### dlib::global\_function\_search::set\_monte\_carlo\_upper\_bound\_sample\_num

```cpp
void dlib::global_function_search::set_monte_carlo_upper_bound_sample_num( size_t num );
AutoIt:
    $oglobal_function_search.set_monte_carlo_upper_bound_sample_num( $num ) -> None
```

### dlib::global\_function\_search::set\_pure\_random\_search\_probability

```cpp
void dlib::global_function_search::set_pure_random_search_probability( double prob );
AutoIt:
    $oglobal_function_search.set_pure_random_search_probability( $prob ) -> None
```

### dlib::global\_function\_search::set\_relative\_noise\_magnitude

```cpp
void dlib::global_function_search::set_relative_noise_magnitude( double value );
AutoIt:
    $oglobal_function_search.set_relative_noise_magnitude( $value ) -> None
```

### dlib::global\_function\_search::set\_seed

```cpp
void dlib::global_function_search::set_seed( LONGLONG seed );
AutoIt:
    $oglobal_function_search.set_seed( $seed ) -> None
```

### dlib::global\_function\_search::set\_solver\_epsilon

```cpp
void dlib::global_function_search::set_solver_epsilon( double eps );
AutoIt:
    $oglobal_function_search.set_solver_epsilon( $eps ) -> None
```

## dlib::image\_window

### dlib::image\_window::get\_create

```cpp
static dlib::image_window dlib::image_window::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.image_window").create() -> <dlib.image_window object>
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::get_create( dlib::fhog_object_detector& detector );
AutoIt:
    $oimage_window.create( $detector ) -> retval
    $oimage_window( $detector ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::get_create( dlib::simple_object_detector_com& detector );
AutoIt:
    $oimage_window.create( $detector ) -> retval
    $oimage_window( $detector ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::get_create( dlib::fhog_object_detector& detector,
                                                                    std::string                 title );
AutoIt:
    $oimage_window.create( $detector, $title ) -> retval
    $oimage_window( $detector, $title ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::get_create( dlib::simple_object_detector_com& detector,
                                                                    std::string                       title );
AutoIt:
    $oimage_window.create( $detector, $title ) -> retval
    $oimage_window( $detector, $title ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::get_create( cv::Mat& img );
AutoIt:
    $oimage_window.create( $img ) -> retval
    $oimage_window( $img ) -> retval
```

```cpp
std::shared_ptr<dlib::image_window> dlib::image_window::get_create( cv::Mat&    img,
                                                                    std::string title );
AutoIt:
    $oimage_window.create( $img, $title ) -> retval
    $oimage_window( $img, $title ) -> retval
```

### dlib::image\_window::add\_overlay

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::rectangle> rectangles,
                                      dlib::rgb_pixel              color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay( $rectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::rectangle>    rectangles,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay( $rectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::drectangle> drectangles,
                                      dlib::rgb_pixel               color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay( $drectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<dlib::drectangle>   drectangles,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay( $drectangles[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<_variant_t> objs,
                                      dlib::rgb_pixel         color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay( $objs[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( std::vector<_variant_t>         objs,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay( $objs[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::rectangle rect,
                                      dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay( $rect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::rectangle                 rect,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay( $rect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::drectangle drect,
                                      dlib::rgb_pixel  color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay( $drect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::drectangle                drect,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay( $drect[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::full_object_detection& detection,
                                      dlib::rgb_pixel              color = rgb_pixel(0, 0, 255) );
AutoIt:
    $oimage_window.add_overlay( $detection[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::full_object_detection&    detection,
                                      std::tuple<uchar, uchar, uchar> color = {0, 0, 255} );
AutoIt:
    $oimage_window.add_overlay( $detection[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::line      l,
                                      dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay( $l[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay( dlib::line                      l,
                                      std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay( $l[, $color] ) -> None
```

### dlib::image\_window::add\_overlay\_circle

```cpp
void dlib::image_window::add_overlay_circle( dlib::point     center,
                                             double          radius,
                                             dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay_circle( dlib::point                     center,
                                             double                          radius,
                                             std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay_circle( dlib::dpoint    center,
                                             double          radius,
                                             dlib::rgb_pixel color = rgb_pixel(255, 0, 0) );
AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

```cpp
void dlib::image_window::add_overlay_circle( dlib::dpoint                    center,
                                             double                          radius,
                                             std::tuple<uchar, uchar, uchar> color = {255, 0, 0} );
AutoIt:
    $oimage_window.add_overlay_circle( $center, $radius[, $color] ) -> None
```

### dlib::image\_window::clear\_overlay

```cpp
void dlib::image_window::clear_overlay();
AutoIt:
    $oimage_window.clear_overlay() -> None
```

### dlib::image\_window::get\_next\_double\_click

```cpp
bool dlib::image_window::get_next_double_click( dlib::point p );
AutoIt:
    $oimage_window.get_next_double_click( [$p] ) -> retval, $p
```

### dlib::image\_window::get\_next\_keypress

```cpp
bool dlib::image_window::get_next_keypress( char*                                                 key,
                                            bool*                                                 is_printable,
                                            std::vector<dlib::image_window::keyboard_state_masks> mods,
                                            bool                                                  get_keyboard_modifiers = false );
AutoIt:
    $oimage_window.get_next_keypress( [$get_keyboard_modifiers[, $key[, $is_printable[, $mods]]]] ) -> retval, $key, $is_printable, $mods
```

### dlib::image\_window::is\_closed

```cpp
bool dlib::image_window::is_closed();
AutoIt:
    $oimage_window.is_closed() -> retval
```

### dlib::image\_window::set\_image

```cpp
void dlib::image_window::set_image( dlib::fhog_object_detector& detector );
AutoIt:
    $oimage_window.set_image( $detector ) -> None
```

```cpp
void dlib::image_window::set_image( dlib::simple_object_detector_com& detector );
AutoIt:
    $oimage_window.set_image( $detector ) -> None
```

```cpp
void dlib::image_window::set_image( cv::Mat& img );
AutoIt:
    $oimage_window.set_image( $img ) -> None
```

### dlib::image\_window::set\_title

```cpp
void dlib::image_window::set_title( std::string title );
AutoIt:
    $oimage_window.set_title( $title ) -> None
```

### dlib::image\_window::wait\_for\_keypress

```cpp
void dlib::image_window::wait_for_keypress( char wait_key );
AutoIt:
    $oimage_window.wait_for_keypress( $wait_key ) -> None
```

```cpp
void dlib::image_window::wait_for_keypress( std::string wait_key );
AutoIt:
    $oimage_window.wait_for_keypress( $wait_key ) -> None
```

### dlib::image\_window::wait\_until\_closed

```cpp
void dlib::image_window::wait_until_closed();
AutoIt:
    $oimage_window.wait_until_closed() -> None
```

### image\_window.KBD\_MOD\_NONE\_

```cpp
static int dlib::image_window::KBD_MOD_NONE
AutoIt:
    [propget] $oimage_window.KBD_MOD_NONE_
```

### image\_window.KBD\_MOD\_SHIFT\_

```cpp
static int dlib::image_window::KBD_MOD_SHIFT
AutoIt:
    [propget] $oimage_window.KBD_MOD_SHIFT_
```

### image\_window.KBD\_MOD\_CONTROL\_

```cpp
static int dlib::image_window::KBD_MOD_CONTROL
AutoIt:
    [propget] $oimage_window.KBD_MOD_CONTROL_
```

### image\_window.KBD\_MOD\_ALT\_

```cpp
static int dlib::image_window::KBD_MOD_ALT
AutoIt:
    [propget] $oimage_window.KBD_MOD_ALT_
```

### image\_window.KBD\_MOD\_META\_

```cpp
static int dlib::image_window::KBD_MOD_META
AutoIt:
    [propget] $oimage_window.KBD_MOD_META_
```

### image\_window.KBD\_MOD\_CAPS\_LOCK\_

```cpp
static int dlib::image_window::KBD_MOD_CAPS_LOCK
AutoIt:
    [propget] $oimage_window.KBD_MOD_CAPS_LOCK_
```

### image\_window.KBD\_MOD\_NUM\_LOCK\_

```cpp
static int dlib::image_window::KBD_MOD_NUM_LOCK
AutoIt:
    [propget] $oimage_window.KBD_MOD_NUM_LOCK_
```

### image\_window.KBD\_MOD\_SCROLL\_LOCK\_

```cpp
static int dlib::image_window::KBD_MOD_SCROLL_LOCK
AutoIt:
    [propget] $oimage_window.KBD_MOD_SCROLL_LOCK_
```

### image\_window.KEY\_BACKSPACE\_

```cpp
static int dlib::image_window::KEY_BACKSPACE
AutoIt:
    [propget] $oimage_window.KEY_BACKSPACE_
```

### image\_window.KEY\_SHIFT\_

```cpp
static int dlib::image_window::KEY_SHIFT
AutoIt:
    [propget] $oimage_window.KEY_SHIFT_
```

### image\_window.KEY\_CTRL\_

```cpp
static int dlib::image_window::KEY_CTRL
AutoIt:
    [propget] $oimage_window.KEY_CTRL_
```

### image\_window.KEY\_ALT\_

```cpp
static int dlib::image_window::KEY_ALT
AutoIt:
    [propget] $oimage_window.KEY_ALT_
```

### image\_window.KEY\_PAUSE\_

```cpp
static int dlib::image_window::KEY_PAUSE
AutoIt:
    [propget] $oimage_window.KEY_PAUSE_
```

### image\_window.KEY\_CAPS\_LOCK\_

```cpp
static int dlib::image_window::KEY_CAPS_LOCK
AutoIt:
    [propget] $oimage_window.KEY_CAPS_LOCK_
```

### image\_window.KEY\_ESC\_

```cpp
static int dlib::image_window::KEY_ESC
AutoIt:
    [propget] $oimage_window.KEY_ESC_
```

### image\_window.KEY\_PAGE\_UP\_

```cpp
static int dlib::image_window::KEY_PAGE_UP
AutoIt:
    [propget] $oimage_window.KEY_PAGE_UP_
```

### image\_window.KEY\_PAGE\_DOWN\_

```cpp
static int dlib::image_window::KEY_PAGE_DOWN
AutoIt:
    [propget] $oimage_window.KEY_PAGE_DOWN_
```

### image\_window.KEY\_END\_

```cpp
static int dlib::image_window::KEY_END
AutoIt:
    [propget] $oimage_window.KEY_END_
```

### image\_window.KEY\_HOME\_

```cpp
static int dlib::image_window::KEY_HOME
AutoIt:
    [propget] $oimage_window.KEY_HOME_
```

### image\_window.KEY\_LEFT\_

```cpp
static int dlib::image_window::KEY_LEFT
AutoIt:
    [propget] $oimage_window.KEY_LEFT_
```

### image\_window.KEY\_RIGHT\_

```cpp
static int dlib::image_window::KEY_RIGHT
AutoIt:
    [propget] $oimage_window.KEY_RIGHT_
```

### image\_window.KEY\_UP\_

```cpp
static int dlib::image_window::KEY_UP
AutoIt:
    [propget] $oimage_window.KEY_UP_
```

### image\_window.KEY\_DOWN\_

```cpp
static int dlib::image_window::KEY_DOWN
AutoIt:
    [propget] $oimage_window.KEY_DOWN_
```

### image\_window.KEY\_INSERT\_

```cpp
static int dlib::image_window::KEY_INSERT
AutoIt:
    [propget] $oimage_window.KEY_INSERT_
```

### image\_window.KEY\_DELETE\_

```cpp
static int dlib::image_window::KEY_DELETE
AutoIt:
    [propget] $oimage_window.KEY_DELETE_
```

### image\_window.KEY\_SCROLL\_LOCK\_

```cpp
static int dlib::image_window::KEY_SCROLL_LOCK
AutoIt:
    [propget] $oimage_window.KEY_SCROLL_LOCK_
```

### image\_window.KEY\_F1\_

```cpp
static int dlib::image_window::KEY_F1
AutoIt:
    [propget] $oimage_window.KEY_F1_
```

### image\_window.KEY\_F2\_

```cpp
static int dlib::image_window::KEY_F2
AutoIt:
    [propget] $oimage_window.KEY_F2_
```

### image\_window.KEY\_F3\_

```cpp
static int dlib::image_window::KEY_F3
AutoIt:
    [propget] $oimage_window.KEY_F3_
```

### image\_window.KEY\_F4\_

```cpp
static int dlib::image_window::KEY_F4
AutoIt:
    [propget] $oimage_window.KEY_F4_
```

### image\_window.KEY\_F5\_

```cpp
static int dlib::image_window::KEY_F5
AutoIt:
    [propget] $oimage_window.KEY_F5_
```

### image\_window.KEY\_F6\_

```cpp
static int dlib::image_window::KEY_F6
AutoIt:
    [propget] $oimage_window.KEY_F6_
```

### image\_window.KEY\_F7\_

```cpp
static int dlib::image_window::KEY_F7
AutoIt:
    [propget] $oimage_window.KEY_F7_
```

### image\_window.KEY\_F8\_

```cpp
static int dlib::image_window::KEY_F8
AutoIt:
    [propget] $oimage_window.KEY_F8_
```

### image\_window.KEY\_F9\_

```cpp
static int dlib::image_window::KEY_F9
AutoIt:
    [propget] $oimage_window.KEY_F9_
```

### image\_window.KEY\_F10\_

```cpp
static int dlib::image_window::KEY_F10
AutoIt:
    [propget] $oimage_window.KEY_F10_
```

### image\_window.KEY\_F11\_

```cpp
static int dlib::image_window::KEY_F11
AutoIt:
    [propget] $oimage_window.KEY_F11_
```

### image\_window.KEY\_F12\_

```cpp
static int dlib::image_window::KEY_F12
AutoIt:
    [propget] $oimage_window.KEY_F12_
```

## dlib::rgb\_pixel

### rgb\_pixel.red

```cpp
uchar dlib::rgb_pixel::red
AutoIt:
    [propget, propput] $orgb_pixel.red
```

### rgb\_pixel.blue

```cpp
uchar dlib::rgb_pixel::blue
AutoIt:
    [propget, propput] $orgb_pixel.blue
```

### rgb\_pixel.green

```cpp
uchar dlib::rgb_pixel::green
AutoIt:
    [propget, propput] $orgb_pixel.green
```

### dlib::rgb\_pixel::get\_create

```cpp
static dlib::rgb_pixel dlib::rgb_pixel::get_create( uchar red,
                                                    uchar blue,
                                                    uchar green );
AutoIt:
    _Dlib_ObjCreate("dlib.rgb_pixel").create( $red, $blue, $green ) -> <dlib.rgb_pixel object>
    $orgb_pixel( $red, $blue, $green ) -> <dlib.rgb_pixel object>
```

```cpp
static dlib::rgb_pixel dlib::rgb_pixel::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rgb_pixel").create() -> <dlib.rgb_pixel object>
```

## dlib::image\_dataset\_metadata

### image\_dataset\_metadata.box

```cpp
static dlib::image_dataset_metadata::box
AutoIt:
    [propget] $oimage_dataset_metadata.box
```

### image\_dataset\_metadata.image

```cpp
static dlib::image_dataset_metadata::image
AutoIt:
    [propget] $oimage_dataset_metadata.image
```

### image\_dataset\_metadata.dataset

```cpp
static dlib::image_dataset_metadata::dataset
AutoIt:
    [propget] $oimage_dataset_metadata.dataset
```

### dlib::image\_dataset\_metadata::load\_image\_dataset\_metadata

```cpp
void dlib::image_dataset_metadata::load_image_dataset_metadata( dlib::image_dataset_metadata::dataset& data,
                                                                std::string                            filename );
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata").load_image_dataset_metadata( $filename[, $data] ) -> $data
```

### dlib::image\_dataset\_metadata::make\_bounding\_box\_regression\_training\_data

```cpp
dlib::image_dataset_metadata::dataset dlib::image_dataset_metadata::make_bounding_box_regression_training_data( dlib::image_dataset_metadata::dataset&    truth,
                                                                                                                std::vector<std::vector<dlib::rectangle>> detections );
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata").make_bounding_box_regression_training_data( $truth, $detections ) -> retval
```

### dlib::image\_dataset\_metadata::save\_image\_dataset\_metadata

```cpp
void dlib::image_dataset_metadata::save_image_dataset_metadata( dlib::image_dataset_metadata::dataset data,
                                                                std::string                           filename );
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata").save_image_dataset_metadata( $data, $filename ) -> None
```

### image\_dataset\_metadata.UNKNOWN\_

```cpp
static int dlib::image_dataset_metadata::UNKNOWN
AutoIt:
    [propget] $oimage_dataset_metadata.UNKNOWN_
```

### image\_dataset\_metadata.MALE\_

```cpp
static int dlib::image_dataset_metadata::MALE
AutoIt:
    [propget] $oimage_dataset_metadata.MALE_
```

### image\_dataset\_metadata.FEMALE\_

```cpp
static int dlib::image_dataset_metadata::FEMALE
AutoIt:
    [propget] $oimage_dataset_metadata.FEMALE_
```

## dlib::image\_dataset\_metadata::box

### box.rect

```cpp
dlib::rectangle dlib::image_dataset_metadata::box::rect
AutoIt:
    [propget, propput] $obox.rect
```

### box.parts

```cpp
std::map<std::string, dlib::point> dlib::image_dataset_metadata::box::parts
AutoIt:
    [propget, propput] $obox.parts
```

### box.label

```cpp
std::string dlib::image_dataset_metadata::box::label
AutoIt:
    [propget, propput] $obox.label
```

### box.difficult

```cpp
bool dlib::image_dataset_metadata::box::difficult
AutoIt:
    [propget, propput] $obox.difficult
```

### box.truncated

```cpp
bool dlib::image_dataset_metadata::box::truncated
AutoIt:
    [propget, propput] $obox.truncated
```

### box.occluded

```cpp
bool dlib::image_dataset_metadata::box::occluded
AutoIt:
    [propget, propput] $obox.occluded
```

### box.ignore

```cpp
bool dlib::image_dataset_metadata::box::ignore
AutoIt:
    [propget, propput] $obox.ignore
```

### box.pose

```cpp
double dlib::image_dataset_metadata::box::pose
AutoIt:
    [propget, propput] $obox.pose
```

### box.detection\_score

```cpp
double dlib::image_dataset_metadata::box::detection_score
AutoIt:
    [propget, propput] $obox.detection_score
```

### box.angle

```cpp
double dlib::image_dataset_metadata::box::angle
AutoIt:
    [propget, propput] $obox.angle
```

### box.gender

```cpp
dlib::image_dataset_metadata::gender_t dlib::image_dataset_metadata::box::gender
AutoIt:
    [propget, propput] $obox.gender
```

### box.age

```cpp
double dlib::image_dataset_metadata::box::age
AutoIt:
    [propget, propput] $obox.age
```

### dlib::image\_dataset\_metadata::box::get\_create

```cpp
static dlib::image_dataset_metadata::box dlib::image_dataset_metadata::box::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.box").create() -> <dlib.image_dataset_metadata.box object>
```

```cpp
static dlib::image_dataset_metadata::box dlib::image_dataset_metadata::box::get_create( dlib::rectangle rect );
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.box").create( $rect ) -> <dlib.image_dataset_metadata.box object>
    $obox( $rect ) -> <dlib.image_dataset_metadata.box object>
```

### dlib::image\_dataset\_metadata::box::has\_label

```cpp
bool dlib::image_dataset_metadata::box::has_label();
AutoIt:
    $obox.has_label() -> retval
```

## dlib::image\_dataset\_metadata::image

### image.filename

```cpp
std::string dlib::image_dataset_metadata::image::filename
AutoIt:
    [propget, propput] $oimage.filename
```

### image.boxes

```cpp
std::vector<dlib::image_dataset_metadata::box> dlib::image_dataset_metadata::image::boxes
AutoIt:
    [propget, propput] $oimage.boxes
```

### dlib::image\_dataset\_metadata::image::get\_create

```cpp
static dlib::image_dataset_metadata::image dlib::image_dataset_metadata::image::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.image").create() -> <dlib.image_dataset_metadata.image object>
```

```cpp
static dlib::image_dataset_metadata::image dlib::image_dataset_metadata::image::get_create( std::string filename );
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.image").create( $filename ) -> <dlib.image_dataset_metadata.image object>
    $oimage( $filename ) -> <dlib.image_dataset_metadata.image object>
```

## dlib::image\_dataset\_metadata::dataset

### dataset.images

```cpp
std::vector<dlib::image_dataset_metadata::image> dlib::image_dataset_metadata::dataset::images
AutoIt:
    [propget, propput] $odataset.images
```

### dataset.comment

```cpp
std::string dlib::image_dataset_metadata::dataset::comment
AutoIt:
    [propget, propput] $odataset.comment
```

### dataset.name

```cpp
std::string dlib::image_dataset_metadata::dataset::name
AutoIt:
    [propget, propput] $odataset.name
```

### dlib::image\_dataset\_metadata::dataset::get\_create

```cpp
static dlib::image_dataset_metadata::dataset dlib::image_dataset_metadata::dataset::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.image_dataset_metadata.dataset").create() -> <dlib.image_dataset_metadata.dataset object>
```

## dlib::line

### line.normal

```cpp
dlib::dpoint dlib::line::normal()
AutoIt:
    [propget] $oline.normal
```

### line.p1

```cpp
dlib::dpoint dlib::line::p1()
AutoIt:
    [propget] $oline.p1
```

### line.p2

```cpp
dlib::dpoint dlib::line::p2()
AutoIt:
    [propget] $oline.p2
```

### dlib::line::get\_create

```cpp
static dlib::line dlib::line::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.line").create() -> <dlib.line object>
```

```cpp
static dlib::line dlib::line::get_create( dlib::dpoint a,
                                          dlib::dpoint b );
AutoIt:
    _Dlib_ObjCreate("dlib.line").create( $a, $b ) -> <dlib.line object>
    $oline( $a, $b ) -> <dlib.line object>
```

```cpp
static dlib::line dlib::line::get_create( dlib::point a,
                                          dlib::point b );
AutoIt:
    _Dlib_ObjCreate("dlib.line").create( $a, $b ) -> <dlib.line object>
    $oline( $a, $b ) -> <dlib.line object>
```

## cv::Mat

### Mat.cols

```cpp
int cv::Mat::cols
AutoIt:
    [propget, propput] $oMat.cols
```

### Mat.data

```cpp
uchar* cv::Mat::data
AutoIt:
    [propget, propput] $oMat.data
```

### Mat.dims

```cpp
int cv::Mat::dims
AutoIt:
    [propget, propput] $oMat.dims
```

### Mat.flags

```cpp
int cv::Mat::flags
AutoIt:
    [propget, propput] $oMat.flags
```

### Mat.rows

```cpp
int cv::Mat::rows
AutoIt:
    [propget, propput] $oMat.rows
```

### Mat.step

```cpp
size_t cv::Mat::step
AutoIt:
    [propget, propput] $oMat.step
```

### Mat.width

```cpp
int cv::Mat::cols
AutoIt:
    [propget, propput] $oMat.width
```

### Mat.height

```cpp
int cv::Mat::rows
AutoIt:
    [propget, propput] $oMat.height
```

### Mat.shape

```cpp
std::tuple<int, int, int> cv::Mat::shape
AutoIt:
    [propget] $oMat.shape
```

### Mat.sizes

```cpp
std::vector<int> cv::Mat::sizes
AutoIt:
    [propget] $oMat.sizes
```

### Mat.steps

```cpp
std::vector<size_t> cv::Mat::steps
AutoIt:
    [propget] $oMat.steps
```

### cv::Mat::create

```cpp
static cv::Mat cv::Mat::create();
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create() -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( int rows,
                                int cols,
                                int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $rows, $cols, $type ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( cv::Size size,
                                int      type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $size, $type ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( int        rows,
                                int        cols,
                                int        type,
                                cv::Scalar s );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $rows, $cols, $type, $s ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( cv::Size   size,
                                int        type,
                                cv::Scalar s );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $size, $type, $s ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const std::vector<int>& sizes,
                                int                     type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $sizes, $type ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const std::vector<int>& sizes,
                                int                     type,
                                cv::Scalar              s );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $sizes, $type, $s ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const cv::Mat& m );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $m ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( int    rows,
                                int    cols,
                                int    type,
                                void*  data,
                                size_t step = Mat::AUTO_STEP );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $rows, $cols, $type, $data[, $step] ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( cv::Size size,
                                int      type,
                                void*    data,
                                size_t   step = Mat::AUTO_STEP );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $size, $type, $data[, $step] ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const std::vector<int>&    sizes,
                                int                        type,
                                void*                      data,
                                const std::vector<size_t>& steps = std::vector<size_t>() );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $sizes, $type, $data[, $steps] ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const cv::Mat&   m,
                                const cv::Range& rowRange,
                                const cv::Range& colRange = Range::all() );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $m, $rowRange[, $colRange] ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const cv::Mat& m,
                                cv::Rect       roi );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $m, $roi ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const cv::Mat&                m,
                                const std::vector<cv::Range>& ranges );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $m, $ranges ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const std::vector<double>& vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $vec ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const std::vector<int>& vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $vec ) -> <cv.Mat object>
```

```cpp
static cv::Mat cv::Mat::create( const cv::cuda::GpuMat& m );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").create( $m ) -> <cv.Mat object>
```

### cv::Mat::GdiplusResize

```cpp
void cv::Mat::GdiplusResize( cv::Mat dst,
                             float   newWidth,
                             float   newHeight,
                             int     interpolation = 7 );
AutoIt:
    $oMat.GdiplusResize( $newWidth, $newHeight[, $interpolation[, $dst]] ) -> $dst
```

### cv::Mat::PixelChecksum

```cpp
size_t cv::Mat::PixelChecksum( int left = 0,
                               int top = 0,
                               int right = __self->get()->cols - 1,
                               int bottom = __self->get()->rows - 1,
                               int step = 1,
                               int mode = 0 );
AutoIt:
    $oMat.PixelChecksum( [$left[, $top[, $right[, $bottom[, $step[, $mode]]]]]] ) -> retval
```

```cpp
size_t cv::Mat::PixelChecksum( cv::Rect rect = cv::Rect(0, 0, __self->get()->cols, __self->get()->rows),
                               int      step = 1,
                               int      mode = 0 );
AutoIt:
    $oMat.PixelChecksum( [$rect[, $step[, $mode]]] ) -> retval
```

### cv::Mat::PixelSearch

```cpp
_variant_t cv::Mat::PixelSearch( cv::Scalar color,
                                 int        left = 0,
                                 int        top = 0,
                                 int        right = __self->get()->cols - 1,
                                 int        bottom = __self->get()->rows - 1,
                                 uchar      shade_variation = 0,
                                 int        step = 1 );
AutoIt:
    $oMat.PixelSearch( $color[, $left[, $top[, $right[, $bottom[, $shade_variation[, $step]]]]]] ) -> retval
```

```cpp
_variant_t cv::Mat::PixelSearch( cv::Scalar color,
                                 cv::Rect   rect = cv::Rect(0, 0, __self->get()->cols, __self->get()->rows),
                                 uchar      shade_variation = 0,
                                 int        step = 1 );
AutoIt:
    $oMat.PixelSearch( $color[, $rect[, $shade_variation[, $step]]] ) -> retval
```

### cv::Mat::Point\_at

```cpp
cv::Point2d cv::Mat::Point_at( int i0 );
AutoIt:
    $oMat.Point_at( $i0 ) -> retval
```

```cpp
cv::Point2d cv::Mat::Point_at( int row,
                               int col );
AutoIt:
    $oMat.Point_at( $row, $col ) -> retval
```

```cpp
cv::Point2d cv::Mat::Point_at( int i0,
                               int i1,
                               int i2 );
AutoIt:
    $oMat.Point_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Point2d cv::Mat::Point_at( cv::Point pt );
AutoIt:
    $oMat.Point_at( $pt ) -> retval
```

```cpp
cv::Point2d cv::Mat::Point_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Point_at( $idx ) -> retval
```

### cv::Mat::Vec2b\_at

```cpp
cv::Vec2b cv::Mat::Vec2b_at( int i0 );
AutoIt:
    $oMat.Vec2b_at( $i0 ) -> retval
```

```cpp
cv::Vec2b cv::Mat::Vec2b_at( int row,
                             int col );
AutoIt:
    $oMat.Vec2b_at( $row, $col ) -> retval
```

```cpp
cv::Vec2b cv::Mat::Vec2b_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec2b_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec2b cv::Mat::Vec2b_at( cv::Point pt );
AutoIt:
    $oMat.Vec2b_at( $pt ) -> retval
```

```cpp
cv::Vec2b cv::Mat::Vec2b_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec2b_at( $idx ) -> retval
```

### cv::Mat::Vec2b\_set\_at

```cpp
void cv::Mat::Vec2b_set_at( int       i0,
                            cv::Vec2b value );
AutoIt:
    $oMat.Vec2b_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec2b_set_at( int       row,
                            int       col,
                            cv::Vec2b value );
AutoIt:
    $oMat.Vec2b_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec2b_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec2b value );
AutoIt:
    $oMat.Vec2b_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec2b_set_at( cv::Point pt,
                            cv::Vec2b value );
AutoIt:
    $oMat.Vec2b_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec2b_set_at( const std::vector<int>& idx,
                            cv::Vec2b               value );
AutoIt:
    $oMat.Vec2b_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec2d\_at

```cpp
cv::Vec2d cv::Mat::Vec2d_at( int i0 );
AutoIt:
    $oMat.Vec2d_at( $i0 ) -> retval
```

```cpp
cv::Vec2d cv::Mat::Vec2d_at( int row,
                             int col );
AutoIt:
    $oMat.Vec2d_at( $row, $col ) -> retval
```

```cpp
cv::Vec2d cv::Mat::Vec2d_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec2d_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec2d cv::Mat::Vec2d_at( cv::Point pt );
AutoIt:
    $oMat.Vec2d_at( $pt ) -> retval
```

```cpp
cv::Vec2d cv::Mat::Vec2d_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec2d_at( $idx ) -> retval
```

### cv::Mat::Vec2d\_set\_at

```cpp
void cv::Mat::Vec2d_set_at( int       i0,
                            cv::Vec2d value );
AutoIt:
    $oMat.Vec2d_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec2d_set_at( int       row,
                            int       col,
                            cv::Vec2d value );
AutoIt:
    $oMat.Vec2d_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec2d_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec2d value );
AutoIt:
    $oMat.Vec2d_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec2d_set_at( cv::Point pt,
                            cv::Vec2d value );
AutoIt:
    $oMat.Vec2d_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec2d_set_at( const std::vector<int>& idx,
                            cv::Vec2d               value );
AutoIt:
    $oMat.Vec2d_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec2f\_at

```cpp
cv::Vec2f cv::Mat::Vec2f_at( int i0 );
AutoIt:
    $oMat.Vec2f_at( $i0 ) -> retval
```

```cpp
cv::Vec2f cv::Mat::Vec2f_at( int row,
                             int col );
AutoIt:
    $oMat.Vec2f_at( $row, $col ) -> retval
```

```cpp
cv::Vec2f cv::Mat::Vec2f_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec2f_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec2f cv::Mat::Vec2f_at( cv::Point pt );
AutoIt:
    $oMat.Vec2f_at( $pt ) -> retval
```

```cpp
cv::Vec2f cv::Mat::Vec2f_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec2f_at( $idx ) -> retval
```

### cv::Mat::Vec2f\_set\_at

```cpp
void cv::Mat::Vec2f_set_at( int       i0,
                            cv::Vec2f value );
AutoIt:
    $oMat.Vec2f_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec2f_set_at( int       row,
                            int       col,
                            cv::Vec2f value );
AutoIt:
    $oMat.Vec2f_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec2f_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec2f value );
AutoIt:
    $oMat.Vec2f_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec2f_set_at( cv::Point pt,
                            cv::Vec2f value );
AutoIt:
    $oMat.Vec2f_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec2f_set_at( const std::vector<int>& idx,
                            cv::Vec2f               value );
AutoIt:
    $oMat.Vec2f_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec2i\_at

```cpp
cv::Vec2i cv::Mat::Vec2i_at( int i0 );
AutoIt:
    $oMat.Vec2i_at( $i0 ) -> retval
```

```cpp
cv::Vec2i cv::Mat::Vec2i_at( int row,
                             int col );
AutoIt:
    $oMat.Vec2i_at( $row, $col ) -> retval
```

```cpp
cv::Vec2i cv::Mat::Vec2i_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec2i_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec2i cv::Mat::Vec2i_at( cv::Point pt );
AutoIt:
    $oMat.Vec2i_at( $pt ) -> retval
```

```cpp
cv::Vec2i cv::Mat::Vec2i_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec2i_at( $idx ) -> retval
```

### cv::Mat::Vec2i\_set\_at

```cpp
void cv::Mat::Vec2i_set_at( int       i0,
                            cv::Vec2i value );
AutoIt:
    $oMat.Vec2i_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec2i_set_at( int       row,
                            int       col,
                            cv::Vec2i value );
AutoIt:
    $oMat.Vec2i_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec2i_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec2i value );
AutoIt:
    $oMat.Vec2i_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec2i_set_at( cv::Point pt,
                            cv::Vec2i value );
AutoIt:
    $oMat.Vec2i_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec2i_set_at( const std::vector<int>& idx,
                            cv::Vec2i               value );
AutoIt:
    $oMat.Vec2i_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec2s\_at

```cpp
cv::Vec2s cv::Mat::Vec2s_at( int i0 );
AutoIt:
    $oMat.Vec2s_at( $i0 ) -> retval
```

```cpp
cv::Vec2s cv::Mat::Vec2s_at( int row,
                             int col );
AutoIt:
    $oMat.Vec2s_at( $row, $col ) -> retval
```

```cpp
cv::Vec2s cv::Mat::Vec2s_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec2s_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec2s cv::Mat::Vec2s_at( cv::Point pt );
AutoIt:
    $oMat.Vec2s_at( $pt ) -> retval
```

```cpp
cv::Vec2s cv::Mat::Vec2s_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec2s_at( $idx ) -> retval
```

### cv::Mat::Vec2s\_set\_at

```cpp
void cv::Mat::Vec2s_set_at( int       i0,
                            cv::Vec2s value );
AutoIt:
    $oMat.Vec2s_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec2s_set_at( int       row,
                            int       col,
                            cv::Vec2s value );
AutoIt:
    $oMat.Vec2s_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec2s_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec2s value );
AutoIt:
    $oMat.Vec2s_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec2s_set_at( cv::Point pt,
                            cv::Vec2s value );
AutoIt:
    $oMat.Vec2s_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec2s_set_at( const std::vector<int>& idx,
                            cv::Vec2s               value );
AutoIt:
    $oMat.Vec2s_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec2w\_at

```cpp
cv::Vec2w cv::Mat::Vec2w_at( int i0 );
AutoIt:
    $oMat.Vec2w_at( $i0 ) -> retval
```

```cpp
cv::Vec2w cv::Mat::Vec2w_at( int row,
                             int col );
AutoIt:
    $oMat.Vec2w_at( $row, $col ) -> retval
```

```cpp
cv::Vec2w cv::Mat::Vec2w_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec2w_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec2w cv::Mat::Vec2w_at( cv::Point pt );
AutoIt:
    $oMat.Vec2w_at( $pt ) -> retval
```

```cpp
cv::Vec2w cv::Mat::Vec2w_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec2w_at( $idx ) -> retval
```

### cv::Mat::Vec2w\_set\_at

```cpp
void cv::Mat::Vec2w_set_at( int       i0,
                            cv::Vec2w value );
AutoIt:
    $oMat.Vec2w_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec2w_set_at( int       row,
                            int       col,
                            cv::Vec2w value );
AutoIt:
    $oMat.Vec2w_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec2w_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec2w value );
AutoIt:
    $oMat.Vec2w_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec2w_set_at( cv::Point pt,
                            cv::Vec2w value );
AutoIt:
    $oMat.Vec2w_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec2w_set_at( const std::vector<int>& idx,
                            cv::Vec2w               value );
AutoIt:
    $oMat.Vec2w_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec3b\_at

```cpp
cv::Vec3b cv::Mat::Vec3b_at( int i0 );
AutoIt:
    $oMat.Vec3b_at( $i0 ) -> retval
```

```cpp
cv::Vec3b cv::Mat::Vec3b_at( int row,
                             int col );
AutoIt:
    $oMat.Vec3b_at( $row, $col ) -> retval
```

```cpp
cv::Vec3b cv::Mat::Vec3b_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec3b_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec3b cv::Mat::Vec3b_at( cv::Point pt );
AutoIt:
    $oMat.Vec3b_at( $pt ) -> retval
```

```cpp
cv::Vec3b cv::Mat::Vec3b_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec3b_at( $idx ) -> retval
```

### cv::Mat::Vec3b\_set\_at

```cpp
void cv::Mat::Vec3b_set_at( int       i0,
                            cv::Vec3b value );
AutoIt:
    $oMat.Vec3b_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec3b_set_at( int       row,
                            int       col,
                            cv::Vec3b value );
AutoIt:
    $oMat.Vec3b_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec3b_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec3b value );
AutoIt:
    $oMat.Vec3b_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec3b_set_at( cv::Point pt,
                            cv::Vec3b value );
AutoIt:
    $oMat.Vec3b_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec3b_set_at( const std::vector<int>& idx,
                            cv::Vec3b               value );
AutoIt:
    $oMat.Vec3b_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec3d\_at

```cpp
cv::Vec3d cv::Mat::Vec3d_at( int i0 );
AutoIt:
    $oMat.Vec3d_at( $i0 ) -> retval
```

```cpp
cv::Vec3d cv::Mat::Vec3d_at( int row,
                             int col );
AutoIt:
    $oMat.Vec3d_at( $row, $col ) -> retval
```

```cpp
cv::Vec3d cv::Mat::Vec3d_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec3d_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec3d cv::Mat::Vec3d_at( cv::Point pt );
AutoIt:
    $oMat.Vec3d_at( $pt ) -> retval
```

```cpp
cv::Vec3d cv::Mat::Vec3d_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec3d_at( $idx ) -> retval
```

### cv::Mat::Vec3d\_set\_at

```cpp
void cv::Mat::Vec3d_set_at( int       i0,
                            cv::Vec3d value );
AutoIt:
    $oMat.Vec3d_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec3d_set_at( int       row,
                            int       col,
                            cv::Vec3d value );
AutoIt:
    $oMat.Vec3d_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec3d_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec3d value );
AutoIt:
    $oMat.Vec3d_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec3d_set_at( cv::Point pt,
                            cv::Vec3d value );
AutoIt:
    $oMat.Vec3d_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec3d_set_at( const std::vector<int>& idx,
                            cv::Vec3d               value );
AutoIt:
    $oMat.Vec3d_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec3f\_at

```cpp
cv::Vec3f cv::Mat::Vec3f_at( int i0 );
AutoIt:
    $oMat.Vec3f_at( $i0 ) -> retval
```

```cpp
cv::Vec3f cv::Mat::Vec3f_at( int row,
                             int col );
AutoIt:
    $oMat.Vec3f_at( $row, $col ) -> retval
```

```cpp
cv::Vec3f cv::Mat::Vec3f_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec3f_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec3f cv::Mat::Vec3f_at( cv::Point pt );
AutoIt:
    $oMat.Vec3f_at( $pt ) -> retval
```

```cpp
cv::Vec3f cv::Mat::Vec3f_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec3f_at( $idx ) -> retval
```

### cv::Mat::Vec3f\_set\_at

```cpp
void cv::Mat::Vec3f_set_at( int       i0,
                            cv::Vec3f value );
AutoIt:
    $oMat.Vec3f_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec3f_set_at( int       row,
                            int       col,
                            cv::Vec3f value );
AutoIt:
    $oMat.Vec3f_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec3f_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec3f value );
AutoIt:
    $oMat.Vec3f_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec3f_set_at( cv::Point pt,
                            cv::Vec3f value );
AutoIt:
    $oMat.Vec3f_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec3f_set_at( const std::vector<int>& idx,
                            cv::Vec3f               value );
AutoIt:
    $oMat.Vec3f_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec3i\_at

```cpp
cv::Vec3i cv::Mat::Vec3i_at( int i0 );
AutoIt:
    $oMat.Vec3i_at( $i0 ) -> retval
```

```cpp
cv::Vec3i cv::Mat::Vec3i_at( int row,
                             int col );
AutoIt:
    $oMat.Vec3i_at( $row, $col ) -> retval
```

```cpp
cv::Vec3i cv::Mat::Vec3i_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec3i_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec3i cv::Mat::Vec3i_at( cv::Point pt );
AutoIt:
    $oMat.Vec3i_at( $pt ) -> retval
```

```cpp
cv::Vec3i cv::Mat::Vec3i_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec3i_at( $idx ) -> retval
```

### cv::Mat::Vec3i\_set\_at

```cpp
void cv::Mat::Vec3i_set_at( int       i0,
                            cv::Vec3i value );
AutoIt:
    $oMat.Vec3i_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec3i_set_at( int       row,
                            int       col,
                            cv::Vec3i value );
AutoIt:
    $oMat.Vec3i_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec3i_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec3i value );
AutoIt:
    $oMat.Vec3i_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec3i_set_at( cv::Point pt,
                            cv::Vec3i value );
AutoIt:
    $oMat.Vec3i_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec3i_set_at( const std::vector<int>& idx,
                            cv::Vec3i               value );
AutoIt:
    $oMat.Vec3i_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec3s\_at

```cpp
cv::Vec3s cv::Mat::Vec3s_at( int i0 );
AutoIt:
    $oMat.Vec3s_at( $i0 ) -> retval
```

```cpp
cv::Vec3s cv::Mat::Vec3s_at( int row,
                             int col );
AutoIt:
    $oMat.Vec3s_at( $row, $col ) -> retval
```

```cpp
cv::Vec3s cv::Mat::Vec3s_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec3s_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec3s cv::Mat::Vec3s_at( cv::Point pt );
AutoIt:
    $oMat.Vec3s_at( $pt ) -> retval
```

```cpp
cv::Vec3s cv::Mat::Vec3s_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec3s_at( $idx ) -> retval
```

### cv::Mat::Vec3s\_set\_at

```cpp
void cv::Mat::Vec3s_set_at( int       i0,
                            cv::Vec3s value );
AutoIt:
    $oMat.Vec3s_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec3s_set_at( int       row,
                            int       col,
                            cv::Vec3s value );
AutoIt:
    $oMat.Vec3s_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec3s_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec3s value );
AutoIt:
    $oMat.Vec3s_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec3s_set_at( cv::Point pt,
                            cv::Vec3s value );
AutoIt:
    $oMat.Vec3s_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec3s_set_at( const std::vector<int>& idx,
                            cv::Vec3s               value );
AutoIt:
    $oMat.Vec3s_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec3w\_at

```cpp
cv::Vec3w cv::Mat::Vec3w_at( int i0 );
AutoIt:
    $oMat.Vec3w_at( $i0 ) -> retval
```

```cpp
cv::Vec3w cv::Mat::Vec3w_at( int row,
                             int col );
AutoIt:
    $oMat.Vec3w_at( $row, $col ) -> retval
```

```cpp
cv::Vec3w cv::Mat::Vec3w_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec3w_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec3w cv::Mat::Vec3w_at( cv::Point pt );
AutoIt:
    $oMat.Vec3w_at( $pt ) -> retval
```

```cpp
cv::Vec3w cv::Mat::Vec3w_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec3w_at( $idx ) -> retval
```

### cv::Mat::Vec3w\_set\_at

```cpp
void cv::Mat::Vec3w_set_at( int       i0,
                            cv::Vec3w value );
AutoIt:
    $oMat.Vec3w_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec3w_set_at( int       row,
                            int       col,
                            cv::Vec3w value );
AutoIt:
    $oMat.Vec3w_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec3w_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec3w value );
AutoIt:
    $oMat.Vec3w_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec3w_set_at( cv::Point pt,
                            cv::Vec3w value );
AutoIt:
    $oMat.Vec3w_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec3w_set_at( const std::vector<int>& idx,
                            cv::Vec3w               value );
AutoIt:
    $oMat.Vec3w_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec4b\_at

```cpp
cv::Vec4b cv::Mat::Vec4b_at( int i0 );
AutoIt:
    $oMat.Vec4b_at( $i0 ) -> retval
```

```cpp
cv::Vec4b cv::Mat::Vec4b_at( int row,
                             int col );
AutoIt:
    $oMat.Vec4b_at( $row, $col ) -> retval
```

```cpp
cv::Vec4b cv::Mat::Vec4b_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec4b_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec4b cv::Mat::Vec4b_at( cv::Point pt );
AutoIt:
    $oMat.Vec4b_at( $pt ) -> retval
```

```cpp
cv::Vec4b cv::Mat::Vec4b_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec4b_at( $idx ) -> retval
```

### cv::Mat::Vec4b\_set\_at

```cpp
void cv::Mat::Vec4b_set_at( int       i0,
                            cv::Vec4b value );
AutoIt:
    $oMat.Vec4b_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec4b_set_at( int       row,
                            int       col,
                            cv::Vec4b value );
AutoIt:
    $oMat.Vec4b_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec4b_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec4b value );
AutoIt:
    $oMat.Vec4b_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec4b_set_at( cv::Point pt,
                            cv::Vec4b value );
AutoIt:
    $oMat.Vec4b_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec4b_set_at( const std::vector<int>& idx,
                            cv::Vec4b               value );
AutoIt:
    $oMat.Vec4b_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec4d\_at

```cpp
cv::Vec4d cv::Mat::Vec4d_at( int i0 );
AutoIt:
    $oMat.Vec4d_at( $i0 ) -> retval
```

```cpp
cv::Vec4d cv::Mat::Vec4d_at( int row,
                             int col );
AutoIt:
    $oMat.Vec4d_at( $row, $col ) -> retval
```

```cpp
cv::Vec4d cv::Mat::Vec4d_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec4d_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec4d cv::Mat::Vec4d_at( cv::Point pt );
AutoIt:
    $oMat.Vec4d_at( $pt ) -> retval
```

```cpp
cv::Vec4d cv::Mat::Vec4d_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec4d_at( $idx ) -> retval
```

### cv::Mat::Vec4d\_set\_at

```cpp
void cv::Mat::Vec4d_set_at( int       i0,
                            cv::Vec4d value );
AutoIt:
    $oMat.Vec4d_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec4d_set_at( int       row,
                            int       col,
                            cv::Vec4d value );
AutoIt:
    $oMat.Vec4d_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec4d_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec4d value );
AutoIt:
    $oMat.Vec4d_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec4d_set_at( cv::Point pt,
                            cv::Vec4d value );
AutoIt:
    $oMat.Vec4d_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec4d_set_at( const std::vector<int>& idx,
                            cv::Vec4d               value );
AutoIt:
    $oMat.Vec4d_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec4f\_at

```cpp
cv::Vec4f cv::Mat::Vec4f_at( int i0 );
AutoIt:
    $oMat.Vec4f_at( $i0 ) -> retval
```

```cpp
cv::Vec4f cv::Mat::Vec4f_at( int row,
                             int col );
AutoIt:
    $oMat.Vec4f_at( $row, $col ) -> retval
```

```cpp
cv::Vec4f cv::Mat::Vec4f_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec4f_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec4f cv::Mat::Vec4f_at( cv::Point pt );
AutoIt:
    $oMat.Vec4f_at( $pt ) -> retval
```

```cpp
cv::Vec4f cv::Mat::Vec4f_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec4f_at( $idx ) -> retval
```

### cv::Mat::Vec4f\_set\_at

```cpp
void cv::Mat::Vec4f_set_at( int       i0,
                            cv::Vec4f value );
AutoIt:
    $oMat.Vec4f_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec4f_set_at( int       row,
                            int       col,
                            cv::Vec4f value );
AutoIt:
    $oMat.Vec4f_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec4f_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec4f value );
AutoIt:
    $oMat.Vec4f_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec4f_set_at( cv::Point pt,
                            cv::Vec4f value );
AutoIt:
    $oMat.Vec4f_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec4f_set_at( const std::vector<int>& idx,
                            cv::Vec4f               value );
AutoIt:
    $oMat.Vec4f_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec4i\_at

```cpp
cv::Vec4i cv::Mat::Vec4i_at( int i0 );
AutoIt:
    $oMat.Vec4i_at( $i0 ) -> retval
```

```cpp
cv::Vec4i cv::Mat::Vec4i_at( int row,
                             int col );
AutoIt:
    $oMat.Vec4i_at( $row, $col ) -> retval
```

```cpp
cv::Vec4i cv::Mat::Vec4i_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec4i_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec4i cv::Mat::Vec4i_at( cv::Point pt );
AutoIt:
    $oMat.Vec4i_at( $pt ) -> retval
```

```cpp
cv::Vec4i cv::Mat::Vec4i_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec4i_at( $idx ) -> retval
```

### cv::Mat::Vec4i\_set\_at

```cpp
void cv::Mat::Vec4i_set_at( int       i0,
                            cv::Vec4i value );
AutoIt:
    $oMat.Vec4i_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec4i_set_at( int       row,
                            int       col,
                            cv::Vec4i value );
AutoIt:
    $oMat.Vec4i_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec4i_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec4i value );
AutoIt:
    $oMat.Vec4i_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec4i_set_at( cv::Point pt,
                            cv::Vec4i value );
AutoIt:
    $oMat.Vec4i_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec4i_set_at( const std::vector<int>& idx,
                            cv::Vec4i               value );
AutoIt:
    $oMat.Vec4i_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec4s\_at

```cpp
cv::Vec4s cv::Mat::Vec4s_at( int i0 );
AutoIt:
    $oMat.Vec4s_at( $i0 ) -> retval
```

```cpp
cv::Vec4s cv::Mat::Vec4s_at( int row,
                             int col );
AutoIt:
    $oMat.Vec4s_at( $row, $col ) -> retval
```

```cpp
cv::Vec4s cv::Mat::Vec4s_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec4s_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec4s cv::Mat::Vec4s_at( cv::Point pt );
AutoIt:
    $oMat.Vec4s_at( $pt ) -> retval
```

```cpp
cv::Vec4s cv::Mat::Vec4s_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec4s_at( $idx ) -> retval
```

### cv::Mat::Vec4s\_set\_at

```cpp
void cv::Mat::Vec4s_set_at( int       i0,
                            cv::Vec4s value );
AutoIt:
    $oMat.Vec4s_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec4s_set_at( int       row,
                            int       col,
                            cv::Vec4s value );
AutoIt:
    $oMat.Vec4s_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec4s_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec4s value );
AutoIt:
    $oMat.Vec4s_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec4s_set_at( cv::Point pt,
                            cv::Vec4s value );
AutoIt:
    $oMat.Vec4s_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec4s_set_at( const std::vector<int>& idx,
                            cv::Vec4s               value );
AutoIt:
    $oMat.Vec4s_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec4w\_at

```cpp
cv::Vec4w cv::Mat::Vec4w_at( int i0 );
AutoIt:
    $oMat.Vec4w_at( $i0 ) -> retval
```

```cpp
cv::Vec4w cv::Mat::Vec4w_at( int row,
                             int col );
AutoIt:
    $oMat.Vec4w_at( $row, $col ) -> retval
```

```cpp
cv::Vec4w cv::Mat::Vec4w_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec4w_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec4w cv::Mat::Vec4w_at( cv::Point pt );
AutoIt:
    $oMat.Vec4w_at( $pt ) -> retval
```

```cpp
cv::Vec4w cv::Mat::Vec4w_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec4w_at( $idx ) -> retval
```

### cv::Mat::Vec4w\_set\_at

```cpp
void cv::Mat::Vec4w_set_at( int       i0,
                            cv::Vec4w value );
AutoIt:
    $oMat.Vec4w_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec4w_set_at( int       row,
                            int       col,
                            cv::Vec4w value );
AutoIt:
    $oMat.Vec4w_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec4w_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec4w value );
AutoIt:
    $oMat.Vec4w_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec4w_set_at( cv::Point pt,
                            cv::Vec4w value );
AutoIt:
    $oMat.Vec4w_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec4w_set_at( const std::vector<int>& idx,
                            cv::Vec4w               value );
AutoIt:
    $oMat.Vec4w_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec6d\_at

```cpp
cv::Vec6d cv::Mat::Vec6d_at( int i0 );
AutoIt:
    $oMat.Vec6d_at( $i0 ) -> retval
```

```cpp
cv::Vec6d cv::Mat::Vec6d_at( int row,
                             int col );
AutoIt:
    $oMat.Vec6d_at( $row, $col ) -> retval
```

```cpp
cv::Vec6d cv::Mat::Vec6d_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec6d_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec6d cv::Mat::Vec6d_at( cv::Point pt );
AutoIt:
    $oMat.Vec6d_at( $pt ) -> retval
```

```cpp
cv::Vec6d cv::Mat::Vec6d_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec6d_at( $idx ) -> retval
```

### cv::Mat::Vec6d\_set\_at

```cpp
void cv::Mat::Vec6d_set_at( int       i0,
                            cv::Vec6d value );
AutoIt:
    $oMat.Vec6d_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec6d_set_at( int       row,
                            int       col,
                            cv::Vec6d value );
AutoIt:
    $oMat.Vec6d_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec6d_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec6d value );
AutoIt:
    $oMat.Vec6d_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec6d_set_at( cv::Point pt,
                            cv::Vec6d value );
AutoIt:
    $oMat.Vec6d_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec6d_set_at( const std::vector<int>& idx,
                            cv::Vec6d               value );
AutoIt:
    $oMat.Vec6d_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec6f\_at

```cpp
cv::Vec6f cv::Mat::Vec6f_at( int i0 );
AutoIt:
    $oMat.Vec6f_at( $i0 ) -> retval
```

```cpp
cv::Vec6f cv::Mat::Vec6f_at( int row,
                             int col );
AutoIt:
    $oMat.Vec6f_at( $row, $col ) -> retval
```

```cpp
cv::Vec6f cv::Mat::Vec6f_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec6f_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec6f cv::Mat::Vec6f_at( cv::Point pt );
AutoIt:
    $oMat.Vec6f_at( $pt ) -> retval
```

```cpp
cv::Vec6f cv::Mat::Vec6f_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec6f_at( $idx ) -> retval
```

### cv::Mat::Vec6f\_set\_at

```cpp
void cv::Mat::Vec6f_set_at( int       i0,
                            cv::Vec6f value );
AutoIt:
    $oMat.Vec6f_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec6f_set_at( int       row,
                            int       col,
                            cv::Vec6f value );
AutoIt:
    $oMat.Vec6f_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec6f_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec6f value );
AutoIt:
    $oMat.Vec6f_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec6f_set_at( cv::Point pt,
                            cv::Vec6f value );
AutoIt:
    $oMat.Vec6f_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec6f_set_at( const std::vector<int>& idx,
                            cv::Vec6f               value );
AutoIt:
    $oMat.Vec6f_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec6i\_at

```cpp
cv::Vec6i cv::Mat::Vec6i_at( int i0 );
AutoIt:
    $oMat.Vec6i_at( $i0 ) -> retval
```

```cpp
cv::Vec6i cv::Mat::Vec6i_at( int row,
                             int col );
AutoIt:
    $oMat.Vec6i_at( $row, $col ) -> retval
```

```cpp
cv::Vec6i cv::Mat::Vec6i_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec6i_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec6i cv::Mat::Vec6i_at( cv::Point pt );
AutoIt:
    $oMat.Vec6i_at( $pt ) -> retval
```

```cpp
cv::Vec6i cv::Mat::Vec6i_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec6i_at( $idx ) -> retval
```

### cv::Mat::Vec6i\_set\_at

```cpp
void cv::Mat::Vec6i_set_at( int       i0,
                            cv::Vec6i value );
AutoIt:
    $oMat.Vec6i_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec6i_set_at( int       row,
                            int       col,
                            cv::Vec6i value );
AutoIt:
    $oMat.Vec6i_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec6i_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec6i value );
AutoIt:
    $oMat.Vec6i_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec6i_set_at( cv::Point pt,
                            cv::Vec6i value );
AutoIt:
    $oMat.Vec6i_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec6i_set_at( const std::vector<int>& idx,
                            cv::Vec6i               value );
AutoIt:
    $oMat.Vec6i_set_at( $idx, $value ) -> None
```

### cv::Mat::Vec8i\_at

```cpp
cv::Vec8i cv::Mat::Vec8i_at( int i0 );
AutoIt:
    $oMat.Vec8i_at( $i0 ) -> retval
```

```cpp
cv::Vec8i cv::Mat::Vec8i_at( int row,
                             int col );
AutoIt:
    $oMat.Vec8i_at( $row, $col ) -> retval
```

```cpp
cv::Vec8i cv::Mat::Vec8i_at( int i0,
                             int i1,
                             int i2 );
AutoIt:
    $oMat.Vec8i_at( $i0, $i1, $i2 ) -> retval
```

```cpp
cv::Vec8i cv::Mat::Vec8i_at( cv::Point pt );
AutoIt:
    $oMat.Vec8i_at( $pt ) -> retval
```

```cpp
cv::Vec8i cv::Mat::Vec8i_at( const std::vector<int>& idx );
AutoIt:
    $oMat.Vec8i_at( $idx ) -> retval
```

### cv::Mat::Vec8i\_set\_at

```cpp
void cv::Mat::Vec8i_set_at( int       i0,
                            cv::Vec8i value );
AutoIt:
    $oMat.Vec8i_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::Vec8i_set_at( int       row,
                            int       col,
                            cv::Vec8i value );
AutoIt:
    $oMat.Vec8i_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::Vec8i_set_at( int       i0,
                            int       i1,
                            int       i2,
                            cv::Vec8i value );
AutoIt:
    $oMat.Vec8i_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::Vec8i_set_at( cv::Point pt,
                            cv::Vec8i value );
AutoIt:
    $oMat.Vec8i_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::Vec8i_set_at( const std::vector<int>& idx,
                            cv::Vec8i               value );
AutoIt:
    $oMat.Vec8i_set_at( $idx, $value ) -> None
```

### cv::Mat::adjustROI

```cpp
std::shared_ptr<cv::Mat> cv::Mat::adjustROI( int dtop,
                                             int dbottom,
                                             int dleft,
                                             int dright );
AutoIt:
    $oMat.adjustROI( $dtop, $dbottom, $dleft, $dright ) -> retval
```

### cv::Mat::asArray

```cpp
_variant_t cv::Mat::asArray();
AutoIt:
    $oMat.asArray() -> retval
```

### cv::Mat::assignTo

```cpp
void cv::Mat::assignTo( const cv::Mat& m,
                        int            type = -1 );
AutoIt:
    $oMat.assignTo( $m[, $type] ) -> None
```

### cv::Mat::at

```cpp
double cv::Mat::at( int i0 );
AutoIt:
    $oMat.at( $i0 ) -> retval
```

```cpp
double cv::Mat::at( int row,
                    int col );
AutoIt:
    $oMat.at( $row, $col ) -> retval
```

```cpp
double cv::Mat::at( int i0,
                    int i1,
                    int i2 );
AutoIt:
    $oMat.at( $i0, $i1, $i2 ) -> retval
```

```cpp
double cv::Mat::at( cv::Point pt );
AutoIt:
    $oMat.at( $pt ) -> retval
```

```cpp
double cv::Mat::at( const std::vector<int>& idx );
AutoIt:
    $oMat.at( $idx ) -> retval
```

### cv::Mat::channels

```cpp
int cv::Mat::channels();
AutoIt:
    $oMat.channels() -> retval
```

### cv::Mat::checkVector

```cpp
int cv::Mat::checkVector( int elemChannels,
                          int depth = -1,
                          int requireContinuous = true );
AutoIt:
    $oMat.checkVector( $elemChannels[, $depth[, $requireContinuous]] ) -> retval
```

### cv::Mat::clone

```cpp
cv::Mat cv::Mat::clone();
AutoIt:
    $oMat.clone() -> retval
```

### cv::Mat::col

```cpp
cv::Mat cv::Mat::col( int x );
AutoIt:
    $oMat.col( $x ) -> retval
```

### cv::Mat::colRange

```cpp
cv::Mat cv::Mat::colRange( int startcol,
                           int endcol = __self->get()->cols );
AutoIt:
    $oMat.colRange( $startcol[, $endcol] ) -> retval
```

```cpp
cv::Mat cv::Mat::colRange( const cv::Range& r );
AutoIt:
    $oMat.colRange( $r ) -> retval
```

### cv::Mat::convertTo

```cpp
void cv::Mat::convertTo( OutputArray m,
                         int         rtype,
                         double      alpha = 1.0,
                         double      beta = 0.0 );
AutoIt:
    $oMat.convertTo( $rtype[, $m[, $alpha[, $beta]]] ) -> $m
```

```cpp
void cv::Mat::convertTo( OutputArray m,
                         int         rtype = -1,
                         double      alpha = 1.0,
                         double      beta = 0.0 );
AutoIt:
    $oMat.convertTo( [$m[, $rtype[, $alpha[, $beta]]]] ) -> $m
```

### cv::Mat::convertToBitmap

```cpp
void* cv::Mat::convertToBitmap( bool copy = true );
AutoIt:
    $oMat.convertToBitmap( [$copy] ) -> retval
```

### cv::Mat::convertToShow

```cpp
void cv::Mat::convertToShow( cv::Mat dst = Mat::zeros(__self->get()->rows, __self->get()->cols, CV_8UC3),
                             bool    toRGB = false );
AutoIt:
    $oMat.convertToShow( [$dst[, $toRGB]] ) -> $dst
```

### cv::Mat::copy

```cpp
cv::Mat cv::Mat::copy();
AutoIt:
    $oMat.copy() -> retval
```

### cv::Mat::copySize

```cpp
void cv::Mat::copySize( const cv::Mat& m );
AutoIt:
    $oMat.copySize( $m ) -> None
```

### cv::Mat::copyTo

```cpp
void cv::Mat::copyTo( OutputArray m );
AutoIt:
    $oMat.copyTo( [$m] ) -> $m
```

```cpp
void cv::Mat::copyTo( OutputArray m,
                      InputArray  mask );
AutoIt:
    $oMat.copyTo( $mask[, $m] ) -> $m
```

### cv::Mat::createFromArray

```cpp
static cv::Mat cv::Mat::createFromArray( _variant_t array,
                                         int        depth = -1 );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromArray( $array[, $depth] ) -> retval
```

### cv::Mat::createFromVec2b

```cpp
static cv::Mat cv::Mat::createFromVec2b( cv::Vec2b vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec2b( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec2d

```cpp
static cv::Mat cv::Mat::createFromVec2d( cv::Vec2d vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec2d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec2f

```cpp
static cv::Mat cv::Mat::createFromVec2f( cv::Vec2f vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec2f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec2i

```cpp
static cv::Mat cv::Mat::createFromVec2i( cv::Vec2i vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec2i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec2s

```cpp
static cv::Mat cv::Mat::createFromVec2s( cv::Vec2s vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec2s( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec2w

```cpp
static cv::Mat cv::Mat::createFromVec2w( cv::Vec2w vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec2w( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec3b

```cpp
static cv::Mat cv::Mat::createFromVec3b( cv::Vec3b vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec3b( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec3d

```cpp
static cv::Mat cv::Mat::createFromVec3d( cv::Vec3d vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec3d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec3f

```cpp
static cv::Mat cv::Mat::createFromVec3f( cv::Vec3f vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec3f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec3i

```cpp
static cv::Mat cv::Mat::createFromVec3i( cv::Vec3i vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec3i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec3s

```cpp
static cv::Mat cv::Mat::createFromVec3s( cv::Vec3s vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec3s( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec3w

```cpp
static cv::Mat cv::Mat::createFromVec3w( cv::Vec3w vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec3w( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec4b

```cpp
static cv::Mat cv::Mat::createFromVec4b( cv::Vec4b vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec4b( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec4d

```cpp
static cv::Mat cv::Mat::createFromVec4d( cv::Vec4d vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec4d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec4f

```cpp
static cv::Mat cv::Mat::createFromVec4f( cv::Vec4f vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec4f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec4i

```cpp
static cv::Mat cv::Mat::createFromVec4i( cv::Vec4i vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec4i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec4s

```cpp
static cv::Mat cv::Mat::createFromVec4s( cv::Vec4s vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec4s( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec4w

```cpp
static cv::Mat cv::Mat::createFromVec4w( cv::Vec4w vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec4w( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec6d

```cpp
static cv::Mat cv::Mat::createFromVec6d( cv::Vec6d vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec6d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec6f

```cpp
static cv::Mat cv::Mat::createFromVec6f( cv::Vec6f vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec6f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec6i

```cpp
static cv::Mat cv::Mat::createFromVec6i( cv::Vec6i vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec6i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVec8i

```cpp
static cv::Mat cv::Mat::createFromVec8i( cv::Vec8i vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVec8i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfDouble

```cpp
static cv::Mat cv::Mat::createFromVectorOfDouble( std::vector<double> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfDouble( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfFloat

```cpp
static cv::Mat cv::Mat::createFromVectorOfFloat( std::vector<float> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfFloat( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfInt

```cpp
static cv::Mat cv::Mat::createFromVectorOfInt( std::vector<int> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfInt( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfMat

```cpp
static std::shared_ptr<cv::Mat> cv::Mat::createFromVectorOfMat( std::vector<cv::Mat> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfMat( $vec ) -> retval
```

### cv::Mat::createFromVectorOfVec2b

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec2b( std::vector<cv::Vec2b> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec2b( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec2d

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec2d( std::vector<cv::Vec2d> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec2d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec2f

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec2f( std::vector<cv::Vec2f> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec2f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec2i

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec2i( std::vector<cv::Vec2i> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec2i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec2s

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec2s( std::vector<cv::Vec2s> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec2s( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec2w

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec2w( std::vector<cv::Vec2w> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec2w( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec3b

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec3b( std::vector<cv::Vec3b> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec3b( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec3d

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec3d( std::vector<cv::Vec3d> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec3d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec3f

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec3f( std::vector<cv::Vec3f> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec3f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec3i

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec3i( std::vector<cv::Vec3i> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec3i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec3s

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec3s( std::vector<cv::Vec3s> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec3s( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec3w

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec3w( std::vector<cv::Vec3w> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec3w( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec4b

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec4b( std::vector<cv::Vec4b> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec4b( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec4d

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec4d( std::vector<cv::Vec4d> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec4d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec4f

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec4f( std::vector<cv::Vec4f> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec4f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec4i

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec4i( std::vector<cv::Vec4i> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec4i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec4s

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec4s( std::vector<cv::Vec4s> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec4s( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec4w

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec4w( std::vector<cv::Vec4w> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec4w( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec6d

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec6d( std::vector<cv::Vec6d> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec6d( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec6f

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec6f( std::vector<cv::Vec6f> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec6f( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec6i

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec6i( std::vector<cv::Vec6i> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec6i( $vec ) -> <cv.Mat object>
```

### cv::Mat::createFromVectorOfVec8i

```cpp
static cv::Mat cv::Mat::createFromVectorOfVec8i( std::vector<cv::Vec8i> vec );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").createFromVectorOfVec8i( $vec ) -> <cv.Mat object>
```

### cv::Mat::cross

```cpp
cv::Mat cv::Mat::cross( InputArray m );
AutoIt:
    $oMat.cross( $m ) -> retval
```

### cv::Mat::depth

```cpp
int cv::Mat::depth();
AutoIt:
    $oMat.depth() -> retval
```

### cv::Mat::diag

```cpp
cv::Mat cv::Mat::diag( int d = 0 );
AutoIt:
    $oMat.diag( [$d] ) -> retval
```

```cpp
static cv::Mat cv::Mat::diag( const cv::Mat& d );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").diag( $d ) -> retval
```

### cv::Mat::dot

```cpp
double cv::Mat::dot( InputArray m );
AutoIt:
    $oMat.dot( $m ) -> retval
```

### cv::Mat::double\_at

```cpp
double cv::Mat::double_at( int i0 );
AutoIt:
    $oMat.double_at( $i0 ) -> retval
```

```cpp
double cv::Mat::double_at( int row,
                           int col );
AutoIt:
    $oMat.double_at( $row, $col ) -> retval
```

```cpp
double cv::Mat::double_at( int i0,
                           int i1,
                           int i2 );
AutoIt:
    $oMat.double_at( $i0, $i1, $i2 ) -> retval
```

```cpp
double cv::Mat::double_at( cv::Point pt );
AutoIt:
    $oMat.double_at( $pt ) -> retval
```

```cpp
double cv::Mat::double_at( const std::vector<int>& idx );
AutoIt:
    $oMat.double_at( $idx ) -> retval
```

### cv::Mat::double\_set\_at

```cpp
void cv::Mat::double_set_at( int    i0,
                             double value );
AutoIt:
    $oMat.double_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::double_set_at( int    row,
                             int    col,
                             double value );
AutoIt:
    $oMat.double_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::double_set_at( int    i0,
                             int    i1,
                             int    i2,
                             double value );
AutoIt:
    $oMat.double_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::double_set_at( cv::Point pt,
                             double    value );
AutoIt:
    $oMat.double_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::double_set_at( const std::vector<int>& idx,
                             double                  value );
AutoIt:
    $oMat.double_set_at( $idx, $value ) -> None
```

### cv::Mat::elemSize

```cpp
size_t cv::Mat::elemSize();
AutoIt:
    $oMat.elemSize() -> retval
```

### cv::Mat::elemSize1

```cpp
size_t cv::Mat::elemSize1();
AutoIt:
    $oMat.elemSize1() -> retval
```

### cv::Mat::empty

```cpp
bool cv::Mat::empty();
AutoIt:
    $oMat.empty() -> retval
```

### cv::Mat::eye

```cpp
static cv::Mat cv::Mat::eye( int rows,
                             int cols,
                             int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").eye( $rows, $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::eye( int rows,
                             int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").eye( $rows, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::eye( int cols,
                             int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").eye( $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::eye( cv::Size size,
                             int      type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").eye( $size, $type ) -> retval
```

### cv::Mat::float\_at

```cpp
float cv::Mat::float_at( int i0 );
AutoIt:
    $oMat.float_at( $i0 ) -> retval
```

```cpp
float cv::Mat::float_at( int row,
                         int col );
AutoIt:
    $oMat.float_at( $row, $col ) -> retval
```

```cpp
float cv::Mat::float_at( int i0,
                         int i1,
                         int i2 );
AutoIt:
    $oMat.float_at( $i0, $i1, $i2 ) -> retval
```

```cpp
float cv::Mat::float_at( cv::Point pt );
AutoIt:
    $oMat.float_at( $pt ) -> retval
```

```cpp
float cv::Mat::float_at( const std::vector<int>& idx );
AutoIt:
    $oMat.float_at( $idx ) -> retval
```

### cv::Mat::float\_set\_at

```cpp
void cv::Mat::float_set_at( int   i0,
                            float value );
AutoIt:
    $oMat.float_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::float_set_at( int   row,
                            int   col,
                            float value );
AutoIt:
    $oMat.float_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::float_set_at( int   i0,
                            int   i1,
                            int   i2,
                            float value );
AutoIt:
    $oMat.float_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::float_set_at( cv::Point pt,
                            float     value );
AutoIt:
    $oMat.float_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::float_set_at( const std::vector<int>& idx,
                            float                   value );
AutoIt:
    $oMat.float_set_at( $idx, $value ) -> None
```

### cv::Mat::getUMat

```cpp
cv::UMat cv::Mat::getUMat( cv::AccessFlag     accessFlags,
                           cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    $oMat.getUMat( $accessFlags[, $usageFlags] ) -> retval
```

### cv::Mat::get\_Item

```cpp
double cv::Mat::get_Item( int i0 );
AutoIt:
    $oMat.Item( $i0 ) -> retval
    $oMat( $i0 ) -> retval
```

```cpp
double cv::Mat::get_Item( int row,
                          int col );
AutoIt:
    $oMat.Item( $row, $col ) -> retval
    $oMat( $row, $col ) -> retval
```

```cpp
double cv::Mat::get_Item( int i0,
                          int i1,
                          int i2 );
AutoIt:
    $oMat.Item( $i0, $i1, $i2 ) -> retval
    $oMat( $i0, $i1, $i2 ) -> retval
```

```cpp
double cv::Mat::get_Item( cv::Point pt );
AutoIt:
    $oMat.Item( $pt ) -> retval
    $oMat( $pt ) -> retval
```

```cpp
double cv::Mat::get_Item( const std::vector<int>& idx );
AutoIt:
    $oMat.Item( $idx ) -> retval
    $oMat( $idx ) -> retval
```

### cv::Mat::int\_at

```cpp
int cv::Mat::int_at( int i0 );
AutoIt:
    $oMat.int_at( $i0 ) -> retval
```

```cpp
int cv::Mat::int_at( int row,
                     int col );
AutoIt:
    $oMat.int_at( $row, $col ) -> retval
```

```cpp
int cv::Mat::int_at( int i0,
                     int i1,
                     int i2 );
AutoIt:
    $oMat.int_at( $i0, $i1, $i2 ) -> retval
```

```cpp
int cv::Mat::int_at( cv::Point pt );
AutoIt:
    $oMat.int_at( $pt ) -> retval
```

```cpp
int cv::Mat::int_at( const std::vector<int>& idx );
AutoIt:
    $oMat.int_at( $idx ) -> retval
```

### cv::Mat::int\_set\_at

```cpp
void cv::Mat::int_set_at( int i0,
                          int value );
AutoIt:
    $oMat.int_set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::int_set_at( int row,
                          int col,
                          int value );
AutoIt:
    $oMat.int_set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::int_set_at( int i0,
                          int i1,
                          int i2,
                          int value );
AutoIt:
    $oMat.int_set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::int_set_at( cv::Point pt,
                          int       value );
AutoIt:
    $oMat.int_set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::int_set_at( const std::vector<int>& idx,
                          int                     value );
AutoIt:
    $oMat.int_set_at( $idx, $value ) -> None
```

### cv::Mat::inv

```cpp
cv::Mat cv::Mat::inv( int method = DECOMP_LU );
AutoIt:
    $oMat.inv( [$method] ) -> retval
```

### cv::Mat::isContinuous

```cpp
bool cv::Mat::isContinuous();
AutoIt:
    $oMat.isContinuous() -> retval
```

### cv::Mat::isSubmatrix

```cpp
bool cv::Mat::isSubmatrix();
AutoIt:
    $oMat.isSubmatrix() -> retval
```

### cv::Mat::locateROI

```cpp
void cv::Mat::locateROI( cv::Size&  wholeSize,
                         cv::Point& ofs );
AutoIt:
    $oMat.locateROI( [$wholeSize[, $ofs]] ) -> $wholeSize, $ofs
```

### cv::Mat::makeInputArray

```cpp
std::shared_ptr<cv::_InputArray> cv::Mat::makeInputArray();
AutoIt:
    $oMat.makeInputArray() -> retval
```

### cv::Mat::makeInputOutputArray

```cpp
std::shared_ptr<cv::_InputOutputArray> cv::Mat::makeInputOutputArray();
AutoIt:
    $oMat.makeInputOutputArray() -> retval
```

### cv::Mat::makeOutputArray

```cpp
std::shared_ptr<cv::_OutputArray> cv::Mat::makeOutputArray();
AutoIt:
    $oMat.makeOutputArray() -> retval
```

### cv::Mat::mul

```cpp
cv::Mat cv::Mat::mul( InputArray m,
                      double     scale = 1 );
AutoIt:
    $oMat.mul( $m[, $scale] ) -> retval
```

### cv::Mat::ones

```cpp
static cv::Mat cv::Mat::ones( int rows,
                              int cols,
                              int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").ones( $rows, $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::ones( int cols,
                              int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").ones( $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::ones( int rows,
                              int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").ones( $rows, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::ones( cv::Size size,
                              int      type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").ones( $size, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::ones( std::vector<int> sizes,
                              int              type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").ones( $sizes, $type ) -> retval
```

### cv::Mat::pop\_back

```cpp
void cv::Mat::pop_back( size_t value );
AutoIt:
    $oMat.pop_back( $value ) -> None
```

### cv::Mat::ptr

```cpp
uchar* cv::Mat::ptr( int y = 0 );
AutoIt:
    $oMat.ptr( [$y] ) -> retval
```

```cpp
uchar* cv::Mat::ptr( int i0,
                     int i1 );
AutoIt:
    $oMat.ptr( $i0, $i1 ) -> retval
```

```cpp
uchar* cv::Mat::ptr( int i0,
                     int i1,
                     int i2 );
AutoIt:
    $oMat.ptr( $i0, $i1, $i2 ) -> retval
```

```cpp
uchar* cv::Mat::ptr( const std::vector<int>& idx = std::vector<int>() );
AutoIt:
    $oMat.ptr( [$idx] ) -> retval
```

### cv::Mat::push\_back

```cpp
void cv::Mat::push_back( const cv::Mat& m );
AutoIt:
    $oMat.push_back( $m ) -> None
```

### cv::Mat::put\_Item

```cpp
void cv::Mat::put_Item( int    i0,
                        double value );
AutoIt:
    $oMat.Item( $i0 ) = $value
```

```cpp
void cv::Mat::put_Item( int    row,
                        int    col,
                        double value );
AutoIt:
    $oMat.Item( $row, $col ) = $value
```

```cpp
void cv::Mat::put_Item( int    i0,
                        int    i1,
                        int    i2,
                        double value );
AutoIt:
    $oMat.Item( $i0, $i1, $i2 ) = $value
```

```cpp
void cv::Mat::put_Item( cv::Point pt,
                        double    value );
AutoIt:
    $oMat.Item( $pt ) = $value
```

```cpp
void cv::Mat::put_Item( const std::vector<int>& idx,
                        double                  value );
AutoIt:
    $oMat.Item( $idx ) = $value
```

### cv::Mat::reserve

```cpp
void cv::Mat::reserve( size_t sz );
AutoIt:
    $oMat.reserve( $sz ) -> None
```

### cv::Mat::reserveBuffer

```cpp
void cv::Mat::reserveBuffer( size_t sz );
AutoIt:
    $oMat.reserveBuffer( $sz ) -> None
```

### cv::Mat::reshape

```cpp
cv::Mat cv::Mat::reshape( int cn,
                          int rows = 0 );
AutoIt:
    $oMat.reshape( $cn[, $rows] ) -> retval
```

```cpp
cv::Mat cv::Mat::reshape( int                     cn,
                          const std::vector<int>& newshape );
AutoIt:
    $oMat.reshape( $cn, $newshape ) -> retval
```

### cv::Mat::resize

```cpp
void cv::Mat::resize( size_t sz );
AutoIt:
    $oMat.resize( $sz ) -> None
```

```cpp
void cv::Mat::resize( size_t            sz,
                      const cv::Scalar& s );
AutoIt:
    $oMat.resize( $sz, $s ) -> None
```

### cv::Mat::row

```cpp
cv::Mat cv::Mat::row( int y );
AutoIt:
    $oMat.row( $y ) -> retval
```

### cv::Mat::rowRange

```cpp
cv::Mat cv::Mat::rowRange( int startrow,
                           int endrow = __self->get()->rows );
AutoIt:
    $oMat.rowRange( $startrow[, $endrow] ) -> retval
```

```cpp
cv::Mat cv::Mat::rowRange( cv::Range r );
AutoIt:
    $oMat.rowRange( $r ) -> retval
```

### cv::Mat::setTo

```cpp
void cv::Mat::setTo( InputArray value,
                     InputArray mask = noArray() );
AutoIt:
    $oMat.setTo( $value[, $mask] ) -> None
```

### cv::Mat::set\_at

```cpp
void cv::Mat::set_at( int    i0,
                      double value );
AutoIt:
    $oMat.set_at( $i0, $value ) -> None
```

```cpp
void cv::Mat::set_at( int    row,
                      int    col,
                      double value );
AutoIt:
    $oMat.set_at( $row, $col, $value ) -> None
```

```cpp
void cv::Mat::set_at( int    i0,
                      int    i1,
                      int    i2,
                      double value );
AutoIt:
    $oMat.set_at( $i0, $i1, $i2, $value ) -> None
```

```cpp
void cv::Mat::set_at( cv::Point pt,
                      double    value );
AutoIt:
    $oMat.set_at( $pt, $value ) -> None
```

```cpp
void cv::Mat::set_at( const std::vector<int>& idx,
                      double                  value );
AutoIt:
    $oMat.set_at( $idx, $value ) -> None
```

### cv::Mat::size

```cpp
cv::Size cv::Mat::size();
AutoIt:
    $oMat.size() -> retval
```

### cv::Mat::step1

```cpp
size_t cv::Mat::step1( int i = 0 );
AutoIt:
    $oMat.step1( [$i] ) -> retval
```

### cv::Mat::t

```cpp
cv::Mat cv::Mat::t();
AutoIt:
    $oMat.t() -> retval
```

### cv::Mat::total

```cpp
size_t cv::Mat::total();
AutoIt:
    $oMat.total() -> retval
```

```cpp
size_t cv::Mat::total( int startDim,
                       int endDim = INT_MAX );
AutoIt:
    $oMat.total( $startDim[, $endDim] ) -> retval
```

### cv::Mat::type

```cpp
int cv::Mat::type();
AutoIt:
    $oMat.type() -> retval
```

### cv::Mat::updateContinuityFlag

```cpp
void cv::Mat::updateContinuityFlag();
AutoIt:
    $oMat.updateContinuityFlag() -> None
```

### cv::Mat::zeros

```cpp
static cv::Mat cv::Mat::zeros( int rows,
                               int cols,
                               int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").zeros( $rows, $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::zeros( int cols,
                               int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").zeros( $cols, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::zeros( int rows,
                               int type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").zeros( $rows, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::zeros( cv::Size size,
                               int      type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").zeros( $size, $type ) -> retval
```

```cpp
static cv::Mat cv::Mat::zeros( std::vector<int> sizes,
                               int              type );
AutoIt:
    _Dlib_ObjCreate("cv.Mat").zeros( $sizes, $type ) -> retval
```

## dlib::Matrix

### Matrix.shape

```cpp
std::tuple<long, long> dlib::Matrix::shape
AutoIt:
    [propget] $oMatrix.shape
```

### dlib::Matrix::get\_create

```cpp
static dlib::Matrix dlib::Matrix::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.matrix").create() -> <dlib.Matrix object>
```

```cpp
std::shared_ptr<dlib::Matrix> dlib::Matrix::get_create( std::vector<double> list );
AutoIt:
    $oMatrix.create( $list ) -> retval
    $oMatrix( $list ) -> retval
```

```cpp
std::shared_ptr<dlib::Matrix> dlib::Matrix::get_create( std::vector<std::vector<double>> list );
AutoIt:
    $oMatrix.create( $list ) -> retval
    $oMatrix( $list ) -> retval
```

```cpp
std::shared_ptr<dlib::Matrix> dlib::Matrix::get_create( long rows,
                                                        long cols );
AutoIt:
    $oMatrix.create( $rows, $cols ) -> retval
    $oMatrix( $rows, $cols ) -> retval
```

### dlib::Matrix::ToString

```cpp
std::string dlib::Matrix::ToString();
AutoIt:
    $oMatrix.ToString() -> retval
```

### dlib::Matrix::deserialize

```cpp
void dlib::Matrix::deserialize( std::string file );
AutoIt:
    $oMatrix.deserialize( $file ) -> None
```

### dlib::Matrix::get

```cpp
dlib::_row dlib::Matrix::get( long row );
AutoIt:
    $oMatrix.get( $row ) -> retval
```

### dlib::Matrix::nc

```cpp
long dlib::Matrix::nc();
AutoIt:
    $oMatrix.nc() -> retval
```

### dlib::Matrix::nr

```cpp
long dlib::Matrix::nr();
AutoIt:
    $oMatrix.nr() -> retval
```

### dlib::Matrix::serialize

```cpp
void dlib::Matrix::serialize( std::string file );
AutoIt:
    $oMatrix.serialize( $file ) -> None
```

### dlib::Matrix::set\_size

```cpp
void dlib::Matrix::set_size( long rows,
                             long cols );
AutoIt:
    $oMatrix.set_size( $rows, $cols ) -> None
```

## std

### std.mutex

```cpp
static std::mutex
AutoIt:
    [propget] $ostd.mutex
```

### std.timed\_mutex

```cpp
static std::timed_mutex
AutoIt:
    [propget] $ostd.timed_mutex
```

## std::mutex

### std::mutex::get\_create

```cpp
static std::mutex std::mutex::get_create();
AutoIt:
    _Dlib_ObjCreate("std.mutex").create() -> <std.mutex object>
```

### std::mutex::lock

```cpp
void std::mutex::lock();
AutoIt:
    $omutex.lock() -> None
```

### std::mutex::try\_lock

```cpp
bool std::mutex::try_lock();
AutoIt:
    $omutex.try_lock() -> retval
```

### std::mutex::unlock

```cpp
void std::mutex::unlock();
AutoIt:
    $omutex.unlock() -> None
```

## std::timed\_mutex

### std::timed\_mutex::get\_create

```cpp
static std::timed_mutex std::timed_mutex::get_create();
AutoIt:
    _Dlib_ObjCreate("std.timed_mutex").create() -> <std.timed_mutex object>
```

### std::timed\_mutex::lock

```cpp
void std::timed_mutex::lock();
AutoIt:
    $otimed_mutex.lock() -> None
```

### std::timed\_mutex::try\_lock

```cpp
bool std::timed_mutex::try_lock();
AutoIt:
    $otimed_mutex.try_lock() -> retval
```

### std::timed\_mutex::try\_lock\_for

```cpp
bool std::timed_mutex::try_lock_for( int duration );
AutoIt:
    $otimed_mutex.try_lock_for( $duration ) -> retval
```

### std::timed\_mutex::unlock

```cpp
void std::timed_mutex::unlock();
AutoIt:
    $otimed_mutex.unlock() -> None
```

## dlib::fhog\_object\_detector

### fhog\_object\_detector.detection\_window\_width

```cpp
ULONG dlib::fhog_object_detector::get_scanner().get_detection_window_width()
AutoIt:
    [propget] $ofhog_object_detector.detection_window_width
```

### fhog\_object\_detector.detection\_window\_height

```cpp
ULONG dlib::fhog_object_detector::get_scanner().get_detection_window_height()
AutoIt:
    [propget] $ofhog_object_detector.detection_window_height
```

### fhog\_object\_detector.num\_detectors

```cpp
ULONG dlib::fhog_object_detector::num_detectors()
AutoIt:
    [propget] $ofhog_object_detector.num_detectors
```

### dlib::fhog\_object\_detector::create

```cpp
static dlib::fhog_object_detector dlib::fhog_object_detector::create();
AutoIt:
    _Dlib_ObjCreate("dlib.fhog_object_detector").create() -> <dlib.fhog_object_detector object>
```

```cpp
std::shared_ptr<dlib::fhog_object_detector> dlib::fhog_object_detector::create( std::string filename );
AutoIt:
    $ofhog_object_detector.create( $filename ) -> retval
```

### dlib::fhog\_object\_detector::get\_call

```cpp
void dlib::fhog_object_detector::get_call( cv::Mat                      image,
                                           std::vector<dlib::rectangle> rectangles,
                                           std::vector<double>          detection_confidences,
                                           std::vector<ULONG>           weight_indices,
                                           uint                         upsample_num_times = 0,
                                           double                       adjust_threshold = 0.0 );
AutoIt:
    $ofhog_object_detector.call( $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
    $ofhog_object_detector( $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

### dlib::fhog\_object\_detector::run

```cpp
void dlib::fhog_object_detector::run( cv::Mat                      image,
                                      std::vector<dlib::rectangle> rectangles,
                                      std::vector<double>          detection_confidences,
                                      std::vector<ULONG>           weight_indices,
                                      uint                         upsample_num_times = 0,
                                      double                       adjust_threshold = 0.0 );
AutoIt:
    $ofhog_object_detector.run( $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

### dlib::fhog\_object\_detector::run\_multiple

```cpp
static void dlib::fhog_object_detector::run_multiple( std::vector<dlib::fhog_object_detector> vectors,
                                                      cv::Mat                                 image,
                                                      std::vector<dlib::rectangle>            rectangles,
                                                      std::vector<double>                     detection_confidences,
                                                      std::vector<ULONG>                      weight_indices,
                                                      uint                                    upsample_num_times = 0,
                                                      double                                  adjust_threshold = 0.0 );
AutoIt:
    _Dlib_ObjCreate("dlib.fhog_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

```cpp
static void dlib::fhog_object_detector::run_multiple( std::vector<dlib::simple_object_detector_com> vectors,
                                                      cv::Mat                                       image,
                                                      std::vector<dlib::rectangle>                  rectangles,
                                                      std::vector<double>                           detection_confidences,
                                                      std::vector<ULONG>                            weight_indices,
                                                      uint                                          upsample_num_times = 0,
                                                      double                                        adjust_threshold = 0.0 );
AutoIt:
    _Dlib_ObjCreate("dlib.fhog_object_detector").run_multiple( $vectors, $image[, $upsample_num_times[, $adjust_threshold[, $rectangles[, $detection_confidences[, $weight_indices]]]]] ) -> $rectangles, $detection_confidences, $weight_indices
```

### dlib::fhog\_object\_detector::save

```cpp
void dlib::fhog_object_detector::save( std::string detector_output_filename );
AutoIt:
    $ofhog_object_detector.save( $detector_output_filename ) -> None
```

## cv::Range

### Range.start

```cpp
int cv::Range::start
AutoIt:
    [propget, propput] $oRange.start
```

### Range.end

```cpp
int cv::Range::end
AutoIt:
    [propget, propput] $oRange.end
```

### cv::Range::get\_create

```cpp
static cv::Range cv::Range::get_create();
AutoIt:
    _Dlib_ObjCreate("cv.Range").create() -> <cv.Range object>
```

```cpp
static cv::Range cv::Range::get_create( int start,
                                        int end );
AutoIt:
    _Dlib_ObjCreate("cv.Range").create( $start, $end ) -> <cv.Range object>
    $oRange( $start, $end ) -> <cv.Range object>
```

### cv::Range::all

```cpp
static cv::Range cv::Range::all();
AutoIt:
    _Dlib_ObjCreate("cv.Range").all() -> retval
```

### cv::Range::empty

```cpp
bool cv::Range::empty();
AutoIt:
    $oRange.empty() -> retval
```

### cv::Range::size

```cpp
int cv::Range::size();
AutoIt:
    $oRange.size() -> retval
```

## dlib::rect\_filter

### dlib::rect\_filter::create

```cpp
static dlib::rect_filter dlib::rect_filter::create();
AutoIt:
    _Dlib_ObjCreate("dlib.rect_filter").create() -> <dlib.rect_filter object>
```

```cpp
static dlib::rect_filter dlib::rect_filter::create( double measurement_noise,
                                                    double typical_acceleration,
                                                    double max_measurement_deviation );
AutoIt:
    _Dlib_ObjCreate("dlib.rect_filter").create( $measurement_noise, $typical_acceleration, $max_measurement_deviation ) -> <dlib.rect_filter object>
```

### dlib::rect\_filter::get\_call

```cpp
dlib::drectangle dlib::rect_filter::get_call( dlib::rectangle rect );
AutoIt:
    $orect_filter.call( $rect ) -> retval
    $orect_filter( $rect ) -> retval
```

```cpp
dlib::drectangle dlib::rect_filter::get_call( dlib::drectangle rect );
AutoIt:
    $orect_filter.call( $rect ) -> retval
    $orect_filter( $rect ) -> retval
```

### dlib::rect\_filter::max\_measurement\_deviation

```cpp
double dlib::rect_filter::max_measurement_deviation();
AutoIt:
    $orect_filter.max_measurement_deviation() -> retval
```

### dlib::rect\_filter::measurement\_noise

```cpp
double dlib::rect_filter::measurement_noise();
AutoIt:
    $orect_filter.measurement_noise() -> retval
```

### dlib::rect\_filter::typical\_acceleration

```cpp
double dlib::rect_filter::typical_acceleration();
AutoIt:
    $orect_filter.typical_acceleration() -> retval
```

## dlib::rectangle

### dlib::rectangle::get\_create

```cpp
static dlib::rectangle dlib::rectangle::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create() -> <dlib.rectangle object>
```

```cpp
static dlib::rectangle dlib::rectangle::get_create( long& left,
                                                    long& top,
                                                    long& right,
                                                    long& bottom );
AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create( $left, $top, $right, $bottom ) -> <dlib.rectangle object>
    $orectangle( $left, $top, $right, $bottom ) -> <dlib.rectangle object>
```

```cpp
static dlib::rectangle dlib::rectangle::get_create( dlib::drectangle& rect );
AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create( $rect ) -> <dlib.rectangle object>
    $orectangle( $rect ) -> <dlib.rectangle object>
```

```cpp
static dlib::rectangle dlib::rectangle::get_create( dlib::rectangle& rect );
AutoIt:
    _Dlib_ObjCreate("dlib.rectangle").create( $rect ) -> <dlib.rectangle object>
    $orectangle( $rect ) -> <dlib.rectangle object>
```

### dlib::rectangle::ToString

```cpp
std::string dlib::rectangle::ToString();
AutoIt:
    $orectangle.ToString() -> retval
```

### dlib::rectangle::area

```cpp
ULONG dlib::rectangle::area();
AutoIt:
    $orectangle.area() -> retval
```

### dlib::rectangle::bl\_corner

```cpp
dlib::point dlib::rectangle::bl_corner();
AutoIt:
    $orectangle.bl_corner() -> retval
```

### dlib::rectangle::bottom

```cpp
long dlib::rectangle::bottom();
AutoIt:
    $orectangle.bottom() -> retval
```

### dlib::rectangle::br\_corner

```cpp
dlib::point dlib::rectangle::br_corner();
AutoIt:
    $orectangle.br_corner() -> retval
```

### dlib::rectangle::center

```cpp
dlib::point dlib::rectangle::center();
AutoIt:
    $orectangle.center() -> retval
```

### dlib::rectangle::contains

```cpp
bool dlib::rectangle::contains( dlib::dpoint& point );
AutoIt:
    $orectangle.contains( $point ) -> retval
```

```cpp
bool dlib::rectangle::contains( dlib::point& point );
AutoIt:
    $orectangle.contains( $point ) -> retval
```

```cpp
bool dlib::rectangle::contains( long& x,
                                long& y );
AutoIt:
    $orectangle.contains( $x, $y ) -> retval
```

```cpp
bool dlib::rectangle::contains( dlib::rectangle& rect );
AutoIt:
    $orectangle.contains( $rect ) -> retval
```

### dlib::rectangle::dcenter

```cpp
dlib::dpoint dlib::rectangle::dcenter();
AutoIt:
    $orectangle.dcenter() -> retval
```

### dlib::rectangle::height

```cpp
ULONG dlib::rectangle::height();
AutoIt:
    $orectangle.height() -> retval
```

### dlib::rectangle::intersect

```cpp
dlib::rectangle dlib::rectangle::intersect( dlib::rectangle& rect );
AutoIt:
    $orectangle.intersect( $rect ) -> retval
```

### dlib::rectangle::is\_empty

```cpp
bool dlib::rectangle::is_empty();
AutoIt:
    $orectangle.is_empty() -> retval
```

### dlib::rectangle::left

```cpp
long dlib::rectangle::left();
AutoIt:
    $orectangle.left() -> retval
```

### dlib::rectangle::right

```cpp
long dlib::rectangle::right();
AutoIt:
    $orectangle.right() -> retval
```

### dlib::rectangle::tl\_corner

```cpp
dlib::point dlib::rectangle::tl_corner();
AutoIt:
    $orectangle.tl_corner() -> retval
```

### dlib::rectangle::top

```cpp
long dlib::rectangle::top();
AutoIt:
    $orectangle.top() -> retval
```

### dlib::rectangle::tr\_corner

```cpp
dlib::point dlib::rectangle::tr_corner();
AutoIt:
    $orectangle.tr_corner() -> retval
```

### dlib::rectangle::width

```cpp
ULONG dlib::rectangle::width();
AutoIt:
    $orectangle.width() -> retval
```

## dlib::drectangle

### dlib::drectangle::get\_create

```cpp
static dlib::drectangle dlib::drectangle::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create() -> <dlib.drectangle object>
```

```cpp
static dlib::drectangle dlib::drectangle::get_create( double& left,
                                                      double& top,
                                                      double& right,
                                                      double& bottom );
AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create( $left, $top, $right, $bottom ) -> <dlib.drectangle object>
    $odrectangle( $left, $top, $right, $bottom ) -> <dlib.drectangle object>
```

```cpp
static dlib::drectangle dlib::drectangle::get_create( dlib::drectangle& rect );
AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create( $rect ) -> <dlib.drectangle object>
    $odrectangle( $rect ) -> <dlib.drectangle object>
```

```cpp
static dlib::drectangle dlib::drectangle::get_create( dlib::rectangle& rect );
AutoIt:
    _Dlib_ObjCreate("dlib.drectangle").create( $rect ) -> <dlib.drectangle object>
    $odrectangle( $rect ) -> <dlib.drectangle object>
```

### dlib::drectangle::ToString

```cpp
std::string dlib::drectangle::ToString();
AutoIt:
    $odrectangle.ToString() -> retval
```

### dlib::drectangle::area

```cpp
double dlib::drectangle::area();
AutoIt:
    $odrectangle.area() -> retval
```

### dlib::drectangle::bl\_corner

```cpp
dlib::dpoint dlib::drectangle::bl_corner();
AutoIt:
    $odrectangle.bl_corner() -> retval
```

### dlib::drectangle::bottom

```cpp
double dlib::drectangle::bottom();
AutoIt:
    $odrectangle.bottom() -> retval
```

### dlib::drectangle::br\_corner

```cpp
dlib::dpoint dlib::drectangle::br_corner();
AutoIt:
    $odrectangle.br_corner() -> retval
```

### dlib::drectangle::center

```cpp
dlib::dpoint dlib::drectangle::center();
AutoIt:
    $odrectangle.center() -> retval
```

### dlib::drectangle::contains

```cpp
bool dlib::drectangle::contains( dlib::dpoint& point );
AutoIt:
    $odrectangle.contains( $point ) -> retval
```

```cpp
bool dlib::drectangle::contains( dlib::point& point );
AutoIt:
    $odrectangle.contains( $point ) -> retval
```

```cpp
bool dlib::drectangle::contains( long& x,
                                 long& y );
AutoIt:
    $odrectangle.contains( $x, $y ) -> retval
```

```cpp
bool dlib::drectangle::contains( dlib::drectangle& rect );
AutoIt:
    $odrectangle.contains( $rect ) -> retval
```

### dlib::drectangle::dcenter

```cpp
dlib::dpoint dlib::drectangle::dcenter();
AutoIt:
    $odrectangle.dcenter() -> retval
```

### dlib::drectangle::height

```cpp
double dlib::drectangle::height();
AutoIt:
    $odrectangle.height() -> retval
```

### dlib::drectangle::intersect

```cpp
dlib::drectangle dlib::drectangle::intersect( dlib::drectangle& rect );
AutoIt:
    $odrectangle.intersect( $rect ) -> retval
```

### dlib::drectangle::is\_empty

```cpp
bool dlib::drectangle::is_empty();
AutoIt:
    $odrectangle.is_empty() -> retval
```

### dlib::drectangle::left

```cpp
double dlib::drectangle::left();
AutoIt:
    $odrectangle.left() -> retval
```

### dlib::drectangle::right

```cpp
double dlib::drectangle::right();
AutoIt:
    $odrectangle.right() -> retval
```

### dlib::drectangle::tl\_corner

```cpp
dlib::dpoint dlib::drectangle::tl_corner();
AutoIt:
    $odrectangle.tl_corner() -> retval
```

### dlib::drectangle::top

```cpp
double dlib::drectangle::top();
AutoIt:
    $odrectangle.top() -> retval
```

### dlib::drectangle::tr\_corner

```cpp
dlib::dpoint dlib::drectangle::tr_corner();
AutoIt:
    $odrectangle.tr_corner() -> retval
```

### dlib::drectangle::width

```cpp
double dlib::drectangle::width();
AutoIt:
    $odrectangle.width() -> retval
```

## dlib::full\_object\_detection

### full\_object\_detection.rect

```cpp
dlib::rectangle dlib::full_object_detection::get_rect()
AutoIt:
    [propget] $ofull_object_detection.rect
```

### full\_object\_detection.num\_parts

```cpp
ULONG dlib::full_object_detection::num_parts()
AutoIt:
    [propget] $ofull_object_detection.num_parts
```

### dlib::full\_object\_detection::get\_create

```cpp
static dlib::full_object_detection dlib::full_object_detection::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.full_object_detection").create() -> <dlib.full_object_detection object>
```

```cpp
static dlib::full_object_detection dlib::full_object_detection::get_create( dlib::rectangle          rect,
                                                                            std::vector<dlib::point> parts );
AutoIt:
    _Dlib_ObjCreate("dlib.full_object_detection").create( $rect, $parts ) -> <dlib.full_object_detection object>
    $ofull_object_detection( $rect, $parts ) -> <dlib.full_object_detection object>
```

### dlib::full\_object\_detection::part

```cpp
dlib::point dlib::full_object_detection::part( ULONG idx );
AutoIt:
    $ofull_object_detection.part( $idx ) -> retval
```

### dlib::full\_object\_detection::parts

```cpp
std::vector<dlib::point> dlib::full_object_detection::parts();
AutoIt:
    $ofull_object_detection.parts() -> retval
```

## dlib::shape\_predictor

### dlib::shape\_predictor::create

```cpp
static dlib::shape_predictor dlib::shape_predictor::create();
AutoIt:
    _Dlib_ObjCreate("dlib.shape_predictor").create() -> <dlib.shape_predictor object>
```

```cpp
std::shared_ptr<dlib::shape_predictor> dlib::shape_predictor::create( std::string filename );
AutoIt:
    $oshape_predictor.create( $filename ) -> retval
```

### dlib::shape\_predictor::get\_call

```cpp
dlib::full_object_detection dlib::shape_predictor::get_call( cv::Mat         img,
                                                             dlib::rectangle box );
AutoIt:
    $oshape_predictor.call( $img, $box ) -> retval
    $oshape_predictor( $img, $box ) -> retval
```

### dlib::shape\_predictor::save

```cpp
void dlib::shape_predictor::save( std::string detector_output_filename );
AutoIt:
    $oshape_predictor.save( $detector_output_filename ) -> None
```

## dlib::svm\_c\_trainer\_radial\_basis

### svm\_c\_trainer\_radial\_basis.epsilon

```cpp
double dlib::svm_c_trainer_radial_basis::epsilon
AutoIt:
    [propget, propput] $osvm_c_trainer_radial_basis.epsilon
```

### svm\_c\_trainer\_radial\_basis.c\_class1

```cpp
double dlib::svm_c_trainer_radial_basis::c_class1
AutoIt:
    [propget, propput] $osvm_c_trainer_radial_basis.c_class1
```

### svm\_c\_trainer\_radial\_basis.c\_class2

```cpp
double dlib::svm_c_trainer_radial_basis::c_class2
AutoIt:
    [propget, propput] $osvm_c_trainer_radial_basis.c_class2
```

### svm\_c\_trainer\_radial\_basis.cache\_size

```cpp
long dlib::svm_c_trainer_radial_basis::cache_size
AutoIt:
    [propget, propput] $osvm_c_trainer_radial_basis.cache_size
```

### svm\_c\_trainer\_radial\_basis.gamma

```cpp
double dlib::svm_c_trainer_radial_basis::gamma
AutoIt:
    [propget, propput] $osvm_c_trainer_radial_basis.gamma
```

### dlib::svm\_c\_trainer\_radial\_basis::get\_create

```cpp
static dlib::svm_c_trainer_radial_basis dlib::svm_c_trainer_radial_basis::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_radial_basis").create() -> <dlib.svm_c_trainer_radial_basis object>
```

### dlib::svm\_c\_trainer\_radial\_basis::set\_c

```cpp
void dlib::svm_c_trainer_radial_basis::set_c( double c );
AutoIt:
    $osvm_c_trainer_radial_basis.set_c( $c ) -> None
```

### dlib::svm\_c\_trainer\_radial\_basis::train

```cpp
dlib::_decision_function_radial_basis dlib::svm_c_trainer_radial_basis::train( std::vector<dlib::SpaceVector> samples,
                                                                               std::vector<double>            labels );
AutoIt:
    $osvm_c_trainer_radial_basis.train( $samples, $labels ) -> retval
```

## dlib::svm\_c\_trainer\_sparse\_radial\_basis

### svm\_c\_trainer\_sparse\_radial\_basis.epsilon

```cpp
double dlib::svm_c_trainer_sparse_radial_basis::epsilon
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_radial_basis.epsilon
```

### svm\_c\_trainer\_sparse\_radial\_basis.c\_class1

```cpp
double dlib::svm_c_trainer_sparse_radial_basis::c_class1
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_radial_basis.c_class1
```

### svm\_c\_trainer\_sparse\_radial\_basis.c\_class2

```cpp
double dlib::svm_c_trainer_sparse_radial_basis::c_class2
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_radial_basis.c_class2
```

### svm\_c\_trainer\_sparse\_radial\_basis.cache\_size

```cpp
long dlib::svm_c_trainer_sparse_radial_basis::cache_size
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_radial_basis.cache_size
```

### svm\_c\_trainer\_sparse\_radial\_basis.gamma

```cpp
double dlib::svm_c_trainer_sparse_radial_basis::gamma
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_radial_basis.gamma
```

### dlib::svm\_c\_trainer\_sparse\_radial\_basis::get\_create

```cpp
static dlib::svm_c_trainer_sparse_radial_basis dlib::svm_c_trainer_sparse_radial_basis::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_sparse_radial_basis").create() -> <dlib.svm_c_trainer_sparse_radial_basis object>
```

### dlib::svm\_c\_trainer\_sparse\_radial\_basis::set\_c

```cpp
void dlib::svm_c_trainer_sparse_radial_basis::set_c( double c );
AutoIt:
    $osvm_c_trainer_sparse_radial_basis.set_c( $c ) -> None
```

### dlib::svm\_c\_trainer\_sparse\_radial\_basis::train

```cpp
dlib::_decision_function_sparse_radial_basis dlib::svm_c_trainer_sparse_radial_basis::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                             std::vector<double>                                labels );
AutoIt:
    $osvm_c_trainer_sparse_radial_basis.train( $samples, $labels ) -> retval
```

## dlib::svm\_c\_trainer\_histogram\_intersection

### svm\_c\_trainer\_histogram\_intersection.epsilon

```cpp
double dlib::svm_c_trainer_histogram_intersection::epsilon
AutoIt:
    [propget, propput] $osvm_c_trainer_histogram_intersection.epsilon
```

### svm\_c\_trainer\_histogram\_intersection.c\_class1

```cpp
double dlib::svm_c_trainer_histogram_intersection::c_class1
AutoIt:
    [propget, propput] $osvm_c_trainer_histogram_intersection.c_class1
```

### svm\_c\_trainer\_histogram\_intersection.c\_class2

```cpp
double dlib::svm_c_trainer_histogram_intersection::c_class2
AutoIt:
    [propget, propput] $osvm_c_trainer_histogram_intersection.c_class2
```

### svm\_c\_trainer\_histogram\_intersection.cache\_size

```cpp
long dlib::svm_c_trainer_histogram_intersection::cache_size
AutoIt:
    [propget, propput] $osvm_c_trainer_histogram_intersection.cache_size
```

### dlib::svm\_c\_trainer\_histogram\_intersection::get\_create

```cpp
static dlib::svm_c_trainer_histogram_intersection dlib::svm_c_trainer_histogram_intersection::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_histogram_intersection").create() -> <dlib.svm_c_trainer_histogram_intersection object>
```

### dlib::svm\_c\_trainer\_histogram\_intersection::set\_c

```cpp
void dlib::svm_c_trainer_histogram_intersection::set_c( double c );
AutoIt:
    $osvm_c_trainer_histogram_intersection.set_c( $c ) -> None
```

### dlib::svm\_c\_trainer\_histogram\_intersection::train

```cpp
dlib::_decision_function_histogram_intersection dlib::svm_c_trainer_histogram_intersection::train( std::vector<dlib::SpaceVector> samples,
                                                                                                   std::vector<double>            labels );
AutoIt:
    $osvm_c_trainer_histogram_intersection.train( $samples, $labels ) -> retval
```

## dlib::svm\_c\_trainer\_sparse\_histogram\_intersection

### svm\_c\_trainer\_sparse\_histogram\_intersection.epsilon

```cpp
double dlib::svm_c_trainer_sparse_histogram_intersection::epsilon
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_histogram_intersection.epsilon
```

### svm\_c\_trainer\_sparse\_histogram\_intersection.c\_class1

```cpp
double dlib::svm_c_trainer_sparse_histogram_intersection::c_class1
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_histogram_intersection.c_class1
```

### svm\_c\_trainer\_sparse\_histogram\_intersection.c\_class2

```cpp
double dlib::svm_c_trainer_sparse_histogram_intersection::c_class2
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_histogram_intersection.c_class2
```

### svm\_c\_trainer\_sparse\_histogram\_intersection.cache\_size

```cpp
long dlib::svm_c_trainer_sparse_histogram_intersection::cache_size
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_histogram_intersection.cache_size
```

### dlib::svm\_c\_trainer\_sparse\_histogram\_intersection::get\_create

```cpp
static dlib::svm_c_trainer_sparse_histogram_intersection dlib::svm_c_trainer_sparse_histogram_intersection::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_sparse_histogram_intersection").create() -> <dlib.svm_c_trainer_sparse_histogram_intersection object>
```

### dlib::svm\_c\_trainer\_sparse\_histogram\_intersection::set\_c

```cpp
void dlib::svm_c_trainer_sparse_histogram_intersection::set_c( double c );
AutoIt:
    $osvm_c_trainer_sparse_histogram_intersection.set_c( $c ) -> None
```

### dlib::svm\_c\_trainer\_sparse\_histogram\_intersection::train

```cpp
dlib::_decision_function_sparse_histogram_intersection dlib::svm_c_trainer_sparse_histogram_intersection::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                                                 std::vector<double>                                labels );
AutoIt:
    $osvm_c_trainer_sparse_histogram_intersection.train( $samples, $labels ) -> retval
```

## dlib::svm\_c\_trainer\_linear

### svm\_c\_trainer\_linear.epsilon

```cpp
double dlib::svm_c_trainer_linear::epsilon
AutoIt:
    [propget, propput] $osvm_c_trainer_linear.epsilon
```

### svm\_c\_trainer\_linear.c\_class1

```cpp
double dlib::svm_c_trainer_linear::c_class1
AutoIt:
    [propget, propput] $osvm_c_trainer_linear.c_class1
```

### svm\_c\_trainer\_linear.c\_class2

```cpp
double dlib::svm_c_trainer_linear::c_class2
AutoIt:
    [propget, propput] $osvm_c_trainer_linear.c_class2
```

### svm\_c\_trainer\_linear.max\_iterations

```cpp
ULONG dlib::svm_c_trainer_linear::max_iterations
AutoIt:
    [propget, propput] $osvm_c_trainer_linear.max_iterations
```

### svm\_c\_trainer\_linear.force\_last\_weight\_to\_1

```cpp
bool dlib::svm_c_trainer_linear::force_last_weight_to_1
AutoIt:
    [propget, propput] $osvm_c_trainer_linear.force_last_weight_to_1
```

### svm\_c\_trainer\_linear.learns\_nonnegative\_weights

```cpp
bool dlib::svm_c_trainer_linear::learns_nonnegative_weights
AutoIt:
    [propget, propput] $osvm_c_trainer_linear.learns_nonnegative_weights
```

### svm\_c\_trainer\_linear.has\_prior

```cpp
bool dlib::svm_c_trainer_linear::has_prior()
AutoIt:
    [propget] $osvm_c_trainer_linear.has_prior
```

### dlib::svm\_c\_trainer\_linear::get\_create

```cpp
static dlib::svm_c_trainer_linear dlib::svm_c_trainer_linear::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_linear").create() -> <dlib.svm_c_trainer_linear object>
```

### dlib::svm\_c\_trainer\_linear::be\_quiet

```cpp
void dlib::svm_c_trainer_linear::be_quiet();
AutoIt:
    $osvm_c_trainer_linear.be_quiet() -> None
```

### dlib::svm\_c\_trainer\_linear::be\_verbose

```cpp
void dlib::svm_c_trainer_linear::be_verbose();
AutoIt:
    $osvm_c_trainer_linear.be_verbose() -> None
```

### dlib::svm\_c\_trainer\_linear::set\_c

```cpp
void dlib::svm_c_trainer_linear::set_c( double c );
AutoIt:
    $osvm_c_trainer_linear.set_c( $c ) -> None
```

### dlib::svm\_c\_trainer\_linear::set\_prior

```cpp
void dlib::svm_c_trainer_linear::set_prior( dlib::_decision_function_linear prior_ );
AutoIt:
    $osvm_c_trainer_linear.set_prior( $prior_ ) -> None
```

### dlib::svm\_c\_trainer\_linear::train

```cpp
dlib::_decision_function_linear dlib::svm_c_trainer_linear::train( std::vector<dlib::SpaceVector> samples,
                                                                   std::vector<double>            labels );
AutoIt:
    $osvm_c_trainer_linear.train( $samples, $labels ) -> retval
```

## dlib::svm\_c\_trainer\_sparse\_linear

### svm\_c\_trainer\_sparse\_linear.epsilon

```cpp
double dlib::svm_c_trainer_sparse_linear::epsilon
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_linear.epsilon
```

### svm\_c\_trainer\_sparse\_linear.c\_class1

```cpp
double dlib::svm_c_trainer_sparse_linear::c_class1
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_linear.c_class1
```

### svm\_c\_trainer\_sparse\_linear.c\_class2

```cpp
double dlib::svm_c_trainer_sparse_linear::c_class2
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_linear.c_class2
```

### svm\_c\_trainer\_sparse\_linear.max\_iterations

```cpp
ULONG dlib::svm_c_trainer_sparse_linear::max_iterations
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_linear.max_iterations
```

### svm\_c\_trainer\_sparse\_linear.force\_last\_weight\_to\_1

```cpp
bool dlib::svm_c_trainer_sparse_linear::force_last_weight_to_1
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_linear.force_last_weight_to_1
```

### svm\_c\_trainer\_sparse\_linear.learns\_nonnegative\_weights

```cpp
bool dlib::svm_c_trainer_sparse_linear::learns_nonnegative_weights
AutoIt:
    [propget, propput] $osvm_c_trainer_sparse_linear.learns_nonnegative_weights
```

### svm\_c\_trainer\_sparse\_linear.has\_prior

```cpp
bool dlib::svm_c_trainer_sparse_linear::has_prior()
AutoIt:
    [propget] $osvm_c_trainer_sparse_linear.has_prior
```

### dlib::svm\_c\_trainer\_sparse\_linear::get\_create

```cpp
static dlib::svm_c_trainer_sparse_linear dlib::svm_c_trainer_sparse_linear::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_c_trainer_sparse_linear").create() -> <dlib.svm_c_trainer_sparse_linear object>
```

### dlib::svm\_c\_trainer\_sparse\_linear::be\_quiet

```cpp
void dlib::svm_c_trainer_sparse_linear::be_quiet();
AutoIt:
    $osvm_c_trainer_sparse_linear.be_quiet() -> None
```

### dlib::svm\_c\_trainer\_sparse\_linear::be\_verbose

```cpp
void dlib::svm_c_trainer_sparse_linear::be_verbose();
AutoIt:
    $osvm_c_trainer_sparse_linear.be_verbose() -> None
```

### dlib::svm\_c\_trainer\_sparse\_linear::set\_c

```cpp
void dlib::svm_c_trainer_sparse_linear::set_c( double c );
AutoIt:
    $osvm_c_trainer_sparse_linear.set_c( $c ) -> None
```

### dlib::svm\_c\_trainer\_sparse\_linear::set\_prior

```cpp
void dlib::svm_c_trainer_sparse_linear::set_prior( dlib::_decision_function_sparse_linear prior_ );
AutoIt:
    $osvm_c_trainer_sparse_linear.set_prior( $prior_ ) -> None
```

### dlib::svm\_c\_trainer\_sparse\_linear::train

```cpp
dlib::_decision_function_sparse_linear dlib::svm_c_trainer_sparse_linear::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                 std::vector<double>                                labels );
AutoIt:
    $osvm_c_trainer_sparse_linear.train( $samples, $labels ) -> retval
```

## dlib::rvm\_trainer\_radial\_basis

### rvm\_trainer\_radial\_basis.epsilon

```cpp
double dlib::rvm_trainer_radial_basis::epsilon
AutoIt:
    [propget, propput] $orvm_trainer_radial_basis.epsilon
```

### rvm\_trainer\_radial\_basis.gamma

```cpp
double dlib::rvm_trainer_radial_basis::gamma
AutoIt:
    [propget, propput] $orvm_trainer_radial_basis.gamma
```

### dlib::rvm\_trainer\_radial\_basis::get\_create

```cpp
static dlib::rvm_trainer_radial_basis dlib::rvm_trainer_radial_basis::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_radial_basis").create() -> <dlib.rvm_trainer_radial_basis object>
```

### dlib::rvm\_trainer\_radial\_basis::train

```cpp
dlib::_decision_function_radial_basis dlib::rvm_trainer_radial_basis::train( std::vector<dlib::SpaceVector> samples,
                                                                             std::vector<double>            labels );
AutoIt:
    $orvm_trainer_radial_basis.train( $samples, $labels ) -> retval
```

## dlib::rvm\_trainer\_sparse\_radial\_basis

### rvm\_trainer\_sparse\_radial\_basis.epsilon

```cpp
double dlib::rvm_trainer_sparse_radial_basis::epsilon
AutoIt:
    [propget, propput] $orvm_trainer_sparse_radial_basis.epsilon
```

### rvm\_trainer\_sparse\_radial\_basis.gamma

```cpp
double dlib::rvm_trainer_sparse_radial_basis::gamma
AutoIt:
    [propget, propput] $orvm_trainer_sparse_radial_basis.gamma
```

### dlib::rvm\_trainer\_sparse\_radial\_basis::get\_create

```cpp
static dlib::rvm_trainer_sparse_radial_basis dlib::rvm_trainer_sparse_radial_basis::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_sparse_radial_basis").create() -> <dlib.rvm_trainer_sparse_radial_basis object>
```

### dlib::rvm\_trainer\_sparse\_radial\_basis::train

```cpp
dlib::_decision_function_sparse_radial_basis dlib::rvm_trainer_sparse_radial_basis::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                           std::vector<double>                                labels );
AutoIt:
    $orvm_trainer_sparse_radial_basis.train( $samples, $labels ) -> retval
```

## dlib::rvm\_trainer\_histogram\_intersection

### rvm\_trainer\_histogram\_intersection.epsilon

```cpp
double dlib::rvm_trainer_histogram_intersection::epsilon
AutoIt:
    [propget, propput] $orvm_trainer_histogram_intersection.epsilon
```

### dlib::rvm\_trainer\_histogram\_intersection::get\_create

```cpp
static dlib::rvm_trainer_histogram_intersection dlib::rvm_trainer_histogram_intersection::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_histogram_intersection").create() -> <dlib.rvm_trainer_histogram_intersection object>
```

### dlib::rvm\_trainer\_histogram\_intersection::train

```cpp
dlib::_decision_function_histogram_intersection dlib::rvm_trainer_histogram_intersection::train( std::vector<dlib::SpaceVector> samples,
                                                                                                 std::vector<double>            labels );
AutoIt:
    $orvm_trainer_histogram_intersection.train( $samples, $labels ) -> retval
```

## dlib::rvm\_trainer\_sparse\_histogram\_intersection

### rvm\_trainer\_sparse\_histogram\_intersection.epsilon

```cpp
double dlib::rvm_trainer_sparse_histogram_intersection::epsilon
AutoIt:
    [propget, propput] $orvm_trainer_sparse_histogram_intersection.epsilon
```

### dlib::rvm\_trainer\_sparse\_histogram\_intersection::get\_create

```cpp
static dlib::rvm_trainer_sparse_histogram_intersection dlib::rvm_trainer_sparse_histogram_intersection::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_sparse_histogram_intersection").create() -> <dlib.rvm_trainer_sparse_histogram_intersection object>
```

### dlib::rvm\_trainer\_sparse\_histogram\_intersection::train

```cpp
dlib::_decision_function_sparse_histogram_intersection dlib::rvm_trainer_sparse_histogram_intersection::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                                                               std::vector<double>                                labels );
AutoIt:
    $orvm_trainer_sparse_histogram_intersection.train( $samples, $labels ) -> retval
```

## dlib::rvm\_trainer\_linear

### rvm\_trainer\_linear.epsilon

```cpp
double dlib::rvm_trainer_linear::epsilon
AutoIt:
    [propget, propput] $orvm_trainer_linear.epsilon
```

### dlib::rvm\_trainer\_linear::get\_create

```cpp
static dlib::rvm_trainer_linear dlib::rvm_trainer_linear::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_linear").create() -> <dlib.rvm_trainer_linear object>
```

### dlib::rvm\_trainer\_linear::train

```cpp
dlib::_decision_function_linear dlib::rvm_trainer_linear::train( std::vector<dlib::SpaceVector> samples,
                                                                 std::vector<double>            labels );
AutoIt:
    $orvm_trainer_linear.train( $samples, $labels ) -> retval
```

## dlib::rvm\_trainer\_sparse\_linear

### rvm\_trainer\_sparse\_linear.epsilon

```cpp
double dlib::rvm_trainer_sparse_linear::epsilon
AutoIt:
    [propget, propput] $orvm_trainer_sparse_linear.epsilon
```

### dlib::rvm\_trainer\_sparse\_linear::get\_create

```cpp
static dlib::rvm_trainer_sparse_linear dlib::rvm_trainer_sparse_linear::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.rvm_trainer_sparse_linear").create() -> <dlib.rvm_trainer_sparse_linear object>
```

### dlib::rvm\_trainer\_sparse\_linear::train

```cpp
dlib::_decision_function_sparse_linear dlib::rvm_trainer_sparse_linear::train( std::vector<std::vector<std::pair<ULONG, double>>> samples,
                                                                               std::vector<double>                                labels );
AutoIt:
    $orvm_trainer_sparse_linear.train( $samples, $labels ) -> retval
```

## dlib::vec\_ranking\_pair

### vec\_ranking\_pair.relevant

```cpp
std::vector<dlib::SpaceVector> dlib::vec_ranking_pair::relevant
AutoIt:
    [propget, propput] $ovec_ranking_pair.relevant
```

### vec\_ranking\_pair.nonrelevant

```cpp
std::vector<dlib::SpaceVector> dlib::vec_ranking_pair::nonrelevant
AutoIt:
    [propget, propput] $ovec_ranking_pair.nonrelevant
```

### dlib::vec\_ranking\_pair::get\_create

```cpp
static dlib::vec_ranking_pair dlib::vec_ranking_pair::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.ranking_pair").create() -> <dlib.vec_ranking_pair object>
```

```cpp
static dlib::vec_ranking_pair dlib::vec_ranking_pair::get_create( std::vector<dlib::SpaceVector> relevant,
                                                                  std::vector<dlib::SpaceVector> nonrelevant );
AutoIt:
    _Dlib_ObjCreate("dlib.ranking_pair").create( $relevant, $nonrelevant ) -> <dlib.vec_ranking_pair object>
    $ovec_ranking_pair( $relevant, $nonrelevant ) -> <dlib.vec_ranking_pair object>
```

## dlib::sparse\_ranking\_pair

### sparse\_ranking\_pair.relevant

```cpp
std::vector<std::vector<std::pair<ULONG, double>>> dlib::sparse_ranking_pair::relevant
AutoIt:
    [propget, propput] $osparse_ranking_pair.relevant
```

### sparse\_ranking\_pair.nonrelevant

```cpp
std::vector<std::vector<std::pair<ULONG, double>>> dlib::sparse_ranking_pair::nonrelevant
AutoIt:
    [propget, propput] $osparse_ranking_pair.nonrelevant
```

### dlib::sparse\_ranking\_pair::get\_create

```cpp
static dlib::sparse_ranking_pair dlib::sparse_ranking_pair::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.sparse_ranking_pair").create() -> <dlib.sparse_ranking_pair object>
```

```cpp
static dlib::sparse_ranking_pair dlib::sparse_ranking_pair::get_create( std::vector<std::vector<std::pair<ULONG, double>>> relevant,
                                                                        std::vector<std::vector<std::pair<ULONG, double>>> nonrelevant );
AutoIt:
    _Dlib_ObjCreate("dlib.sparse_ranking_pair").create( $relevant, $nonrelevant ) -> <dlib.sparse_ranking_pair object>
    $osparse_ranking_pair( $relevant, $nonrelevant ) -> <dlib.sparse_ranking_pair object>
```

## dlib::vec\_svm\_rank\_trainer

### vec\_svm\_rank\_trainer.epsilon

```cpp
double dlib::vec_svm_rank_trainer::epsilon
AutoIt:
    [propget, propput] $ovec_svm_rank_trainer.epsilon
```

### vec\_svm\_rank\_trainer.c

```cpp
double dlib::vec_svm_rank_trainer::c
AutoIt:
    [propget, propput] $ovec_svm_rank_trainer.c
```

### vec\_svm\_rank\_trainer.max\_iterations

```cpp
ULONG dlib::vec_svm_rank_trainer::max_iterations
AutoIt:
    [propget, propput] $ovec_svm_rank_trainer.max_iterations
```

### vec\_svm\_rank\_trainer.force\_last\_weight\_to\_1

```cpp
bool dlib::vec_svm_rank_trainer::force_last_weight_to_1
AutoIt:
    [propget, propput] $ovec_svm_rank_trainer.force_last_weight_to_1
```

### vec\_svm\_rank\_trainer.learns\_nonnegative\_weights

```cpp
bool dlib::vec_svm_rank_trainer::learns_nonnegative_weights
AutoIt:
    [propget, propput] $ovec_svm_rank_trainer.learns_nonnegative_weights
```

### vec\_svm\_rank\_trainer.has\_prior

```cpp
bool dlib::vec_svm_rank_trainer::has_prior()
AutoIt:
    [propget] $ovec_svm_rank_trainer.has_prior
```

### dlib::vec\_svm\_rank\_trainer::get\_create

```cpp
static dlib::vec_svm_rank_trainer dlib::vec_svm_rank_trainer::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_rank_trainer").create() -> <dlib.vec_svm_rank_trainer object>
```

### dlib::vec\_svm\_rank\_trainer::be\_quiet

```cpp
void dlib::vec_svm_rank_trainer::be_quiet();
AutoIt:
    $ovec_svm_rank_trainer.be_quiet() -> None
```

### dlib::vec\_svm\_rank\_trainer::be\_verbose

```cpp
void dlib::vec_svm_rank_trainer::be_verbose();
AutoIt:
    $ovec_svm_rank_trainer.be_verbose() -> None
```

### dlib::vec\_svm\_rank\_trainer::set\_prior

```cpp
void dlib::vec_svm_rank_trainer::set_prior( dlib::_decision_function_linear prior_ );
AutoIt:
    $ovec_svm_rank_trainer.set_prior( $prior_ ) -> None
```

### dlib::vec\_svm\_rank\_trainer::train

```cpp
dlib::_decision_function_linear dlib::vec_svm_rank_trainer::train( dlib::vec_ranking_pair sample );
AutoIt:
    $ovec_svm_rank_trainer.train( $sample ) -> retval
```

```cpp
dlib::_decision_function_linear dlib::vec_svm_rank_trainer::train( std::vector<dlib::vec_ranking_pair> samples );
AutoIt:
    $ovec_svm_rank_trainer.train( $samples ) -> retval
```

## dlib::svm\_rank\_trainer\_sparse

### svm\_rank\_trainer\_sparse.epsilon

```cpp
double dlib::svm_rank_trainer_sparse::epsilon
AutoIt:
    [propget, propput] $osvm_rank_trainer_sparse.epsilon
```

### svm\_rank\_trainer\_sparse.c

```cpp
double dlib::svm_rank_trainer_sparse::c
AutoIt:
    [propget, propput] $osvm_rank_trainer_sparse.c
```

### svm\_rank\_trainer\_sparse.max\_iterations

```cpp
ULONG dlib::svm_rank_trainer_sparse::max_iterations
AutoIt:
    [propget, propput] $osvm_rank_trainer_sparse.max_iterations
```

### svm\_rank\_trainer\_sparse.force\_last\_weight\_to\_1

```cpp
bool dlib::svm_rank_trainer_sparse::force_last_weight_to_1
AutoIt:
    [propget, propput] $osvm_rank_trainer_sparse.force_last_weight_to_1
```

### svm\_rank\_trainer\_sparse.learns\_nonnegative\_weights

```cpp
bool dlib::svm_rank_trainer_sparse::learns_nonnegative_weights
AutoIt:
    [propget, propput] $osvm_rank_trainer_sparse.learns_nonnegative_weights
```

### svm\_rank\_trainer\_sparse.has\_prior

```cpp
bool dlib::svm_rank_trainer_sparse::has_prior()
AutoIt:
    [propget] $osvm_rank_trainer_sparse.has_prior
```

### dlib::svm\_rank\_trainer\_sparse::get\_create

```cpp
static dlib::svm_rank_trainer_sparse dlib::svm_rank_trainer_sparse::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.svm_rank_trainer_sparse").create() -> <dlib.svm_rank_trainer_sparse object>
```

### dlib::svm\_rank\_trainer\_sparse::be\_quiet

```cpp
void dlib::svm_rank_trainer_sparse::be_quiet();
AutoIt:
    $osvm_rank_trainer_sparse.be_quiet() -> None
```

### dlib::svm\_rank\_trainer\_sparse::be\_verbose

```cpp
void dlib::svm_rank_trainer_sparse::be_verbose();
AutoIt:
    $osvm_rank_trainer_sparse.be_verbose() -> None
```

### dlib::svm\_rank\_trainer\_sparse::set\_prior

```cpp
void dlib::svm_rank_trainer_sparse::set_prior( dlib::_decision_function_sparse_linear prior_ );
AutoIt:
    $osvm_rank_trainer_sparse.set_prior( $prior_ ) -> None
```

### dlib::svm\_rank\_trainer\_sparse::train

```cpp
dlib::_decision_function_sparse_linear dlib::svm_rank_trainer_sparse::train( dlib::sparse_ranking_pair sample );
AutoIt:
    $osvm_rank_trainer_sparse.train( $sample ) -> retval
```

```cpp
dlib::_decision_function_sparse_linear dlib::svm_rank_trainer_sparse::train( std::vector<dlib::sparse_ranking_pair> samples );
AutoIt:
    $osvm_rank_trainer_sparse.train( $samples ) -> retval
```

## cv::UMat

### UMat.cols

```cpp
int cv::UMat::cols
AutoIt:
    [propget, propput] $oUMat.cols
```

### UMat.dims

```cpp
int cv::UMat::dims
AutoIt:
    [propget, propput] $oUMat.dims
```

### UMat.flags

```cpp
int cv::UMat::flags
AutoIt:
    [propget, propput] $oUMat.flags
```

### UMat.rows

```cpp
int cv::UMat::rows
AutoIt:
    [propget, propput] $oUMat.rows
```

### UMat.step

```cpp
size_t cv::UMat::step
AutoIt:
    [propget, propput] $oUMat.step
```

### UMat.width

```cpp
int cv::UMat::cols
AutoIt:
    [propget, propput] $oUMat.width
```

### UMat.height

```cpp
int cv::UMat::rows
AutoIt:
    [propget, propput] $oUMat.height
```

### UMat.shape

```cpp
std::tuple<int, int, int> cv::UMat::shape
AutoIt:
    [propget] $oUMat.shape
```

### UMat.sizes

```cpp
std::vector<int> cv::UMat::sizes
AutoIt:
    [propget] $oUMat.sizes
```

### UMat.steps

```cpp
std::vector<size_t> cv::UMat::steps
AutoIt:
    [propget] $oUMat.steps
```

### cv::UMat::get\_create

```cpp
static cv::UMat cv::UMat::get_create( cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( [$usageFlags] ) -> <cv.UMat object>
    $oUMat( [$usageFlags] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( int                rows,
                                      int                cols,
                                      int                type,
                                      cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $rows, $cols, $type[, $usageFlags] ) -> <cv.UMat object>
    $oUMat( $rows, $cols, $type[, $usageFlags] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( cv::Size           size,
                                      int                type,
                                      cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $size, $type[, $usageFlags] ) -> <cv.UMat object>
    $oUMat( $size, $type[, $usageFlags] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( int                rows,
                                      int                cols,
                                      int                type,
                                      const cv::Scalar&  s,
                                      cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $rows, $cols, $type, $s[, $usageFlags] ) -> <cv.UMat object>
    $oUMat( $rows, $cols, $type, $s[, $usageFlags] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( cv::Size           size,
                                      int                type,
                                      const cv::Scalar&  s,
                                      cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $size, $type, $s[, $usageFlags] ) -> <cv.UMat object>
    $oUMat( $size, $type, $s[, $usageFlags] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( std::vector<int>   sizes,
                                      int                type,
                                      cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $sizes, $type[, $usageFlags] ) -> <cv.UMat object>
    $oUMat( $sizes, $type[, $usageFlags] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( std::vector<int>   sizes,
                                      int                type,
                                      const cv::Scalar&  s,
                                      cv::UMatUsageFlags usageFlags = USAGE_DEFAULT );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $sizes, $type, $s[, $usageFlags] ) -> <cv.UMat object>
    $oUMat( $sizes, $type, $s[, $usageFlags] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( const cv::UMat& m );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $m ) -> <cv.UMat object>
    $oUMat( $m ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( const cv::UMat&  m,
                                      const cv::Range& rowRange,
                                      const cv::Range& colRange = Range::all() );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $m, $rowRange[, $colRange] ) -> <cv.UMat object>
    $oUMat( $m, $rowRange[, $colRange] ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( const cv::UMat& m,
                                      const cv::Rect& roi );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $m, $roi ) -> <cv.UMat object>
    $oUMat( $m, $roi ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( const cv::UMat&               m,
                                      const std::vector<cv::Range>& ranges );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $m, $ranges ) -> <cv.UMat object>
    $oUMat( $m, $ranges ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( const std::vector<double>& vec );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $vec ) -> <cv.UMat object>
    $oUMat( $vec ) -> <cv.UMat object>
```

```cpp
static cv::UMat cv::UMat::get_create( const std::vector<int>& vec );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").create( $vec ) -> <cv.UMat object>
    $oUMat( $vec ) -> <cv.UMat object>
```

### cv::UMat::GdiplusResize

```cpp
void cv::UMat::GdiplusResize( cv::Mat dst,
                              float   newWidth,
                              float   newHeight,
                              int     interpolation = 7 );
AutoIt:
    $oUMat.GdiplusResize( $newWidth, $newHeight[, $interpolation[, $dst]] ) -> $dst
```

### cv::UMat::adjustROI

```cpp
std::shared_ptr<cv::UMat> cv::UMat::adjustROI( int dtop,
                                               int dbottom,
                                               int dleft,
                                               int dright );
AutoIt:
    $oUMat.adjustROI( $dtop, $dbottom, $dleft, $dright ) -> retval
```

### cv::UMat::assignTo

```cpp
void cv::UMat::assignTo( const cv::UMat& m,
                         int             type = -1 );
AutoIt:
    $oUMat.assignTo( $m[, $type] ) -> None
```

### cv::UMat::channels

```cpp
int cv::UMat::channels();
AutoIt:
    $oUMat.channels() -> retval
```

### cv::UMat::checkVector

```cpp
int cv::UMat::checkVector( int elemChannels,
                           int depth = -1,
                           int requireContinuous = true );
AutoIt:
    $oUMat.checkVector( $elemChannels[, $depth[, $requireContinuous]] ) -> retval
```

### cv::UMat::clone

```cpp
cv::UMat cv::UMat::clone();
AutoIt:
    $oUMat.clone() -> retval
```

### cv::UMat::col

```cpp
cv::UMat cv::UMat::col( int x );
AutoIt:
    $oUMat.col( $x ) -> retval
```

### cv::UMat::colRange

```cpp
cv::UMat cv::UMat::colRange( int startcol,
                             int endcol = __self->get()->cols );
AutoIt:
    $oUMat.colRange( $startcol[, $endcol] ) -> retval
```

```cpp
cv::UMat cv::UMat::colRange( const cv::Range& r );
AutoIt:
    $oUMat.colRange( $r ) -> retval
```

### cv::UMat::convertTo

```cpp
void cv::UMat::convertTo( OutputArray m,
                          int         rtype,
                          double      alpha = 1.0,
                          double      beta = 0.0 );
AutoIt:
    $oUMat.convertTo( $rtype[, $m[, $alpha[, $beta]]] ) -> $m
```

```cpp
void cv::UMat::convertTo( OutputArray m,
                          int         rtype = -1,
                          double      alpha = 1.0,
                          double      beta = 0.0 );
AutoIt:
    $oUMat.convertTo( [$m[, $rtype[, $alpha[, $beta]]]] ) -> $m
```

### cv::UMat::convertToBitmap

```cpp
void* cv::UMat::convertToBitmap( bool copy = true );
AutoIt:
    $oUMat.convertToBitmap( [$copy] ) -> retval
```

### cv::UMat::convertToShow

```cpp
void cv::UMat::convertToShow( cv::Mat dst = Mat::zeros(__self->get()->rows, __self->get()->cols, CV_8UC3),
                              bool    toRGB = false );
AutoIt:
    $oUMat.convertToShow( [$dst[, $toRGB]] ) -> $dst
```

### cv::UMat::copy

```cpp
cv::UMat cv::UMat::copy();
AutoIt:
    $oUMat.copy() -> retval
```

### cv::UMat::copySize

```cpp
void cv::UMat::copySize( const cv::UMat& m );
AutoIt:
    $oUMat.copySize( $m ) -> None
```

### cv::UMat::copyTo

```cpp
void cv::UMat::copyTo( OutputArray m );
AutoIt:
    $oUMat.copyTo( [$m] ) -> $m
```

```cpp
void cv::UMat::copyTo( OutputArray m,
                       InputArray  mask );
AutoIt:
    $oUMat.copyTo( $mask[, $m] ) -> $m
```

### cv::UMat::depth

```cpp
int cv::UMat::depth();
AutoIt:
    $oUMat.depth() -> retval
```

### cv::UMat::diag

```cpp
cv::UMat cv::UMat::diag( int d = 0 );
AutoIt:
    $oUMat.diag( [$d] ) -> retval
```

```cpp
static cv::UMat cv::UMat::diag( const cv::UMat&    d,
                                cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").diag( $d, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::diag( const cv::UMat& d );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").diag( $d ) -> retval
```

### cv::UMat::dot

```cpp
double cv::UMat::dot( InputArray m );
AutoIt:
    $oUMat.dot( $m ) -> retval
```

### cv::UMat::elemSize

```cpp
size_t cv::UMat::elemSize();
AutoIt:
    $oUMat.elemSize() -> retval
```

### cv::UMat::elemSize1

```cpp
size_t cv::UMat::elemSize1();
AutoIt:
    $oUMat.elemSize1() -> retval
```

### cv::UMat::empty

```cpp
bool cv::UMat::empty();
AutoIt:
    $oUMat.empty() -> retval
```

### cv::UMat::eye

```cpp
static cv::UMat cv::UMat::eye( int rows,
                               int cols,
                               int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $rows, $cols, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::eye( int rows,
                               int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $rows, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::eye( int cols,
                               int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $cols, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::eye( cv::Size size,
                               int      type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $size, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::eye( int                rows,
                               int                cols,
                               int                type,
                               cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $rows, $cols, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::eye( int                rows,
                               int                type,
                               cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $rows, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::eye( int                cols,
                               int                type,
                               cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $cols, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::eye( cv::Size           size,
                               int                type,
                               cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").eye( $size, $type, $usageFlags ) -> retval
```

### cv::UMat::getMat

```cpp
cv::Mat cv::UMat::getMat( cv::AccessFlag flags );
AutoIt:
    $oUMat.getMat( $flags ) -> retval
```

### cv::UMat::handle

```cpp
void* cv::UMat::handle( cv::AccessFlag acessFlag );
AutoIt:
    $oUMat.handle( $acessFlag ) -> retval
```

### cv::UMat::isContinuous

```cpp
bool cv::UMat::isContinuous();
AutoIt:
    $oUMat.isContinuous() -> retval
```

### cv::UMat::isSubmatrix

```cpp
bool cv::UMat::isSubmatrix();
AutoIt:
    $oUMat.isSubmatrix() -> retval
```

### cv::UMat::locateROI

```cpp
void cv::UMat::locateROI( cv::Size&  wholeSize,
                          cv::Point& ofs );
AutoIt:
    $oUMat.locateROI( [$wholeSize[, $ofs]] ) -> $wholeSize, $ofs
```

### cv::UMat::makeeInputArray

```cpp
std::shared_ptr<cv::_InputArray> cv::UMat::makeeInputArray();
AutoIt:
    $oUMat.makeeInputArray() -> retval
```

### cv::UMat::makeeInputOutputArray

```cpp
std::shared_ptr<cv::_InputOutputArray> cv::UMat::makeeInputOutputArray();
AutoIt:
    $oUMat.makeeInputOutputArray() -> retval
```

### cv::UMat::makeeOutputArray

```cpp
std::shared_ptr<cv::_OutputArray> cv::UMat::makeeOutputArray();
AutoIt:
    $oUMat.makeeOutputArray() -> retval
```

### cv::UMat::mul

```cpp
cv::UMat cv::UMat::mul( InputArray m,
                        double     scale = 1 );
AutoIt:
    $oUMat.mul( $m[, $scale] ) -> retval
```

### cv::UMat::ndoffset

```cpp
void cv::UMat::ndoffset( size_t* ofs );
AutoIt:
    $oUMat.ndoffset( [$ofs] ) -> $ofs
```

### cv::UMat::ones

```cpp
static cv::UMat cv::UMat::ones( int rows,
                                int cols,
                                int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $rows, $cols, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( int cols,
                                int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $cols, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( int rows,
                                int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $rows, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( cv::Size size,
                                int      type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $size, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( std::vector<int> sizes,
                                int              type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $sizes, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( int                rows,
                                int                cols,
                                int                type,
                                cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $rows, $cols, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( int                cols,
                                int                type,
                                cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $cols, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( int                rows,
                                int                type,
                                cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $rows, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( cv::Size           size,
                                int                type,
                                cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $size, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::ones( std::vector<int>   sizes,
                                int                type,
                                cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").ones( $sizes, $type, $usageFlags ) -> retval
```

### cv::UMat::reshape

```cpp
cv::UMat cv::UMat::reshape( int cn,
                            int rows = 0 );
AutoIt:
    $oUMat.reshape( $cn[, $rows] ) -> retval
```

```cpp
cv::UMat cv::UMat::reshape( int                     cn,
                            const std::vector<int>& newshape );
AutoIt:
    $oUMat.reshape( $cn, $newshape ) -> retval
```

### cv::UMat::row

```cpp
cv::UMat cv::UMat::row( int y );
AutoIt:
    $oUMat.row( $y ) -> retval
```

### cv::UMat::rowRange

```cpp
cv::UMat cv::UMat::rowRange( int startrow,
                             int endrow = __self->get()->rows );
AutoIt:
    $oUMat.rowRange( $startrow[, $endrow] ) -> retval
```

```cpp
cv::UMat cv::UMat::rowRange( cv::Range r );
AutoIt:
    $oUMat.rowRange( $r ) -> retval
```

### cv::UMat::setTo

```cpp
void cv::UMat::setTo( InputArray value,
                      InputArray mask = noArray() );
AutoIt:
    $oUMat.setTo( $value[, $mask] ) -> None
```

### cv::UMat::size

```cpp
cv::Size cv::UMat::size();
AutoIt:
    $oUMat.size() -> retval
```

### cv::UMat::step1

```cpp
size_t cv::UMat::step1( int i = 0 );
AutoIt:
    $oUMat.step1( [$i] ) -> retval
```

### cv::UMat::t

```cpp
cv::UMat cv::UMat::t();
AutoIt:
    $oUMat.t() -> retval
```

### cv::UMat::total

```cpp
size_t cv::UMat::total();
AutoIt:
    $oUMat.total() -> retval
```

### cv::UMat::type

```cpp
int cv::UMat::type();
AutoIt:
    $oUMat.type() -> retval
```

### cv::UMat::updateContinuityFlag

```cpp
void cv::UMat::updateContinuityFlag();
AutoIt:
    $oUMat.updateContinuityFlag() -> None
```

### cv::UMat::zeros

```cpp
static cv::UMat cv::UMat::zeros( int rows,
                                 int cols,
                                 int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $rows, $cols, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( int cols,
                                 int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $cols, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( int rows,
                                 int type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $rows, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( cv::Size size,
                                 int      type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $size, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( std::vector<int> sizes,
                                 int              type );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $sizes, $type ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( int                rows,
                                 int                cols,
                                 int                type,
                                 cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $rows, $cols, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( int                cols,
                                 int                type,
                                 cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $cols, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( int                rows,
                                 int                type,
                                 cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $rows, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( cv::Size           size,
                                 int                type,
                                 cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $size, $type, $usageFlags ) -> retval
```

```cpp
static cv::UMat cv::UMat::zeros( std::vector<int>   sizes,
                                 int                type,
                                 cv::UMatUsageFlags usageFlags );
AutoIt:
    _Dlib_ObjCreate("cv.UMat").zeros( $sizes, $type, $usageFlags ) -> retval
```

## dlib::SpaceVector

### SpaceVector.shape

```cpp
std::tuple<long, long> dlib::SpaceVector::shape
AutoIt:
    [propget] $oSpaceVector.shape
```

### dlib::SpaceVector::create

```cpp
static dlib::SpaceVector dlib::SpaceVector::create();
AutoIt:
    _Dlib_ObjCreate("dlib.vector").create() -> <dlib.SpaceVector object>
```

```cpp
static std::shared_ptr<dlib::SpaceVector> dlib::SpaceVector::create( std::vector<double> list );
AutoIt:
    _Dlib_ObjCreate("dlib.vector").create( $list ) -> retval
```

```cpp
static std::shared_ptr<dlib::SpaceVector> dlib::SpaceVector::create( long rows );
AutoIt:
    _Dlib_ObjCreate("dlib.vector").create( $rows ) -> retval
```

### dlib::SpaceVector::ToString

```cpp
std::string dlib::SpaceVector::ToString();
AutoIt:
    $oSpaceVector.ToString() -> retval
```

### dlib::SpaceVector::get

```cpp
double dlib::SpaceVector::get( long row );
AutoIt:
    $oSpaceVector.get( $row ) -> retval
```

### dlib::SpaceVector::get\_Item

```cpp
double dlib::SpaceVector::get_Item( long row );
AutoIt:
    $oSpaceVector.Item( $row ) -> retval
    $oSpaceVector( $row ) -> retval
```

### dlib::SpaceVector::put\_Item

```cpp
void dlib::SpaceVector::put_Item( long   row,
                                  double val );
AutoIt:
    $oSpaceVector.Item( $row ) = $val
```

### dlib::SpaceVector::resize

```cpp
void dlib::SpaceVector::resize( long rows );
AutoIt:
    $oSpaceVector.resize( $rows ) -> None
```

### dlib::SpaceVector::set

```cpp
void dlib::SpaceVector::set( long   row,
                             double val );
AutoIt:
    $oSpaceVector.set( $row, $val ) -> None
```

### dlib::SpaceVector::set\_size

```cpp
void dlib::SpaceVector::set_size( long rows );
AutoIt:
    $oSpaceVector.set_size( $rows ) -> None
```

### dlib::SpaceVector::size

```cpp
long dlib::SpaceVector::size();
AutoIt:
    $oSpaceVector.size() -> retval
```

### dlib::SpaceVector::slice

```cpp
dlib::SpaceVector dlib::SpaceVector::slice( long start,
                                            long stop = __self->get()->size(),
                                            long step = 1 );
AutoIt:
    $oSpaceVector.slice( $start[, $stop[, $step]] ) -> retval
```

## dlib::point\_transform\_projective

### point\_transform\_projective.m

```cpp
dlib::Matrix dlib::point_transform_projective::get_m()
AutoIt:
    [propget] $opoint_transform_projective.m
```

### dlib::point\_transform\_projective::get\_create

```cpp
static dlib::point_transform_projective dlib::point_transform_projective::get_create();
AutoIt:
    _Dlib_ObjCreate("dlib.point_transform_projective").create() -> <dlib.point_transform_projective object>
```

```cpp
std::shared_ptr<dlib::point_transform_projective> dlib::point_transform_projective::get_create( dlib::Matrix m );
AutoIt:
    $opoint_transform_projective.create( $m ) -> retval
    $opoint_transform_projective( $m ) -> retval
```

```cpp
std::shared_ptr<dlib::point_transform_projective> dlib::point_transform_projective::get_create( cv::Mat m );
AutoIt:
    $opoint_transform_projective.create( $m ) -> retval
    $opoint_transform_projective( $m ) -> retval
```

## dlib::dpoint

### dpoint.x

```cpp
double dlib::dpoint::x()
AutoIt:
    [propget, propput] $odpoint.x
```

### dpoint.y

```cpp
double dlib::dpoint::y()
AutoIt:
    [propget, propput] $odpoint.y
```

### dlib::dpoint::get\_create

```cpp
static dlib::dpoint dlib::dpoint::get_create( double& x = 0,
                                              double& y = 0 );
AutoIt:
    _Dlib_ObjCreate("dlib.dpoint").create( [$x[, $y]] ) -> <dlib.dpoint object>
    $odpoint( [$x[, $y]] ) -> <dlib.dpoint object>
```

```cpp
static dlib::dpoint dlib::dpoint::get_create( dlib::point& p );
AutoIt:
    _Dlib_ObjCreate("dlib.dpoint").create( $p ) -> <dlib.dpoint object>
    $odpoint( $p ) -> <dlib.dpoint object>
```

### dlib::dpoint::ToString

```cpp
std::string dlib::dpoint::ToString();
AutoIt:
    $odpoint.ToString() -> retval
```

### dlib::dpoint::add

```cpp
dlib::dpoint dlib::dpoint::add( dlib::dpoint& other );
AutoIt:
    $odpoint.add( $other ) -> retval
```

### dlib::dpoint::divide

```cpp
dlib::dpoint dlib::dpoint::divide( double& scalar );
AutoIt:
    $odpoint.divide( $scalar ) -> retval
```

### dlib::dpoint::multiply

```cpp
dlib::dpoint dlib::dpoint::multiply( double& scalar );
AutoIt:
    $odpoint.multiply( $scalar ) -> retval
```

### dlib::dpoint::normalize

```cpp
dlib::dpoint dlib::dpoint::normalize();
AutoIt:
    $odpoint.normalize() -> retval
```

### dlib::dpoint::sub

```cpp
dlib::dpoint dlib::dpoint::sub( dlib::dpoint& other );
AutoIt:
    $odpoint.sub( $other ) -> retval
```

## dlib::point

### point.x

```cpp
long dlib::point::x()
AutoIt:
    [propget, propput] $opoint.x
```

### point.y

```cpp
long dlib::point::y()
AutoIt:
    [propget, propput] $opoint.y
```

### dlib::point::get\_create

```cpp
static dlib::point dlib::point::get_create( long& x = 0,
                                            long& y = 0 );
AutoIt:
    _Dlib_ObjCreate("dlib.point").create( [$x[, $y]] ) -> <dlib.point object>
    $opoint( [$x[, $y]] ) -> <dlib.point object>
```

```cpp
static dlib::point dlib::point::get_create( dlib::dpoint& p );
AutoIt:
    _Dlib_ObjCreate("dlib.point").create( $p ) -> <dlib.point object>
    $opoint( $p ) -> <dlib.point object>
```

### dlib::point::ToString

```cpp
std::string dlib::point::ToString();
AutoIt:
    $opoint.ToString() -> retval
```

### dlib::point::add

```cpp
dlib::point dlib::point::add( dlib::point& other );
AutoIt:
    $opoint.add( $other ) -> retval
```

### dlib::point::divide

```cpp
dlib::point dlib::point::divide( double& scalar );
AutoIt:
    $opoint.divide( $scalar ) -> retval
```

### dlib::point::multiply

```cpp
dlib::point dlib::point::multiply( double& scalar );
AutoIt:
    $opoint.multiply( $scalar ) -> retval
```

### dlib::point::normalize

```cpp
dlib::point dlib::point::normalize();
AutoIt:
    $opoint.normalize() -> retval
```

### dlib::point::sub

```cpp
dlib::point dlib::point::sub( dlib::point& other );
AutoIt:
    $opoint.sub( $other ) -> retval
```

## VectorOfString

### VectorOfString.Count

```cpp
size_t VectorOfString::size()
AutoIt:
    [propget] $oVectorOfString.Count
```

### VectorOfString::create

```cpp
static VectorOfString VectorOfString::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfString").create() -> <VectorOfString object>
```

```cpp
static VectorOfString VectorOfString::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfString").create( $size ) -> <VectorOfString object>
```

```cpp
static VectorOfString VectorOfString::create( VectorOfString other );
AutoIt:
    _Dlib_ObjCreate("VectorOfString").create( $other ) -> <VectorOfString object>
```

### VectorOfString::Add

```cpp
void VectorOfString::Add( std::string value );
AutoIt:
    $oVectorOfString.Add( $value ) -> None
```

### VectorOfString::Items

```cpp
VectorOfString VectorOfString::Items();
AutoIt:
    $oVectorOfString.Items() -> retval
```

### VectorOfString::Keys

```cpp
std::vector<int> VectorOfString::Keys();
AutoIt:
    $oVectorOfString.Keys() -> retval
```

### VectorOfString::Remove

```cpp
void VectorOfString::Remove( size_t index );
AutoIt:
    $oVectorOfString.Remove( $index ) -> None
```

### VectorOfString::append

```cpp
void VectorOfString::append( std::string value );
AutoIt:
    $oVectorOfString.append( $value ) -> None
```

### VectorOfString::at

```cpp
std::string VectorOfString::at( size_t index );
AutoIt:
    $oVectorOfString.at( $index ) -> retval
```

```cpp
void VectorOfString::at( size_t      index,
                         std::string value );
AutoIt:
    $oVectorOfString.at( $index, $value ) -> None
```

### VectorOfString::clear

```cpp
void VectorOfString::clear();
AutoIt:
    $oVectorOfString.clear() -> None
```

### VectorOfString::empty

```cpp
bool VectorOfString::empty();
AutoIt:
    $oVectorOfString.empty() -> retval
```

### VectorOfString::end

```cpp
void* VectorOfString::end();
AutoIt:
    $oVectorOfString.end() -> retval
```

### VectorOfString::get\_Item

```cpp
std::string VectorOfString::get_Item( size_t index );
AutoIt:
    $oVectorOfString.Item( $index ) -> retval
    $oVectorOfString( $index ) -> retval
```

### VectorOfString::get\_\_NewEnum

```cpp
IUnknown* VectorOfString::get__NewEnum();
AutoIt:
    $oVectorOfString._NewEnum() -> retval
```

### VectorOfString::push\_back

```cpp
void VectorOfString::push_back( std::string value );
AutoIt:
    $oVectorOfString.push_back( $value ) -> None
```

### VectorOfString::push\_vector

```cpp
void VectorOfString::push_vector( VectorOfString other );
AutoIt:
    $oVectorOfString.push_vector( $other ) -> None
```

```cpp
void VectorOfString::push_vector( VectorOfString other,
                                  size_t         count,
                                  size_t         start = 0 );
AutoIt:
    $oVectorOfString.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfString::put\_Item

```cpp
void VectorOfString::put_Item( size_t      index,
                               std::string item );
AutoIt:
    $oVectorOfString.Item( $index ) = $item
```

### VectorOfString::size

```cpp
size_t VectorOfString::size();
AutoIt:
    $oVectorOfString.size() -> retval
```

### VectorOfString::slice

```cpp
VectorOfString VectorOfString::slice( size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfString.slice( [$start[, $count]] ) -> retval
```

### VectorOfString::sort

```cpp
void VectorOfString::sort( void*  comparator,
                           size_t start = 0,
                           size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfString.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfString::sort\_variant

```cpp
void VectorOfString::sort_variant( void*  comparator,
                                   size_t start = 0,
                                   size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfString.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfString::start

```cpp
void* VectorOfString::start();
AutoIt:
    $oVectorOfString.start() -> retval
```

## VectorOfVariant

### VectorOfVariant.Count

```cpp
size_t VectorOfVariant::size()
AutoIt:
    [propget] $oVectorOfVariant.Count
```

### VectorOfVariant::create

```cpp
static VectorOfVariant VectorOfVariant::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVariant").create() -> <VectorOfVariant object>
```

```cpp
static VectorOfVariant VectorOfVariant::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVariant").create( $size ) -> <VectorOfVariant object>
```

```cpp
static VectorOfVariant VectorOfVariant::create( VectorOfVariant other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVariant").create( $other ) -> <VectorOfVariant object>
```

### VectorOfVariant::Add

```cpp
void VectorOfVariant::Add( _variant_t value );
AutoIt:
    $oVectorOfVariant.Add( $value ) -> None
```

### VectorOfVariant::Items

```cpp
VectorOfVariant VectorOfVariant::Items();
AutoIt:
    $oVectorOfVariant.Items() -> retval
```

### VectorOfVariant::Keys

```cpp
std::vector<int> VectorOfVariant::Keys();
AutoIt:
    $oVectorOfVariant.Keys() -> retval
```

### VectorOfVariant::Remove

```cpp
void VectorOfVariant::Remove( size_t index );
AutoIt:
    $oVectorOfVariant.Remove( $index ) -> None
```

### VectorOfVariant::append

```cpp
void VectorOfVariant::append( _variant_t value );
AutoIt:
    $oVectorOfVariant.append( $value ) -> None
```

### VectorOfVariant::at

```cpp
_variant_t VectorOfVariant::at( size_t index );
AutoIt:
    $oVectorOfVariant.at( $index ) -> retval
```

```cpp
void VectorOfVariant::at( size_t     index,
                          _variant_t value );
AutoIt:
    $oVectorOfVariant.at( $index, $value ) -> None
```

### VectorOfVariant::clear

```cpp
void VectorOfVariant::clear();
AutoIt:
    $oVectorOfVariant.clear() -> None
```

### VectorOfVariant::empty

```cpp
bool VectorOfVariant::empty();
AutoIt:
    $oVectorOfVariant.empty() -> retval
```

### VectorOfVariant::end

```cpp
void* VectorOfVariant::end();
AutoIt:
    $oVectorOfVariant.end() -> retval
```

### VectorOfVariant::get\_Item

```cpp
_variant_t VectorOfVariant::get_Item( size_t index );
AutoIt:
    $oVectorOfVariant.Item( $index ) -> retval
    $oVectorOfVariant( $index ) -> retval
```

### VectorOfVariant::get\_\_NewEnum

```cpp
IUnknown* VectorOfVariant::get__NewEnum();
AutoIt:
    $oVectorOfVariant._NewEnum() -> retval
```

### VectorOfVariant::push\_back

```cpp
void VectorOfVariant::push_back( _variant_t value );
AutoIt:
    $oVectorOfVariant.push_back( $value ) -> None
```

### VectorOfVariant::push\_vector

```cpp
void VectorOfVariant::push_vector( VectorOfVariant other );
AutoIt:
    $oVectorOfVariant.push_vector( $other ) -> None
```

```cpp
void VectorOfVariant::push_vector( VectorOfVariant other,
                                   size_t          count,
                                   size_t          start = 0 );
AutoIt:
    $oVectorOfVariant.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVariant::put\_Item

```cpp
void VectorOfVariant::put_Item( size_t     index,
                                _variant_t item );
AutoIt:
    $oVectorOfVariant.Item( $index ) = $item
```

### VectorOfVariant::size

```cpp
size_t VectorOfVariant::size();
AutoIt:
    $oVectorOfVariant.size() -> retval
```

### VectorOfVariant::slice

```cpp
VectorOfVariant VectorOfVariant::slice( size_t start = 0,
                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVariant.slice( [$start[, $count]] ) -> retval
```

### VectorOfVariant::sort

```cpp
void VectorOfVariant::sort( void*  comparator,
                            size_t start = 0,
                            size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVariant.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVariant::sort\_variant

```cpp
void VectorOfVariant::sort_variant( void*  comparator,
                                    size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVariant.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVariant::start

```cpp
void* VectorOfVariant::start();
AutoIt:
    $oVectorOfVariant.start() -> retval
```

## VectorOfPairOfULONGAndDouble

### VectorOfPairOfULONGAndDouble.Count

```cpp
size_t VectorOfPairOfULONGAndDouble::size()
AutoIt:
    [propget] $oVectorOfPairOfULONGAndDouble.Count
```

### VectorOfPairOfULONGAndDouble::create

```cpp
static VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndDouble").create() -> <VectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndDouble").create( $size ) -> <VectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::create( VectorOfPairOfULONGAndDouble other );
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndDouble").create( $other ) -> <VectorOfPairOfULONGAndDouble object>
```

### VectorOfPairOfULONGAndDouble::Add

```cpp
void VectorOfPairOfULONGAndDouble::Add( std::pair<ULONG, double> value );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.Add( $value ) -> None
```

### VectorOfPairOfULONGAndDouble::Items

```cpp
VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::Items();
AutoIt:
    $oVectorOfPairOfULONGAndDouble.Items() -> retval
```

### VectorOfPairOfULONGAndDouble::Keys

```cpp
std::vector<int> VectorOfPairOfULONGAndDouble::Keys();
AutoIt:
    $oVectorOfPairOfULONGAndDouble.Keys() -> retval
```

### VectorOfPairOfULONGAndDouble::Remove

```cpp
void VectorOfPairOfULONGAndDouble::Remove( size_t index );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.Remove( $index ) -> None
```

### VectorOfPairOfULONGAndDouble::append

```cpp
void VectorOfPairOfULONGAndDouble::append( std::pair<ULONG, double> value );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.append( $value ) -> None
```

### VectorOfPairOfULONGAndDouble::at

```cpp
std::pair<ULONG, double> VectorOfPairOfULONGAndDouble::at( size_t index );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.at( $index ) -> retval
```

```cpp
void VectorOfPairOfULONGAndDouble::at( size_t                   index,
                                       std::pair<ULONG, double> value );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.at( $index, $value ) -> None
```

### VectorOfPairOfULONGAndDouble::clear

```cpp
void VectorOfPairOfULONGAndDouble::clear();
AutoIt:
    $oVectorOfPairOfULONGAndDouble.clear() -> None
```

### VectorOfPairOfULONGAndDouble::empty

```cpp
bool VectorOfPairOfULONGAndDouble::empty();
AutoIt:
    $oVectorOfPairOfULONGAndDouble.empty() -> retval
```

### VectorOfPairOfULONGAndDouble::end

```cpp
void* VectorOfPairOfULONGAndDouble::end();
AutoIt:
    $oVectorOfPairOfULONGAndDouble.end() -> retval
```

### VectorOfPairOfULONGAndDouble::get\_Item

```cpp
std::pair<ULONG, double> VectorOfPairOfULONGAndDouble::get_Item( size_t index );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.Item( $index ) -> retval
    $oVectorOfPairOfULONGAndDouble( $index ) -> retval
```

### VectorOfPairOfULONGAndDouble::get\_\_NewEnum

```cpp
IUnknown* VectorOfPairOfULONGAndDouble::get__NewEnum();
AutoIt:
    $oVectorOfPairOfULONGAndDouble._NewEnum() -> retval
```

### VectorOfPairOfULONGAndDouble::push\_back

```cpp
void VectorOfPairOfULONGAndDouble::push_back( std::pair<ULONG, double> value );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.push_back( $value ) -> None
```

### VectorOfPairOfULONGAndDouble::push\_vector

```cpp
void VectorOfPairOfULONGAndDouble::push_vector( VectorOfPairOfULONGAndDouble other );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfPairOfULONGAndDouble::push_vector( VectorOfPairOfULONGAndDouble other,
                                                size_t                       count,
                                                size_t                       start = 0 );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPairOfULONGAndDouble::put\_Item

```cpp
void VectorOfPairOfULONGAndDouble::put_Item( size_t                   index,
                                             std::pair<ULONG, double> item );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.Item( $index ) = $item
```

### VectorOfPairOfULONGAndDouble::size

```cpp
size_t VectorOfPairOfULONGAndDouble::size();
AutoIt:
    $oVectorOfPairOfULONGAndDouble.size() -> retval
```

### VectorOfPairOfULONGAndDouble::slice

```cpp
VectorOfPairOfULONGAndDouble VectorOfPairOfULONGAndDouble::slice( size_t start = 0,
                                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfPairOfULONGAndDouble::sort

```cpp
void VectorOfPairOfULONGAndDouble::sort( void*  comparator,
                                         size_t start = 0,
                                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndDouble::sort\_variant

```cpp
void VectorOfPairOfULONGAndDouble::sort_variant( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfULONGAndDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndDouble::start

```cpp
void* VectorOfPairOfULONGAndDouble::start();
AutoIt:
    $oVectorOfPairOfULONGAndDouble.start() -> retval
```

## VectorOfVectorOfPairOfULONGAndDouble

### VectorOfVectorOfPairOfULONGAndDouble.Count

```cpp
size_t VectorOfVectorOfPairOfULONGAndDouble::size()
AutoIt:
    [propget] $oVectorOfVectorOfPairOfULONGAndDouble.Count
```

### VectorOfVectorOfPairOfULONGAndDouble::create

```cpp
static VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndDouble").create() -> <VectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndDouble").create( $size ) -> <VectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::create( VectorOfVectorOfPairOfULONGAndDouble other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndDouble").create( $other ) -> <VectorOfVectorOfPairOfULONGAndDouble object>
```

### VectorOfVectorOfPairOfULONGAndDouble::Add

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::Add( std::vector<std::pair<ULONG, double>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Add( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::Items

```cpp
VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::Items();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Items() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::Keys

```cpp
std::vector<int> VectorOfVectorOfPairOfULONGAndDouble::Keys();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Keys() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::Remove

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Remove( $index ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::append

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::append( std::vector<std::pair<ULONG, double>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.append( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::at

```cpp
std::vector<std::pair<ULONG, double>> VectorOfVectorOfPairOfULONGAndDouble::at( size_t index );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::at( size_t                                index,
                                               std::vector<std::pair<ULONG, double>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.at( $index, $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::clear

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::clear();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.clear() -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::empty

```cpp
bool VectorOfVectorOfPairOfULONGAndDouble::empty();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.empty() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::end

```cpp
void* VectorOfVectorOfPairOfULONGAndDouble::end();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.end() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::get\_Item

```cpp
std::vector<std::pair<ULONG, double>> VectorOfVectorOfPairOfULONGAndDouble::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Item( $index ) -> retval
    $oVectorOfVectorOfPairOfULONGAndDouble( $index ) -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfPairOfULONGAndDouble::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble._NewEnum() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::push\_back

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::push_back( std::vector<std::pair<ULONG, double>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.push_back( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::push\_vector

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfPairOfULONGAndDouble other );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfPairOfULONGAndDouble other,
                                                        size_t                               count,
                                                        size_t                               start = 0 );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::put\_Item

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::put_Item( size_t                                index,
                                                     std::vector<std::pair<ULONG, double>> item );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.Item( $index ) = $item
```

### VectorOfVectorOfPairOfULONGAndDouble::size

```cpp
size_t VectorOfVectorOfPairOfULONGAndDouble::size();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.size() -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::slice

```cpp
VectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfPairOfULONGAndDouble::slice( size_t start = 0,
                                                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfPairOfULONGAndDouble::sort

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::sort( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::sort\_variant

```cpp
void VectorOfVectorOfPairOfULONGAndDouble::sort_variant( void*  comparator,
                                                         size_t start = 0,
                                                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndDouble::start

```cpp
void* VectorOfVectorOfPairOfULONGAndDouble::start();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndDouble.start() -> retval
```

## VectorOfMat

### VectorOfMat.Count

```cpp
size_t VectorOfMat::size()
AutoIt:
    [propget] $oVectorOfMat.Count
```

### VectorOfMat::create

```cpp
static VectorOfMat VectorOfMat::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfMat").create() -> <VectorOfMat object>
```

```cpp
static VectorOfMat VectorOfMat::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfMat").create( $size ) -> <VectorOfMat object>
```

```cpp
static VectorOfMat VectorOfMat::create( VectorOfMat other );
AutoIt:
    _Dlib_ObjCreate("VectorOfMat").create( $other ) -> <VectorOfMat object>
```

### VectorOfMat::Add

```cpp
void VectorOfMat::Add( cv::Mat value );
AutoIt:
    $oVectorOfMat.Add( $value ) -> None
```

### VectorOfMat::Items

```cpp
VectorOfMat VectorOfMat::Items();
AutoIt:
    $oVectorOfMat.Items() -> retval
```

### VectorOfMat::Keys

```cpp
std::vector<int> VectorOfMat::Keys();
AutoIt:
    $oVectorOfMat.Keys() -> retval
```

### VectorOfMat::Remove

```cpp
void VectorOfMat::Remove( size_t index );
AutoIt:
    $oVectorOfMat.Remove( $index ) -> None
```

### VectorOfMat::append

```cpp
void VectorOfMat::append( cv::Mat value );
AutoIt:
    $oVectorOfMat.append( $value ) -> None
```

### VectorOfMat::at

```cpp
cv::Mat VectorOfMat::at( size_t index );
AutoIt:
    $oVectorOfMat.at( $index ) -> retval
```

```cpp
void VectorOfMat::at( size_t  index,
                      cv::Mat value );
AutoIt:
    $oVectorOfMat.at( $index, $value ) -> None
```

### VectorOfMat::clear

```cpp
void VectorOfMat::clear();
AutoIt:
    $oVectorOfMat.clear() -> None
```

### VectorOfMat::empty

```cpp
bool VectorOfMat::empty();
AutoIt:
    $oVectorOfMat.empty() -> retval
```

### VectorOfMat::end

```cpp
void* VectorOfMat::end();
AutoIt:
    $oVectorOfMat.end() -> retval
```

### VectorOfMat::get\_Item

```cpp
cv::Mat VectorOfMat::get_Item( size_t index );
AutoIt:
    $oVectorOfMat.Item( $index ) -> retval
    $oVectorOfMat( $index ) -> retval
```

### VectorOfMat::get\_\_NewEnum

```cpp
IUnknown* VectorOfMat::get__NewEnum();
AutoIt:
    $oVectorOfMat._NewEnum() -> retval
```

### VectorOfMat::push\_back

```cpp
void VectorOfMat::push_back( cv::Mat value );
AutoIt:
    $oVectorOfMat.push_back( $value ) -> None
```

### VectorOfMat::push\_vector

```cpp
void VectorOfMat::push_vector( VectorOfMat other );
AutoIt:
    $oVectorOfMat.push_vector( $other ) -> None
```

```cpp
void VectorOfMat::push_vector( VectorOfMat other,
                               size_t      count,
                               size_t      start = 0 );
AutoIt:
    $oVectorOfMat.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfMat::put\_Item

```cpp
void VectorOfMat::put_Item( size_t  index,
                            cv::Mat item );
AutoIt:
    $oVectorOfMat.Item( $index ) = $item
```

### VectorOfMat::size

```cpp
size_t VectorOfMat::size();
AutoIt:
    $oVectorOfMat.size() -> retval
```

### VectorOfMat::slice

```cpp
VectorOfMat VectorOfMat::slice( size_t start = 0,
                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfMat.slice( [$start[, $count]] ) -> retval
```

### VectorOfMat::sort

```cpp
void VectorOfMat::sort( void*  comparator,
                        size_t start = 0,
                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfMat.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMat::sort\_variant

```cpp
void VectorOfMat::sort_variant( void*  comparator,
                                size_t start = 0,
                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfMat.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMat::start

```cpp
void* VectorOfMat::start();
AutoIt:
    $oVectorOfMat.start() -> retval
```

## VectorOfFull\_object\_detection

### VectorOfFull\_object\_detection.Count

```cpp
size_t VectorOfFull_object_detection::size()
AutoIt:
    [propget] $oVectorOfFull_object_detection.Count
```

### VectorOfFull\_object\_detection::create

```cpp
static VectorOfFull_object_detection VectorOfFull_object_detection::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfFull_object_detection").create() -> <VectorOfFull_object_detection object>
```

```cpp
static VectorOfFull_object_detection VectorOfFull_object_detection::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfFull_object_detection").create( $size ) -> <VectorOfFull_object_detection object>
```

```cpp
static VectorOfFull_object_detection VectorOfFull_object_detection::create( VectorOfFull_object_detection other );
AutoIt:
    _Dlib_ObjCreate("VectorOfFull_object_detection").create( $other ) -> <VectorOfFull_object_detection object>
```

### VectorOfFull\_object\_detection::Add

```cpp
void VectorOfFull_object_detection::Add( dlib::full_object_detection value );
AutoIt:
    $oVectorOfFull_object_detection.Add( $value ) -> None
```

### VectorOfFull\_object\_detection::Items

```cpp
VectorOfFull_object_detection VectorOfFull_object_detection::Items();
AutoIt:
    $oVectorOfFull_object_detection.Items() -> retval
```

### VectorOfFull\_object\_detection::Keys

```cpp
std::vector<int> VectorOfFull_object_detection::Keys();
AutoIt:
    $oVectorOfFull_object_detection.Keys() -> retval
```

### VectorOfFull\_object\_detection::Remove

```cpp
void VectorOfFull_object_detection::Remove( size_t index );
AutoIt:
    $oVectorOfFull_object_detection.Remove( $index ) -> None
```

### VectorOfFull\_object\_detection::append

```cpp
void VectorOfFull_object_detection::append( dlib::full_object_detection value );
AutoIt:
    $oVectorOfFull_object_detection.append( $value ) -> None
```

### VectorOfFull\_object\_detection::at

```cpp
dlib::full_object_detection VectorOfFull_object_detection::at( size_t index );
AutoIt:
    $oVectorOfFull_object_detection.at( $index ) -> retval
```

```cpp
void VectorOfFull_object_detection::at( size_t                      index,
                                        dlib::full_object_detection value );
AutoIt:
    $oVectorOfFull_object_detection.at( $index, $value ) -> None
```

### VectorOfFull\_object\_detection::clear

```cpp
void VectorOfFull_object_detection::clear();
AutoIt:
    $oVectorOfFull_object_detection.clear() -> None
```

### VectorOfFull\_object\_detection::empty

```cpp
bool VectorOfFull_object_detection::empty();
AutoIt:
    $oVectorOfFull_object_detection.empty() -> retval
```

### VectorOfFull\_object\_detection::end

```cpp
void* VectorOfFull_object_detection::end();
AutoIt:
    $oVectorOfFull_object_detection.end() -> retval
```

### VectorOfFull\_object\_detection::get\_Item

```cpp
dlib::full_object_detection VectorOfFull_object_detection::get_Item( size_t index );
AutoIt:
    $oVectorOfFull_object_detection.Item( $index ) -> retval
    $oVectorOfFull_object_detection( $index ) -> retval
```

### VectorOfFull\_object\_detection::get\_\_NewEnum

```cpp
IUnknown* VectorOfFull_object_detection::get__NewEnum();
AutoIt:
    $oVectorOfFull_object_detection._NewEnum() -> retval
```

### VectorOfFull\_object\_detection::push\_back

```cpp
void VectorOfFull_object_detection::push_back( dlib::full_object_detection value );
AutoIt:
    $oVectorOfFull_object_detection.push_back( $value ) -> None
```

### VectorOfFull\_object\_detection::push\_vector

```cpp
void VectorOfFull_object_detection::push_vector( VectorOfFull_object_detection other );
AutoIt:
    $oVectorOfFull_object_detection.push_vector( $other ) -> None
```

```cpp
void VectorOfFull_object_detection::push_vector( VectorOfFull_object_detection other,
                                                 size_t                        count,
                                                 size_t                        start = 0 );
AutoIt:
    $oVectorOfFull_object_detection.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFull\_object\_detection::put\_Item

```cpp
void VectorOfFull_object_detection::put_Item( size_t                      index,
                                              dlib::full_object_detection item );
AutoIt:
    $oVectorOfFull_object_detection.Item( $index ) = $item
```

### VectorOfFull\_object\_detection::size

```cpp
size_t VectorOfFull_object_detection::size();
AutoIt:
    $oVectorOfFull_object_detection.size() -> retval
```

### VectorOfFull\_object\_detection::slice

```cpp
VectorOfFull_object_detection VectorOfFull_object_detection::slice( size_t start = 0,
                                                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFull_object_detection.slice( [$start[, $count]] ) -> retval
```

### VectorOfFull\_object\_detection::sort

```cpp
void VectorOfFull_object_detection::sort( void*  comparator,
                                          size_t start = 0,
                                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFull_object_detection.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFull\_object\_detection::sort\_variant

```cpp
void VectorOfFull_object_detection::sort_variant( void*  comparator,
                                                  size_t start = 0,
                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFull_object_detection.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFull\_object\_detection::start

```cpp
void* VectorOfFull_object_detection::start();
AutoIt:
    $oVectorOfFull_object_detection.start() -> retval
```

## VectorOfULONG

### VectorOfULONG.Count

```cpp
size_t VectorOfULONG::size()
AutoIt:
    [propget] $oVectorOfULONG.Count
```

### VectorOfULONG::create

```cpp
static VectorOfULONG VectorOfULONG::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfULONG").create() -> <VectorOfULONG object>
```

```cpp
static VectorOfULONG VectorOfULONG::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfULONG").create( $size ) -> <VectorOfULONG object>
```

```cpp
static VectorOfULONG VectorOfULONG::create( VectorOfULONG other );
AutoIt:
    _Dlib_ObjCreate("VectorOfULONG").create( $other ) -> <VectorOfULONG object>
```

### VectorOfULONG::Add

```cpp
void VectorOfULONG::Add( ULONG value );
AutoIt:
    $oVectorOfULONG.Add( $value ) -> None
```

### VectorOfULONG::Items

```cpp
VectorOfULONG VectorOfULONG::Items();
AutoIt:
    $oVectorOfULONG.Items() -> retval
```

### VectorOfULONG::Keys

```cpp
std::vector<int> VectorOfULONG::Keys();
AutoIt:
    $oVectorOfULONG.Keys() -> retval
```

### VectorOfULONG::Remove

```cpp
void VectorOfULONG::Remove( size_t index );
AutoIt:
    $oVectorOfULONG.Remove( $index ) -> None
```

### VectorOfULONG::append

```cpp
void VectorOfULONG::append( ULONG value );
AutoIt:
    $oVectorOfULONG.append( $value ) -> None
```

### VectorOfULONG::at

```cpp
ULONG VectorOfULONG::at( size_t index );
AutoIt:
    $oVectorOfULONG.at( $index ) -> retval
```

```cpp
void VectorOfULONG::at( size_t index,
                        ULONG  value );
AutoIt:
    $oVectorOfULONG.at( $index, $value ) -> None
```

### VectorOfULONG::clear

```cpp
void VectorOfULONG::clear();
AutoIt:
    $oVectorOfULONG.clear() -> None
```

### VectorOfULONG::empty

```cpp
bool VectorOfULONG::empty();
AutoIt:
    $oVectorOfULONG.empty() -> retval
```

### VectorOfULONG::end

```cpp
void* VectorOfULONG::end();
AutoIt:
    $oVectorOfULONG.end() -> retval
```

### VectorOfULONG::get\_Item

```cpp
ULONG VectorOfULONG::get_Item( size_t index );
AutoIt:
    $oVectorOfULONG.Item( $index ) -> retval
    $oVectorOfULONG( $index ) -> retval
```

### VectorOfULONG::get\_\_NewEnum

```cpp
IUnknown* VectorOfULONG::get__NewEnum();
AutoIt:
    $oVectorOfULONG._NewEnum() -> retval
```

### VectorOfULONG::push\_back

```cpp
void VectorOfULONG::push_back( ULONG value );
AutoIt:
    $oVectorOfULONG.push_back( $value ) -> None
```

### VectorOfULONG::push\_vector

```cpp
void VectorOfULONG::push_vector( VectorOfULONG other );
AutoIt:
    $oVectorOfULONG.push_vector( $other ) -> None
```

```cpp
void VectorOfULONG::push_vector( VectorOfULONG other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfULONG.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfULONG::put\_Item

```cpp
void VectorOfULONG::put_Item( size_t index,
                              ULONG  item );
AutoIt:
    $oVectorOfULONG.Item( $index ) = $item
```

### VectorOfULONG::size

```cpp
size_t VectorOfULONG::size();
AutoIt:
    $oVectorOfULONG.size() -> retval
```

### VectorOfULONG::slice

```cpp
VectorOfULONG VectorOfULONG::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfULONG.slice( [$start[, $count]] ) -> retval
```

### VectorOfULONG::sort

```cpp
void VectorOfULONG::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfULONG.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfULONG::sort\_variant

```cpp
void VectorOfULONG::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfULONG.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfULONG::start

```cpp
void* VectorOfULONG::start();
AutoIt:
    $oVectorOfULONG.start() -> retval
```

## VectorOfSpaceVector

### VectorOfSpaceVector.Count

```cpp
size_t VectorOfSpaceVector::size()
AutoIt:
    [propget] $oVectorOfSpaceVector.Count
```

### VectorOfSpaceVector::create

```cpp
static VectorOfSpaceVector VectorOfSpaceVector::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfSpaceVector").create() -> <VectorOfSpaceVector object>
```

```cpp
static VectorOfSpaceVector VectorOfSpaceVector::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfSpaceVector").create( $size ) -> <VectorOfSpaceVector object>
```

```cpp
static VectorOfSpaceVector VectorOfSpaceVector::create( VectorOfSpaceVector other );
AutoIt:
    _Dlib_ObjCreate("VectorOfSpaceVector").create( $other ) -> <VectorOfSpaceVector object>
```

### VectorOfSpaceVector::Add

```cpp
void VectorOfSpaceVector::Add( dlib::SpaceVector value );
AutoIt:
    $oVectorOfSpaceVector.Add( $value ) -> None
```

### VectorOfSpaceVector::Items

```cpp
VectorOfSpaceVector VectorOfSpaceVector::Items();
AutoIt:
    $oVectorOfSpaceVector.Items() -> retval
```

### VectorOfSpaceVector::Keys

```cpp
std::vector<int> VectorOfSpaceVector::Keys();
AutoIt:
    $oVectorOfSpaceVector.Keys() -> retval
```

### VectorOfSpaceVector::Remove

```cpp
void VectorOfSpaceVector::Remove( size_t index );
AutoIt:
    $oVectorOfSpaceVector.Remove( $index ) -> None
```

### VectorOfSpaceVector::append

```cpp
void VectorOfSpaceVector::append( dlib::SpaceVector value );
AutoIt:
    $oVectorOfSpaceVector.append( $value ) -> None
```

### VectorOfSpaceVector::at

```cpp
dlib::SpaceVector VectorOfSpaceVector::at( size_t index );
AutoIt:
    $oVectorOfSpaceVector.at( $index ) -> retval
```

```cpp
void VectorOfSpaceVector::at( size_t            index,
                              dlib::SpaceVector value );
AutoIt:
    $oVectorOfSpaceVector.at( $index, $value ) -> None
```

### VectorOfSpaceVector::clear

```cpp
void VectorOfSpaceVector::clear();
AutoIt:
    $oVectorOfSpaceVector.clear() -> None
```

### VectorOfSpaceVector::empty

```cpp
bool VectorOfSpaceVector::empty();
AutoIt:
    $oVectorOfSpaceVector.empty() -> retval
```

### VectorOfSpaceVector::end

```cpp
void* VectorOfSpaceVector::end();
AutoIt:
    $oVectorOfSpaceVector.end() -> retval
```

### VectorOfSpaceVector::get\_Item

```cpp
dlib::SpaceVector VectorOfSpaceVector::get_Item( size_t index );
AutoIt:
    $oVectorOfSpaceVector.Item( $index ) -> retval
    $oVectorOfSpaceVector( $index ) -> retval
```

### VectorOfSpaceVector::get\_\_NewEnum

```cpp
IUnknown* VectorOfSpaceVector::get__NewEnum();
AutoIt:
    $oVectorOfSpaceVector._NewEnum() -> retval
```

### VectorOfSpaceVector::push\_back

```cpp
void VectorOfSpaceVector::push_back( dlib::SpaceVector value );
AutoIt:
    $oVectorOfSpaceVector.push_back( $value ) -> None
```

### VectorOfSpaceVector::push\_vector

```cpp
void VectorOfSpaceVector::push_vector( VectorOfSpaceVector other );
AutoIt:
    $oVectorOfSpaceVector.push_vector( $other ) -> None
```

```cpp
void VectorOfSpaceVector::push_vector( VectorOfSpaceVector other,
                                       size_t              count,
                                       size_t              start = 0 );
AutoIt:
    $oVectorOfSpaceVector.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfSpaceVector::put\_Item

```cpp
void VectorOfSpaceVector::put_Item( size_t            index,
                                    dlib::SpaceVector item );
AutoIt:
    $oVectorOfSpaceVector.Item( $index ) = $item
```

### VectorOfSpaceVector::size

```cpp
size_t VectorOfSpaceVector::size();
AutoIt:
    $oVectorOfSpaceVector.size() -> retval
```

### VectorOfSpaceVector::slice

```cpp
VectorOfSpaceVector VectorOfSpaceVector::slice( size_t start = 0,
                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSpaceVector.slice( [$start[, $count]] ) -> retval
```

### VectorOfSpaceVector::sort

```cpp
void VectorOfSpaceVector::sort( void*  comparator,
                                size_t start = 0,
                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSpaceVector.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSpaceVector::sort\_variant

```cpp
void VectorOfSpaceVector::sort_variant( void*  comparator,
                                        size_t start = 0,
                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSpaceVector.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSpaceVector::start

```cpp
void* VectorOfSpaceVector::start();
AutoIt:
    $oVectorOfSpaceVector.start() -> retval
```

## VectorOfDouble

### VectorOfDouble.Count

```cpp
size_t VectorOfDouble::size()
AutoIt:
    [propget] $oVectorOfDouble.Count
```

### VectorOfDouble::create

```cpp
static VectorOfDouble VectorOfDouble::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfDouble").create() -> <VectorOfDouble object>
```

```cpp
static VectorOfDouble VectorOfDouble::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfDouble").create( $size ) -> <VectorOfDouble object>
```

```cpp
static VectorOfDouble VectorOfDouble::create( VectorOfDouble other );
AutoIt:
    _Dlib_ObjCreate("VectorOfDouble").create( $other ) -> <VectorOfDouble object>
```

### VectorOfDouble::Add

```cpp
void VectorOfDouble::Add( double value );
AutoIt:
    $oVectorOfDouble.Add( $value ) -> None
```

### VectorOfDouble::Items

```cpp
VectorOfDouble VectorOfDouble::Items();
AutoIt:
    $oVectorOfDouble.Items() -> retval
```

### VectorOfDouble::Keys

```cpp
std::vector<int> VectorOfDouble::Keys();
AutoIt:
    $oVectorOfDouble.Keys() -> retval
```

### VectorOfDouble::Remove

```cpp
void VectorOfDouble::Remove( size_t index );
AutoIt:
    $oVectorOfDouble.Remove( $index ) -> None
```

### VectorOfDouble::append

```cpp
void VectorOfDouble::append( double value );
AutoIt:
    $oVectorOfDouble.append( $value ) -> None
```

### VectorOfDouble::at

```cpp
double VectorOfDouble::at( size_t index );
AutoIt:
    $oVectorOfDouble.at( $index ) -> retval
```

```cpp
void VectorOfDouble::at( size_t index,
                         double value );
AutoIt:
    $oVectorOfDouble.at( $index, $value ) -> None
```

### VectorOfDouble::clear

```cpp
void VectorOfDouble::clear();
AutoIt:
    $oVectorOfDouble.clear() -> None
```

### VectorOfDouble::empty

```cpp
bool VectorOfDouble::empty();
AutoIt:
    $oVectorOfDouble.empty() -> retval
```

### VectorOfDouble::end

```cpp
void* VectorOfDouble::end();
AutoIt:
    $oVectorOfDouble.end() -> retval
```

### VectorOfDouble::get\_Item

```cpp
double VectorOfDouble::get_Item( size_t index );
AutoIt:
    $oVectorOfDouble.Item( $index ) -> retval
    $oVectorOfDouble( $index ) -> retval
```

### VectorOfDouble::get\_\_NewEnum

```cpp
IUnknown* VectorOfDouble::get__NewEnum();
AutoIt:
    $oVectorOfDouble._NewEnum() -> retval
```

### VectorOfDouble::push\_back

```cpp
void VectorOfDouble::push_back( double value );
AutoIt:
    $oVectorOfDouble.push_back( $value ) -> None
```

### VectorOfDouble::push\_vector

```cpp
void VectorOfDouble::push_vector( VectorOfDouble other );
AutoIt:
    $oVectorOfDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfDouble::push_vector( VectorOfDouble other,
                                  size_t         count,
                                  size_t         start = 0 );
AutoIt:
    $oVectorOfDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfDouble::put\_Item

```cpp
void VectorOfDouble::put_Item( size_t index,
                               double item );
AutoIt:
    $oVectorOfDouble.Item( $index ) = $item
```

### VectorOfDouble::size

```cpp
size_t VectorOfDouble::size();
AutoIt:
    $oVectorOfDouble.size() -> retval
```

### VectorOfDouble::slice

```cpp
VectorOfDouble VectorOfDouble::slice( size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfDouble::sort

```cpp
void VectorOfDouble::sort( void*  comparator,
                           size_t start = 0,
                           size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDouble::sort\_variant

```cpp
void VectorOfDouble::sort_variant( void*  comparator,
                                   size_t start = 0,
                                   size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDouble::start

```cpp
void* VectorOfDouble::start();
AutoIt:
    $oVectorOfDouble.start() -> retval
```

## VectorOfBool

### VectorOfBool.Count

```cpp
size_t VectorOfBool::size()
AutoIt:
    [propget] $oVectorOfBool.Count
```

### VectorOfBool::create

```cpp
static VectorOfBool VectorOfBool::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfBool").create() -> <VectorOfBool object>
```

```cpp
static VectorOfBool VectorOfBool::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfBool").create( $size ) -> <VectorOfBool object>
```

```cpp
static VectorOfBool VectorOfBool::create( VectorOfBool other );
AutoIt:
    _Dlib_ObjCreate("VectorOfBool").create( $other ) -> <VectorOfBool object>
```

### VectorOfBool::Add

```cpp
void VectorOfBool::Add( bool value );
AutoIt:
    $oVectorOfBool.Add( $value ) -> None
```

### VectorOfBool::Items

```cpp
VectorOfBool VectorOfBool::Items();
AutoIt:
    $oVectorOfBool.Items() -> retval
```

### VectorOfBool::Keys

```cpp
std::vector<int> VectorOfBool::Keys();
AutoIt:
    $oVectorOfBool.Keys() -> retval
```

### VectorOfBool::Remove

```cpp
void VectorOfBool::Remove( size_t index );
AutoIt:
    $oVectorOfBool.Remove( $index ) -> None
```

### VectorOfBool::append

```cpp
void VectorOfBool::append( bool value );
AutoIt:
    $oVectorOfBool.append( $value ) -> None
```

### VectorOfBool::at

```cpp
bool VectorOfBool::at( size_t index );
AutoIt:
    $oVectorOfBool.at( $index ) -> retval
```

```cpp
void VectorOfBool::at( size_t index,
                       bool   value );
AutoIt:
    $oVectorOfBool.at( $index, $value ) -> None
```

### VectorOfBool::clear

```cpp
void VectorOfBool::clear();
AutoIt:
    $oVectorOfBool.clear() -> None
```

### VectorOfBool::empty

```cpp
bool VectorOfBool::empty();
AutoIt:
    $oVectorOfBool.empty() -> retval
```

### VectorOfBool::end

```cpp
void* VectorOfBool::end();
AutoIt:
    $oVectorOfBool.end() -> retval
```

### VectorOfBool::get\_Item

```cpp
bool VectorOfBool::get_Item( size_t index );
AutoIt:
    $oVectorOfBool.Item( $index ) -> retval
    $oVectorOfBool( $index ) -> retval
```

### VectorOfBool::get\_\_NewEnum

```cpp
IUnknown* VectorOfBool::get__NewEnum();
AutoIt:
    $oVectorOfBool._NewEnum() -> retval
```

### VectorOfBool::push\_back

```cpp
void VectorOfBool::push_back( bool value );
AutoIt:
    $oVectorOfBool.push_back( $value ) -> None
```

### VectorOfBool::push\_vector

```cpp
void VectorOfBool::push_vector( VectorOfBool other );
AutoIt:
    $oVectorOfBool.push_vector( $other ) -> None
```

```cpp
void VectorOfBool::push_vector( VectorOfBool other,
                                size_t       count,
                                size_t       start = 0 );
AutoIt:
    $oVectorOfBool.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfBool::put\_Item

```cpp
void VectorOfBool::put_Item( size_t index,
                             bool   item );
AutoIt:
    $oVectorOfBool.Item( $index ) = $item
```

### VectorOfBool::size

```cpp
size_t VectorOfBool::size();
AutoIt:
    $oVectorOfBool.size() -> retval
```

### VectorOfBool::slice

```cpp
VectorOfBool VectorOfBool::slice( size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfBool.slice( [$start[, $count]] ) -> retval
```

### VectorOfBool::sort

```cpp
void VectorOfBool::sort( void*  comparator,
                         size_t start = 0,
                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfBool.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfBool::sort\_variant

```cpp
void VectorOfBool::sort_variant( void*  comparator,
                                 size_t start = 0,
                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfBool.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfBool::start

```cpp
void* VectorOfBool::start();
AutoIt:
    $oVectorOfBool.start() -> retval
```

## VectorOfRectangle

### VectorOfRectangle.Count

```cpp
size_t VectorOfRectangle::size()
AutoIt:
    [propget] $oVectorOfRectangle.Count
```

### VectorOfRectangle::create

```cpp
static VectorOfRectangle VectorOfRectangle::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfRectangle").create() -> <VectorOfRectangle object>
```

```cpp
static VectorOfRectangle VectorOfRectangle::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfRectangle").create( $size ) -> <VectorOfRectangle object>
```

```cpp
static VectorOfRectangle VectorOfRectangle::create( VectorOfRectangle other );
AutoIt:
    _Dlib_ObjCreate("VectorOfRectangle").create( $other ) -> <VectorOfRectangle object>
```

### VectorOfRectangle::Add

```cpp
void VectorOfRectangle::Add( dlib::rectangle value );
AutoIt:
    $oVectorOfRectangle.Add( $value ) -> None
```

### VectorOfRectangle::Items

```cpp
VectorOfRectangle VectorOfRectangle::Items();
AutoIt:
    $oVectorOfRectangle.Items() -> retval
```

### VectorOfRectangle::Keys

```cpp
std::vector<int> VectorOfRectangle::Keys();
AutoIt:
    $oVectorOfRectangle.Keys() -> retval
```

### VectorOfRectangle::Remove

```cpp
void VectorOfRectangle::Remove( size_t index );
AutoIt:
    $oVectorOfRectangle.Remove( $index ) -> None
```

### VectorOfRectangle::append

```cpp
void VectorOfRectangle::append( dlib::rectangle value );
AutoIt:
    $oVectorOfRectangle.append( $value ) -> None
```

### VectorOfRectangle::at

```cpp
dlib::rectangle VectorOfRectangle::at( size_t index );
AutoIt:
    $oVectorOfRectangle.at( $index ) -> retval
```

```cpp
void VectorOfRectangle::at( size_t          index,
                            dlib::rectangle value );
AutoIt:
    $oVectorOfRectangle.at( $index, $value ) -> None
```

### VectorOfRectangle::clear

```cpp
void VectorOfRectangle::clear();
AutoIt:
    $oVectorOfRectangle.clear() -> None
```

### VectorOfRectangle::empty

```cpp
bool VectorOfRectangle::empty();
AutoIt:
    $oVectorOfRectangle.empty() -> retval
```

### VectorOfRectangle::end

```cpp
void* VectorOfRectangle::end();
AutoIt:
    $oVectorOfRectangle.end() -> retval
```

### VectorOfRectangle::get\_Item

```cpp
dlib::rectangle VectorOfRectangle::get_Item( size_t index );
AutoIt:
    $oVectorOfRectangle.Item( $index ) -> retval
    $oVectorOfRectangle( $index ) -> retval
```

### VectorOfRectangle::get\_\_NewEnum

```cpp
IUnknown* VectorOfRectangle::get__NewEnum();
AutoIt:
    $oVectorOfRectangle._NewEnum() -> retval
```

### VectorOfRectangle::push\_back

```cpp
void VectorOfRectangle::push_back( dlib::rectangle value );
AutoIt:
    $oVectorOfRectangle.push_back( $value ) -> None
```

### VectorOfRectangle::push\_vector

```cpp
void VectorOfRectangle::push_vector( VectorOfRectangle other );
AutoIt:
    $oVectorOfRectangle.push_vector( $other ) -> None
```

```cpp
void VectorOfRectangle::push_vector( VectorOfRectangle other,
                                     size_t            count,
                                     size_t            start = 0 );
AutoIt:
    $oVectorOfRectangle.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfRectangle::put\_Item

```cpp
void VectorOfRectangle::put_Item( size_t          index,
                                  dlib::rectangle item );
AutoIt:
    $oVectorOfRectangle.Item( $index ) = $item
```

### VectorOfRectangle::size

```cpp
size_t VectorOfRectangle::size();
AutoIt:
    $oVectorOfRectangle.size() -> retval
```

### VectorOfRectangle::slice

```cpp
VectorOfRectangle VectorOfRectangle::slice( size_t start = 0,
                                            size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfRectangle.slice( [$start[, $count]] ) -> retval
```

### VectorOfRectangle::sort

```cpp
void VectorOfRectangle::sort( void*  comparator,
                              size_t start = 0,
                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfRectangle.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfRectangle::sort\_variant

```cpp
void VectorOfRectangle::sort_variant( void*  comparator,
                                      size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfRectangle.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfRectangle::start

```cpp
void* VectorOfRectangle::start();
AutoIt:
    $oVectorOfRectangle.start() -> retval
```

## VectorOfLong

### VectorOfLong.Count

```cpp
size_t VectorOfLong::size()
AutoIt:
    [propget] $oVectorOfLong.Count
```

### VectorOfLong::create

```cpp
static VectorOfLong VectorOfLong::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfLong").create() -> <VectorOfLong object>
```

```cpp
static VectorOfLong VectorOfLong::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfLong").create( $size ) -> <VectorOfLong object>
```

```cpp
static VectorOfLong VectorOfLong::create( VectorOfLong other );
AutoIt:
    _Dlib_ObjCreate("VectorOfLong").create( $other ) -> <VectorOfLong object>
```

### VectorOfLong::Add

```cpp
void VectorOfLong::Add( long value );
AutoIt:
    $oVectorOfLong.Add( $value ) -> None
```

### VectorOfLong::Items

```cpp
VectorOfLong VectorOfLong::Items();
AutoIt:
    $oVectorOfLong.Items() -> retval
```

### VectorOfLong::Keys

```cpp
std::vector<int> VectorOfLong::Keys();
AutoIt:
    $oVectorOfLong.Keys() -> retval
```

### VectorOfLong::Remove

```cpp
void VectorOfLong::Remove( size_t index );
AutoIt:
    $oVectorOfLong.Remove( $index ) -> None
```

### VectorOfLong::append

```cpp
void VectorOfLong::append( long value );
AutoIt:
    $oVectorOfLong.append( $value ) -> None
```

### VectorOfLong::at

```cpp
long VectorOfLong::at( size_t index );
AutoIt:
    $oVectorOfLong.at( $index ) -> retval
```

```cpp
void VectorOfLong::at( size_t index,
                       long   value );
AutoIt:
    $oVectorOfLong.at( $index, $value ) -> None
```

### VectorOfLong::clear

```cpp
void VectorOfLong::clear();
AutoIt:
    $oVectorOfLong.clear() -> None
```

### VectorOfLong::empty

```cpp
bool VectorOfLong::empty();
AutoIt:
    $oVectorOfLong.empty() -> retval
```

### VectorOfLong::end

```cpp
void* VectorOfLong::end();
AutoIt:
    $oVectorOfLong.end() -> retval
```

### VectorOfLong::get\_Item

```cpp
long VectorOfLong::get_Item( size_t index );
AutoIt:
    $oVectorOfLong.Item( $index ) -> retval
    $oVectorOfLong( $index ) -> retval
```

### VectorOfLong::get\_\_NewEnum

```cpp
IUnknown* VectorOfLong::get__NewEnum();
AutoIt:
    $oVectorOfLong._NewEnum() -> retval
```

### VectorOfLong::push\_back

```cpp
void VectorOfLong::push_back( long value );
AutoIt:
    $oVectorOfLong.push_back( $value ) -> None
```

### VectorOfLong::push\_vector

```cpp
void VectorOfLong::push_vector( VectorOfLong other );
AutoIt:
    $oVectorOfLong.push_vector( $other ) -> None
```

```cpp
void VectorOfLong::push_vector( VectorOfLong other,
                                size_t       count,
                                size_t       start = 0 );
AutoIt:
    $oVectorOfLong.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfLong::put\_Item

```cpp
void VectorOfLong::put_Item( size_t index,
                             long   item );
AutoIt:
    $oVectorOfLong.Item( $index ) = $item
```

### VectorOfLong::size

```cpp
size_t VectorOfLong::size();
AutoIt:
    $oVectorOfLong.size() -> retval
```

### VectorOfLong::slice

```cpp
VectorOfLong VectorOfLong::slice( size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfLong.slice( [$start[, $count]] ) -> retval
```

### VectorOfLong::sort

```cpp
void VectorOfLong::sort( void*  comparator,
                         size_t start = 0,
                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfLong.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfLong::sort\_variant

```cpp
void VectorOfLong::sort_variant( void*  comparator,
                                 size_t start = 0,
                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfLong.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfLong::start

```cpp
void* VectorOfLong::start();
AutoIt:
    $oVectorOfLong.start() -> retval
```

## VectorOfVectorOfSpaceVector

### VectorOfVectorOfSpaceVector.Count

```cpp
size_t VectorOfVectorOfSpaceVector::size()
AutoIt:
    [propget] $oVectorOfVectorOfSpaceVector.Count
```

### VectorOfVectorOfSpaceVector::create

```cpp
static VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfSpaceVector").create() -> <VectorOfVectorOfSpaceVector object>
```

```cpp
static VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfSpaceVector").create( $size ) -> <VectorOfVectorOfSpaceVector object>
```

```cpp
static VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::create( VectorOfVectorOfSpaceVector other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfSpaceVector").create( $other ) -> <VectorOfVectorOfSpaceVector object>
```

### VectorOfVectorOfSpaceVector::Add

```cpp
void VectorOfVectorOfSpaceVector::Add( std::vector<dlib::SpaceVector> value );
AutoIt:
    $oVectorOfVectorOfSpaceVector.Add( $value ) -> None
```

### VectorOfVectorOfSpaceVector::Items

```cpp
VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::Items();
AutoIt:
    $oVectorOfVectorOfSpaceVector.Items() -> retval
```

### VectorOfVectorOfSpaceVector::Keys

```cpp
std::vector<int> VectorOfVectorOfSpaceVector::Keys();
AutoIt:
    $oVectorOfVectorOfSpaceVector.Keys() -> retval
```

### VectorOfVectorOfSpaceVector::Remove

```cpp
void VectorOfVectorOfSpaceVector::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfSpaceVector.Remove( $index ) -> None
```

### VectorOfVectorOfSpaceVector::append

```cpp
void VectorOfVectorOfSpaceVector::append( std::vector<dlib::SpaceVector> value );
AutoIt:
    $oVectorOfVectorOfSpaceVector.append( $value ) -> None
```

### VectorOfVectorOfSpaceVector::at

```cpp
std::vector<dlib::SpaceVector> VectorOfVectorOfSpaceVector::at( size_t index );
AutoIt:
    $oVectorOfVectorOfSpaceVector.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfSpaceVector::at( size_t                         index,
                                      std::vector<dlib::SpaceVector> value );
AutoIt:
    $oVectorOfVectorOfSpaceVector.at( $index, $value ) -> None
```

### VectorOfVectorOfSpaceVector::clear

```cpp
void VectorOfVectorOfSpaceVector::clear();
AutoIt:
    $oVectorOfVectorOfSpaceVector.clear() -> None
```

### VectorOfVectorOfSpaceVector::empty

```cpp
bool VectorOfVectorOfSpaceVector::empty();
AutoIt:
    $oVectorOfVectorOfSpaceVector.empty() -> retval
```

### VectorOfVectorOfSpaceVector::end

```cpp
void* VectorOfVectorOfSpaceVector::end();
AutoIt:
    $oVectorOfVectorOfSpaceVector.end() -> retval
```

### VectorOfVectorOfSpaceVector::get\_Item

```cpp
std::vector<dlib::SpaceVector> VectorOfVectorOfSpaceVector::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfSpaceVector.Item( $index ) -> retval
    $oVectorOfVectorOfSpaceVector( $index ) -> retval
```

### VectorOfVectorOfSpaceVector::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfSpaceVector::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfSpaceVector._NewEnum() -> retval
```

### VectorOfVectorOfSpaceVector::push\_back

```cpp
void VectorOfVectorOfSpaceVector::push_back( std::vector<dlib::SpaceVector> value );
AutoIt:
    $oVectorOfVectorOfSpaceVector.push_back( $value ) -> None
```

### VectorOfVectorOfSpaceVector::push\_vector

```cpp
void VectorOfVectorOfSpaceVector::push_vector( VectorOfVectorOfSpaceVector other );
AutoIt:
    $oVectorOfVectorOfSpaceVector.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfSpaceVector::push_vector( VectorOfVectorOfSpaceVector other,
                                               size_t                      count,
                                               size_t                      start = 0 );
AutoIt:
    $oVectorOfVectorOfSpaceVector.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfSpaceVector::put\_Item

```cpp
void VectorOfVectorOfSpaceVector::put_Item( size_t                         index,
                                            std::vector<dlib::SpaceVector> item );
AutoIt:
    $oVectorOfVectorOfSpaceVector.Item( $index ) = $item
```

### VectorOfVectorOfSpaceVector::size

```cpp
size_t VectorOfVectorOfSpaceVector::size();
AutoIt:
    $oVectorOfVectorOfSpaceVector.size() -> retval
```

### VectorOfVectorOfSpaceVector::slice

```cpp
VectorOfVectorOfSpaceVector VectorOfVectorOfSpaceVector::slice( size_t start = 0,
                                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfSpaceVector.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfSpaceVector::sort

```cpp
void VectorOfVectorOfSpaceVector::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfSpaceVector.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfSpaceVector::sort\_variant

```cpp
void VectorOfVectorOfSpaceVector::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfSpaceVector.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfSpaceVector::start

```cpp
void* VectorOfVectorOfSpaceVector::start();
AutoIt:
    $oVectorOfVectorOfSpaceVector.start() -> retval
```

## VectorOfPairOfULONGAndULONG

### VectorOfPairOfULONGAndULONG.Count

```cpp
size_t VectorOfPairOfULONGAndULONG::size()
AutoIt:
    [propget] $oVectorOfPairOfULONGAndULONG.Count
```

### VectorOfPairOfULONGAndULONG::create

```cpp
static VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndULONG").create() -> <VectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndULONG").create( $size ) -> <VectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::create( VectorOfPairOfULONGAndULONG other );
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfULONGAndULONG").create( $other ) -> <VectorOfPairOfULONGAndULONG object>
```

### VectorOfPairOfULONGAndULONG::Add

```cpp
void VectorOfPairOfULONGAndULONG::Add( std::pair<ULONG, ULONG> value );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.Add( $value ) -> None
```

### VectorOfPairOfULONGAndULONG::Items

```cpp
VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::Items();
AutoIt:
    $oVectorOfPairOfULONGAndULONG.Items() -> retval
```

### VectorOfPairOfULONGAndULONG::Keys

```cpp
std::vector<int> VectorOfPairOfULONGAndULONG::Keys();
AutoIt:
    $oVectorOfPairOfULONGAndULONG.Keys() -> retval
```

### VectorOfPairOfULONGAndULONG::Remove

```cpp
void VectorOfPairOfULONGAndULONG::Remove( size_t index );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.Remove( $index ) -> None
```

### VectorOfPairOfULONGAndULONG::append

```cpp
void VectorOfPairOfULONGAndULONG::append( std::pair<ULONG, ULONG> value );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.append( $value ) -> None
```

### VectorOfPairOfULONGAndULONG::at

```cpp
std::pair<ULONG, ULONG> VectorOfPairOfULONGAndULONG::at( size_t index );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.at( $index ) -> retval
```

```cpp
void VectorOfPairOfULONGAndULONG::at( size_t                  index,
                                      std::pair<ULONG, ULONG> value );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.at( $index, $value ) -> None
```

### VectorOfPairOfULONGAndULONG::clear

```cpp
void VectorOfPairOfULONGAndULONG::clear();
AutoIt:
    $oVectorOfPairOfULONGAndULONG.clear() -> None
```

### VectorOfPairOfULONGAndULONG::empty

```cpp
bool VectorOfPairOfULONGAndULONG::empty();
AutoIt:
    $oVectorOfPairOfULONGAndULONG.empty() -> retval
```

### VectorOfPairOfULONGAndULONG::end

```cpp
void* VectorOfPairOfULONGAndULONG::end();
AutoIt:
    $oVectorOfPairOfULONGAndULONG.end() -> retval
```

### VectorOfPairOfULONGAndULONG::get\_Item

```cpp
std::pair<ULONG, ULONG> VectorOfPairOfULONGAndULONG::get_Item( size_t index );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.Item( $index ) -> retval
    $oVectorOfPairOfULONGAndULONG( $index ) -> retval
```

### VectorOfPairOfULONGAndULONG::get\_\_NewEnum

```cpp
IUnknown* VectorOfPairOfULONGAndULONG::get__NewEnum();
AutoIt:
    $oVectorOfPairOfULONGAndULONG._NewEnum() -> retval
```

### VectorOfPairOfULONGAndULONG::push\_back

```cpp
void VectorOfPairOfULONGAndULONG::push_back( std::pair<ULONG, ULONG> value );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.push_back( $value ) -> None
```

### VectorOfPairOfULONGAndULONG::push\_vector

```cpp
void VectorOfPairOfULONGAndULONG::push_vector( VectorOfPairOfULONGAndULONG other );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.push_vector( $other ) -> None
```

```cpp
void VectorOfPairOfULONGAndULONG::push_vector( VectorOfPairOfULONGAndULONG other,
                                               size_t                      count,
                                               size_t                      start = 0 );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPairOfULONGAndULONG::put\_Item

```cpp
void VectorOfPairOfULONGAndULONG::put_Item( size_t                  index,
                                            std::pair<ULONG, ULONG> item );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.Item( $index ) = $item
```

### VectorOfPairOfULONGAndULONG::size

```cpp
size_t VectorOfPairOfULONGAndULONG::size();
AutoIt:
    $oVectorOfPairOfULONGAndULONG.size() -> retval
```

### VectorOfPairOfULONGAndULONG::slice

```cpp
VectorOfPairOfULONGAndULONG VectorOfPairOfULONGAndULONG::slice( size_t start = 0,
                                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.slice( [$start[, $count]] ) -> retval
```

### VectorOfPairOfULONGAndULONG::sort

```cpp
void VectorOfPairOfULONGAndULONG::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndULONG::sort\_variant

```cpp
void VectorOfPairOfULONGAndULONG::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfULONGAndULONG.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfULONGAndULONG::start

```cpp
void* VectorOfPairOfULONGAndULONG::start();
AutoIt:
    $oVectorOfPairOfULONGAndULONG.start() -> retval
```

## VectorOfVectorOfPairOfULONGAndULONG

### VectorOfVectorOfPairOfULONGAndULONG.Count

```cpp
size_t VectorOfVectorOfPairOfULONGAndULONG::size()
AutoIt:
    [propget] $oVectorOfVectorOfPairOfULONGAndULONG.Count
```

### VectorOfVectorOfPairOfULONGAndULONG::create

```cpp
static VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndULONG").create() -> <VectorOfVectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndULONG").create( $size ) -> <VectorOfVectorOfPairOfULONGAndULONG object>
```

```cpp
static VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::create( VectorOfVectorOfPairOfULONGAndULONG other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndULONG").create( $other ) -> <VectorOfVectorOfPairOfULONGAndULONG object>
```

### VectorOfVectorOfPairOfULONGAndULONG::Add

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::Add( std::vector<std::pair<ULONG, ULONG>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Add( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::Items

```cpp
VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::Items();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Items() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::Keys

```cpp
std::vector<int> VectorOfVectorOfPairOfULONGAndULONG::Keys();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Keys() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::Remove

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Remove( $index ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::append

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::append( std::vector<std::pair<ULONG, ULONG>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.append( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::at

```cpp
std::vector<std::pair<ULONG, ULONG>> VectorOfVectorOfPairOfULONGAndULONG::at( size_t index );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::at( size_t                               index,
                                              std::vector<std::pair<ULONG, ULONG>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.at( $index, $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::clear

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::clear();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.clear() -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::empty

```cpp
bool VectorOfVectorOfPairOfULONGAndULONG::empty();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.empty() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::end

```cpp
void* VectorOfVectorOfPairOfULONGAndULONG::end();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.end() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::get\_Item

```cpp
std::vector<std::pair<ULONG, ULONG>> VectorOfVectorOfPairOfULONGAndULONG::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Item( $index ) -> retval
    $oVectorOfVectorOfPairOfULONGAndULONG( $index ) -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfPairOfULONGAndULONG::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG._NewEnum() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::push\_back

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::push_back( std::vector<std::pair<ULONG, ULONG>> value );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.push_back( $value ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::push\_vector

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::push_vector( VectorOfVectorOfPairOfULONGAndULONG other );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::push_vector( VectorOfVectorOfPairOfULONGAndULONG other,
                                                       size_t                              count,
                                                       size_t                              start = 0 );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::put\_Item

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::put_Item( size_t                               index,
                                                    std::vector<std::pair<ULONG, ULONG>> item );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.Item( $index ) = $item
```

### VectorOfVectorOfPairOfULONGAndULONG::size

```cpp
size_t VectorOfVectorOfPairOfULONGAndULONG::size();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.size() -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::slice

```cpp
VectorOfVectorOfPairOfULONGAndULONG VectorOfVectorOfPairOfULONGAndULONG::slice( size_t start = 0,
                                                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfPairOfULONGAndULONG::sort

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::sort( void*  comparator,
                                                size_t start = 0,
                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::sort\_variant

```cpp
void VectorOfVectorOfPairOfULONGAndULONG::sort_variant( void*  comparator,
                                                        size_t start = 0,
                                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfPairOfULONGAndULONG::start

```cpp
void* VectorOfVectorOfPairOfULONGAndULONG::start();
AutoIt:
    $oVectorOfVectorOfPairOfULONGAndULONG.start() -> retval
```

## VectorOfVectorOfVectorOfPairOfULONGAndDouble

### VectorOfVectorOfVectorOfPairOfULONGAndDouble.Count

```cpp
size_t VectorOfVectorOfVectorOfPairOfULONGAndDouble::size()
AutoIt:
    [propget] $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Count
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::create

```cpp
static VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfVectorOfPairOfULONGAndDouble").create() -> <VectorOfVectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfVectorOfPairOfULONGAndDouble").create( $size ) -> <VectorOfVectorOfVectorOfPairOfULONGAndDouble object>
```

```cpp
static VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::create( VectorOfVectorOfVectorOfPairOfULONGAndDouble other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfVectorOfPairOfULONGAndDouble").create( $other ) -> <VectorOfVectorOfVectorOfPairOfULONGAndDouble object>
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Add

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::Add( std::vector<std::vector<std::pair<ULONG, double>>> value );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Add( $value ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Items

```cpp
VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::Items();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Items() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Keys

```cpp
std::vector<int> VectorOfVectorOfVectorOfPairOfULONGAndDouble::Keys();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Keys() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::Remove

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Remove( $index ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::append

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::append( std::vector<std::vector<std::pair<ULONG, double>>> value );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.append( $value ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::at

```cpp
std::vector<std::vector<std::pair<ULONG, double>>> VectorOfVectorOfVectorOfPairOfULONGAndDouble::at( size_t index );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::at( size_t                                             index,
                                                       std::vector<std::vector<std::pair<ULONG, double>>> value );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.at( $index, $value ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::clear

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::clear();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.clear() -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::empty

```cpp
bool VectorOfVectorOfVectorOfPairOfULONGAndDouble::empty();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.empty() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::end

```cpp
void* VectorOfVectorOfVectorOfPairOfULONGAndDouble::end();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.end() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::get\_Item

```cpp
std::vector<std::vector<std::pair<ULONG, double>>> VectorOfVectorOfVectorOfPairOfULONGAndDouble::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Item( $index ) -> retval
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble( $index ) -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfVectorOfPairOfULONGAndDouble::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble._NewEnum() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::push\_back

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_back( std::vector<std::vector<std::pair<ULONG, double>>> value );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.push_back( $value ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::push\_vector

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfVectorOfPairOfULONGAndDouble other );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::push_vector( VectorOfVectorOfVectorOfPairOfULONGAndDouble other,
                                                                size_t                                       count,
                                                                size_t                                       start = 0 );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::put\_Item

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::put_Item( size_t                                             index,
                                                             std::vector<std::vector<std::pair<ULONG, double>>> item );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.Item( $index ) = $item
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::size

```cpp
size_t VectorOfVectorOfVectorOfPairOfULONGAndDouble::size();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.size() -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::slice

```cpp
VectorOfVectorOfVectorOfPairOfULONGAndDouble VectorOfVectorOfVectorOfPairOfULONGAndDouble::slice( size_t start = 0,
                                                                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort( void*  comparator,
                                                         size_t start = 0,
                                                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort\_variant

```cpp
void VectorOfVectorOfVectorOfPairOfULONGAndDouble::sort_variant( void*  comparator,
                                                                 size_t start = 0,
                                                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfVectorOfPairOfULONGAndDouble::start

```cpp
void* VectorOfVectorOfVectorOfPairOfULONGAndDouble::start();
AutoIt:
    $oVectorOfVectorOfVectorOfPairOfULONGAndDouble.start() -> retval
```

## VectorOfVectorOfFull\_object\_detection

### VectorOfVectorOfFull\_object\_detection.Count

```cpp
size_t VectorOfVectorOfFull_object_detection::size()
AutoIt:
    [propget] $oVectorOfVectorOfFull_object_detection.Count
```

### VectorOfVectorOfFull\_object\_detection::create

```cpp
static VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFull_object_detection").create() -> <VectorOfVectorOfFull_object_detection object>
```

```cpp
static VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFull_object_detection").create( $size ) -> <VectorOfVectorOfFull_object_detection object>
```

```cpp
static VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::create( VectorOfVectorOfFull_object_detection other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFull_object_detection").create( $other ) -> <VectorOfVectorOfFull_object_detection object>
```

### VectorOfVectorOfFull\_object\_detection::Add

```cpp
void VectorOfVectorOfFull_object_detection::Add( std::vector<dlib::full_object_detection> value );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.Add( $value ) -> None
```

### VectorOfVectorOfFull\_object\_detection::Items

```cpp
VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::Items();
AutoIt:
    $oVectorOfVectorOfFull_object_detection.Items() -> retval
```

### VectorOfVectorOfFull\_object\_detection::Keys

```cpp
std::vector<int> VectorOfVectorOfFull_object_detection::Keys();
AutoIt:
    $oVectorOfVectorOfFull_object_detection.Keys() -> retval
```

### VectorOfVectorOfFull\_object\_detection::Remove

```cpp
void VectorOfVectorOfFull_object_detection::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.Remove( $index ) -> None
```

### VectorOfVectorOfFull\_object\_detection::append

```cpp
void VectorOfVectorOfFull_object_detection::append( std::vector<dlib::full_object_detection> value );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.append( $value ) -> None
```

### VectorOfVectorOfFull\_object\_detection::at

```cpp
std::vector<dlib::full_object_detection> VectorOfVectorOfFull_object_detection::at( size_t index );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfFull_object_detection::at( size_t                                   index,
                                                std::vector<dlib::full_object_detection> value );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.at( $index, $value ) -> None
```

### VectorOfVectorOfFull\_object\_detection::clear

```cpp
void VectorOfVectorOfFull_object_detection::clear();
AutoIt:
    $oVectorOfVectorOfFull_object_detection.clear() -> None
```

### VectorOfVectorOfFull\_object\_detection::empty

```cpp
bool VectorOfVectorOfFull_object_detection::empty();
AutoIt:
    $oVectorOfVectorOfFull_object_detection.empty() -> retval
```

### VectorOfVectorOfFull\_object\_detection::end

```cpp
void* VectorOfVectorOfFull_object_detection::end();
AutoIt:
    $oVectorOfVectorOfFull_object_detection.end() -> retval
```

### VectorOfVectorOfFull\_object\_detection::get\_Item

```cpp
std::vector<dlib::full_object_detection> VectorOfVectorOfFull_object_detection::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.Item( $index ) -> retval
    $oVectorOfVectorOfFull_object_detection( $index ) -> retval
```

### VectorOfVectorOfFull\_object\_detection::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfFull_object_detection::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfFull_object_detection._NewEnum() -> retval
```

### VectorOfVectorOfFull\_object\_detection::push\_back

```cpp
void VectorOfVectorOfFull_object_detection::push_back( std::vector<dlib::full_object_detection> value );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.push_back( $value ) -> None
```

### VectorOfVectorOfFull\_object\_detection::push\_vector

```cpp
void VectorOfVectorOfFull_object_detection::push_vector( VectorOfVectorOfFull_object_detection other );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfFull_object_detection::push_vector( VectorOfVectorOfFull_object_detection other,
                                                         size_t                                count,
                                                         size_t                                start = 0 );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfFull\_object\_detection::put\_Item

```cpp
void VectorOfVectorOfFull_object_detection::put_Item( size_t                                   index,
                                                      std::vector<dlib::full_object_detection> item );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.Item( $index ) = $item
```

### VectorOfVectorOfFull\_object\_detection::size

```cpp
size_t VectorOfVectorOfFull_object_detection::size();
AutoIt:
    $oVectorOfVectorOfFull_object_detection.size() -> retval
```

### VectorOfVectorOfFull\_object\_detection::slice

```cpp
VectorOfVectorOfFull_object_detection VectorOfVectorOfFull_object_detection::slice( size_t start = 0,
                                                                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfFull\_object\_detection::sort

```cpp
void VectorOfVectorOfFull_object_detection::sort( void*  comparator,
                                                  size_t start = 0,
                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFull\_object\_detection::sort\_variant

```cpp
void VectorOfVectorOfFull_object_detection::sort_variant( void*  comparator,
                                                          size_t start = 0,
                                                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfFull_object_detection.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFull\_object\_detection::start

```cpp
void* VectorOfVectorOfFull_object_detection::start();
AutoIt:
    $oVectorOfVectorOfFull_object_detection.start() -> retval
```

## VectorOfVectorOfRectangle

### VectorOfVectorOfRectangle.Count

```cpp
size_t VectorOfVectorOfRectangle::size()
AutoIt:
    [propget] $oVectorOfVectorOfRectangle.Count
```

### VectorOfVectorOfRectangle::create

```cpp
static VectorOfVectorOfRectangle VectorOfVectorOfRectangle::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfRectangle").create() -> <VectorOfVectorOfRectangle object>
```

```cpp
static VectorOfVectorOfRectangle VectorOfVectorOfRectangle::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfRectangle").create( $size ) -> <VectorOfVectorOfRectangle object>
```

```cpp
static VectorOfVectorOfRectangle VectorOfVectorOfRectangle::create( VectorOfVectorOfRectangle other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfRectangle").create( $other ) -> <VectorOfVectorOfRectangle object>
```

### VectorOfVectorOfRectangle::Add

```cpp
void VectorOfVectorOfRectangle::Add( std::vector<dlib::rectangle> value );
AutoIt:
    $oVectorOfVectorOfRectangle.Add( $value ) -> None
```

### VectorOfVectorOfRectangle::Items

```cpp
VectorOfVectorOfRectangle VectorOfVectorOfRectangle::Items();
AutoIt:
    $oVectorOfVectorOfRectangle.Items() -> retval
```

### VectorOfVectorOfRectangle::Keys

```cpp
std::vector<int> VectorOfVectorOfRectangle::Keys();
AutoIt:
    $oVectorOfVectorOfRectangle.Keys() -> retval
```

### VectorOfVectorOfRectangle::Remove

```cpp
void VectorOfVectorOfRectangle::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfRectangle.Remove( $index ) -> None
```

### VectorOfVectorOfRectangle::append

```cpp
void VectorOfVectorOfRectangle::append( std::vector<dlib::rectangle> value );
AutoIt:
    $oVectorOfVectorOfRectangle.append( $value ) -> None
```

### VectorOfVectorOfRectangle::at

```cpp
std::vector<dlib::rectangle> VectorOfVectorOfRectangle::at( size_t index );
AutoIt:
    $oVectorOfVectorOfRectangle.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfRectangle::at( size_t                       index,
                                    std::vector<dlib::rectangle> value );
AutoIt:
    $oVectorOfVectorOfRectangle.at( $index, $value ) -> None
```

### VectorOfVectorOfRectangle::clear

```cpp
void VectorOfVectorOfRectangle::clear();
AutoIt:
    $oVectorOfVectorOfRectangle.clear() -> None
```

### VectorOfVectorOfRectangle::empty

```cpp
bool VectorOfVectorOfRectangle::empty();
AutoIt:
    $oVectorOfVectorOfRectangle.empty() -> retval
```

### VectorOfVectorOfRectangle::end

```cpp
void* VectorOfVectorOfRectangle::end();
AutoIt:
    $oVectorOfVectorOfRectangle.end() -> retval
```

### VectorOfVectorOfRectangle::get\_Item

```cpp
std::vector<dlib::rectangle> VectorOfVectorOfRectangle::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfRectangle.Item( $index ) -> retval
    $oVectorOfVectorOfRectangle( $index ) -> retval
```

### VectorOfVectorOfRectangle::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfRectangle::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfRectangle._NewEnum() -> retval
```

### VectorOfVectorOfRectangle::push\_back

```cpp
void VectorOfVectorOfRectangle::push_back( std::vector<dlib::rectangle> value );
AutoIt:
    $oVectorOfVectorOfRectangle.push_back( $value ) -> None
```

### VectorOfVectorOfRectangle::push\_vector

```cpp
void VectorOfVectorOfRectangle::push_vector( VectorOfVectorOfRectangle other );
AutoIt:
    $oVectorOfVectorOfRectangle.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfRectangle::push_vector( VectorOfVectorOfRectangle other,
                                             size_t                    count,
                                             size_t                    start = 0 );
AutoIt:
    $oVectorOfVectorOfRectangle.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfRectangle::put\_Item

```cpp
void VectorOfVectorOfRectangle::put_Item( size_t                       index,
                                          std::vector<dlib::rectangle> item );
AutoIt:
    $oVectorOfVectorOfRectangle.Item( $index ) = $item
```

### VectorOfVectorOfRectangle::size

```cpp
size_t VectorOfVectorOfRectangle::size();
AutoIt:
    $oVectorOfVectorOfRectangle.size() -> retval
```

### VectorOfVectorOfRectangle::slice

```cpp
VectorOfVectorOfRectangle VectorOfVectorOfRectangle::slice( size_t start = 0,
                                                            size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfRectangle.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfRectangle::sort

```cpp
void VectorOfVectorOfRectangle::sort( void*  comparator,
                                      size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfRectangle.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfRectangle::sort\_variant

```cpp
void VectorOfVectorOfRectangle::sort_variant( void*  comparator,
                                              size_t start = 0,
                                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfRectangle.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfRectangle::start

```cpp
void* VectorOfVectorOfRectangle::start();
AutoIt:
    $oVectorOfVectorOfRectangle.start() -> retval
```

## VectorOfVec\_ranking\_pair

### VectorOfVec\_ranking\_pair.Count

```cpp
size_t VectorOfVec_ranking_pair::size()
AutoIt:
    [propget] $oVectorOfVec_ranking_pair.Count
```

### VectorOfVec\_ranking\_pair::create

```cpp
static VectorOfVec_ranking_pair VectorOfVec_ranking_pair::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec_ranking_pair").create() -> <VectorOfVec_ranking_pair object>
```

```cpp
static VectorOfVec_ranking_pair VectorOfVec_ranking_pair::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec_ranking_pair").create( $size ) -> <VectorOfVec_ranking_pair object>
```

```cpp
static VectorOfVec_ranking_pair VectorOfVec_ranking_pair::create( VectorOfVec_ranking_pair other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec_ranking_pair").create( $other ) -> <VectorOfVec_ranking_pair object>
```

### VectorOfVec\_ranking\_pair::Add

```cpp
void VectorOfVec_ranking_pair::Add( dlib::vec_ranking_pair value );
AutoIt:
    $oVectorOfVec_ranking_pair.Add( $value ) -> None
```

### VectorOfVec\_ranking\_pair::Items

```cpp
VectorOfVec_ranking_pair VectorOfVec_ranking_pair::Items();
AutoIt:
    $oVectorOfVec_ranking_pair.Items() -> retval
```

### VectorOfVec\_ranking\_pair::Keys

```cpp
std::vector<int> VectorOfVec_ranking_pair::Keys();
AutoIt:
    $oVectorOfVec_ranking_pair.Keys() -> retval
```

### VectorOfVec\_ranking\_pair::Remove

```cpp
void VectorOfVec_ranking_pair::Remove( size_t index );
AutoIt:
    $oVectorOfVec_ranking_pair.Remove( $index ) -> None
```

### VectorOfVec\_ranking\_pair::append

```cpp
void VectorOfVec_ranking_pair::append( dlib::vec_ranking_pair value );
AutoIt:
    $oVectorOfVec_ranking_pair.append( $value ) -> None
```

### VectorOfVec\_ranking\_pair::at

```cpp
dlib::vec_ranking_pair VectorOfVec_ranking_pair::at( size_t index );
AutoIt:
    $oVectorOfVec_ranking_pair.at( $index ) -> retval
```

```cpp
void VectorOfVec_ranking_pair::at( size_t                 index,
                                   dlib::vec_ranking_pair value );
AutoIt:
    $oVectorOfVec_ranking_pair.at( $index, $value ) -> None
```

### VectorOfVec\_ranking\_pair::clear

```cpp
void VectorOfVec_ranking_pair::clear();
AutoIt:
    $oVectorOfVec_ranking_pair.clear() -> None
```

### VectorOfVec\_ranking\_pair::empty

```cpp
bool VectorOfVec_ranking_pair::empty();
AutoIt:
    $oVectorOfVec_ranking_pair.empty() -> retval
```

### VectorOfVec\_ranking\_pair::end

```cpp
void* VectorOfVec_ranking_pair::end();
AutoIt:
    $oVectorOfVec_ranking_pair.end() -> retval
```

### VectorOfVec\_ranking\_pair::get\_Item

```cpp
dlib::vec_ranking_pair VectorOfVec_ranking_pair::get_Item( size_t index );
AutoIt:
    $oVectorOfVec_ranking_pair.Item( $index ) -> retval
    $oVectorOfVec_ranking_pair( $index ) -> retval
```

### VectorOfVec\_ranking\_pair::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec_ranking_pair::get__NewEnum();
AutoIt:
    $oVectorOfVec_ranking_pair._NewEnum() -> retval
```

### VectorOfVec\_ranking\_pair::push\_back

```cpp
void VectorOfVec_ranking_pair::push_back( dlib::vec_ranking_pair value );
AutoIt:
    $oVectorOfVec_ranking_pair.push_back( $value ) -> None
```

### VectorOfVec\_ranking\_pair::push\_vector

```cpp
void VectorOfVec_ranking_pair::push_vector( VectorOfVec_ranking_pair other );
AutoIt:
    $oVectorOfVec_ranking_pair.push_vector( $other ) -> None
```

```cpp
void VectorOfVec_ranking_pair::push_vector( VectorOfVec_ranking_pair other,
                                            size_t                   count,
                                            size_t                   start = 0 );
AutoIt:
    $oVectorOfVec_ranking_pair.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec\_ranking\_pair::put\_Item

```cpp
void VectorOfVec_ranking_pair::put_Item( size_t                 index,
                                         dlib::vec_ranking_pair item );
AutoIt:
    $oVectorOfVec_ranking_pair.Item( $index ) = $item
```

### VectorOfVec\_ranking\_pair::size

```cpp
size_t VectorOfVec_ranking_pair::size();
AutoIt:
    $oVectorOfVec_ranking_pair.size() -> retval
```

### VectorOfVec\_ranking\_pair::slice

```cpp
VectorOfVec_ranking_pair VectorOfVec_ranking_pair::slice( size_t start = 0,
                                                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec_ranking_pair.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec\_ranking\_pair::sort

```cpp
void VectorOfVec_ranking_pair::sort( void*  comparator,
                                     size_t start = 0,
                                     size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec_ranking_pair.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec\_ranking\_pair::sort\_variant

```cpp
void VectorOfVec_ranking_pair::sort_variant( void*  comparator,
                                             size_t start = 0,
                                             size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec_ranking_pair.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec\_ranking\_pair::start

```cpp
void* VectorOfVec_ranking_pair::start();
AutoIt:
    $oVectorOfVec_ranking_pair.start() -> retval
```

## VectorOfSparse\_ranking\_pair

### VectorOfSparse\_ranking\_pair.Count

```cpp
size_t VectorOfSparse_ranking_pair::size()
AutoIt:
    [propget] $oVectorOfSparse_ranking_pair.Count
```

### VectorOfSparse\_ranking\_pair::create

```cpp
static VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfSparse_ranking_pair").create() -> <VectorOfSparse_ranking_pair object>
```

```cpp
static VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfSparse_ranking_pair").create( $size ) -> <VectorOfSparse_ranking_pair object>
```

```cpp
static VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::create( VectorOfSparse_ranking_pair other );
AutoIt:
    _Dlib_ObjCreate("VectorOfSparse_ranking_pair").create( $other ) -> <VectorOfSparse_ranking_pair object>
```

### VectorOfSparse\_ranking\_pair::Add

```cpp
void VectorOfSparse_ranking_pair::Add( dlib::sparse_ranking_pair value );
AutoIt:
    $oVectorOfSparse_ranking_pair.Add( $value ) -> None
```

### VectorOfSparse\_ranking\_pair::Items

```cpp
VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::Items();
AutoIt:
    $oVectorOfSparse_ranking_pair.Items() -> retval
```

### VectorOfSparse\_ranking\_pair::Keys

```cpp
std::vector<int> VectorOfSparse_ranking_pair::Keys();
AutoIt:
    $oVectorOfSparse_ranking_pair.Keys() -> retval
```

### VectorOfSparse\_ranking\_pair::Remove

```cpp
void VectorOfSparse_ranking_pair::Remove( size_t index );
AutoIt:
    $oVectorOfSparse_ranking_pair.Remove( $index ) -> None
```

### VectorOfSparse\_ranking\_pair::append

```cpp
void VectorOfSparse_ranking_pair::append( dlib::sparse_ranking_pair value );
AutoIt:
    $oVectorOfSparse_ranking_pair.append( $value ) -> None
```

### VectorOfSparse\_ranking\_pair::at

```cpp
dlib::sparse_ranking_pair VectorOfSparse_ranking_pair::at( size_t index );
AutoIt:
    $oVectorOfSparse_ranking_pair.at( $index ) -> retval
```

```cpp
void VectorOfSparse_ranking_pair::at( size_t                    index,
                                      dlib::sparse_ranking_pair value );
AutoIt:
    $oVectorOfSparse_ranking_pair.at( $index, $value ) -> None
```

### VectorOfSparse\_ranking\_pair::clear

```cpp
void VectorOfSparse_ranking_pair::clear();
AutoIt:
    $oVectorOfSparse_ranking_pair.clear() -> None
```

### VectorOfSparse\_ranking\_pair::empty

```cpp
bool VectorOfSparse_ranking_pair::empty();
AutoIt:
    $oVectorOfSparse_ranking_pair.empty() -> retval
```

### VectorOfSparse\_ranking\_pair::end

```cpp
void* VectorOfSparse_ranking_pair::end();
AutoIt:
    $oVectorOfSparse_ranking_pair.end() -> retval
```

### VectorOfSparse\_ranking\_pair::get\_Item

```cpp
dlib::sparse_ranking_pair VectorOfSparse_ranking_pair::get_Item( size_t index );
AutoIt:
    $oVectorOfSparse_ranking_pair.Item( $index ) -> retval
    $oVectorOfSparse_ranking_pair( $index ) -> retval
```

### VectorOfSparse\_ranking\_pair::get\_\_NewEnum

```cpp
IUnknown* VectorOfSparse_ranking_pair::get__NewEnum();
AutoIt:
    $oVectorOfSparse_ranking_pair._NewEnum() -> retval
```

### VectorOfSparse\_ranking\_pair::push\_back

```cpp
void VectorOfSparse_ranking_pair::push_back( dlib::sparse_ranking_pair value );
AutoIt:
    $oVectorOfSparse_ranking_pair.push_back( $value ) -> None
```

### VectorOfSparse\_ranking\_pair::push\_vector

```cpp
void VectorOfSparse_ranking_pair::push_vector( VectorOfSparse_ranking_pair other );
AutoIt:
    $oVectorOfSparse_ranking_pair.push_vector( $other ) -> None
```

```cpp
void VectorOfSparse_ranking_pair::push_vector( VectorOfSparse_ranking_pair other,
                                               size_t                      count,
                                               size_t                      start = 0 );
AutoIt:
    $oVectorOfSparse_ranking_pair.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfSparse\_ranking\_pair::put\_Item

```cpp
void VectorOfSparse_ranking_pair::put_Item( size_t                    index,
                                            dlib::sparse_ranking_pair item );
AutoIt:
    $oVectorOfSparse_ranking_pair.Item( $index ) = $item
```

### VectorOfSparse\_ranking\_pair::size

```cpp
size_t VectorOfSparse_ranking_pair::size();
AutoIt:
    $oVectorOfSparse_ranking_pair.size() -> retval
```

### VectorOfSparse\_ranking\_pair::slice

```cpp
VectorOfSparse_ranking_pair VectorOfSparse_ranking_pair::slice( size_t start = 0,
                                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSparse_ranking_pair.slice( [$start[, $count]] ) -> retval
```

### VectorOfSparse\_ranking\_pair::sort

```cpp
void VectorOfSparse_ranking_pair::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSparse_ranking_pair.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSparse\_ranking\_pair::sort\_variant

```cpp
void VectorOfSparse_ranking_pair::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSparse_ranking_pair.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSparse\_ranking\_pair::start

```cpp
void* VectorOfSparse_ranking_pair::start();
AutoIt:
    $oVectorOfSparse_ranking_pair.start() -> retval
```

## VectorOfDpoint

### VectorOfDpoint.Count

```cpp
size_t VectorOfDpoint::size()
AutoIt:
    [propget] $oVectorOfDpoint.Count
```

### VectorOfDpoint::create

```cpp
static VectorOfDpoint VectorOfDpoint::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfDpoint").create() -> <VectorOfDpoint object>
```

```cpp
static VectorOfDpoint VectorOfDpoint::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfDpoint").create( $size ) -> <VectorOfDpoint object>
```

```cpp
static VectorOfDpoint VectorOfDpoint::create( VectorOfDpoint other );
AutoIt:
    _Dlib_ObjCreate("VectorOfDpoint").create( $other ) -> <VectorOfDpoint object>
```

### VectorOfDpoint::Add

```cpp
void VectorOfDpoint::Add( dlib::dpoint value );
AutoIt:
    $oVectorOfDpoint.Add( $value ) -> None
```

### VectorOfDpoint::Items

```cpp
VectorOfDpoint VectorOfDpoint::Items();
AutoIt:
    $oVectorOfDpoint.Items() -> retval
```

### VectorOfDpoint::Keys

```cpp
std::vector<int> VectorOfDpoint::Keys();
AutoIt:
    $oVectorOfDpoint.Keys() -> retval
```

### VectorOfDpoint::Remove

```cpp
void VectorOfDpoint::Remove( size_t index );
AutoIt:
    $oVectorOfDpoint.Remove( $index ) -> None
```

### VectorOfDpoint::append

```cpp
void VectorOfDpoint::append( dlib::dpoint value );
AutoIt:
    $oVectorOfDpoint.append( $value ) -> None
```

### VectorOfDpoint::at

```cpp
dlib::dpoint VectorOfDpoint::at( size_t index );
AutoIt:
    $oVectorOfDpoint.at( $index ) -> retval
```

```cpp
void VectorOfDpoint::at( size_t       index,
                         dlib::dpoint value );
AutoIt:
    $oVectorOfDpoint.at( $index, $value ) -> None
```

### VectorOfDpoint::clear

```cpp
void VectorOfDpoint::clear();
AutoIt:
    $oVectorOfDpoint.clear() -> None
```

### VectorOfDpoint::empty

```cpp
bool VectorOfDpoint::empty();
AutoIt:
    $oVectorOfDpoint.empty() -> retval
```

### VectorOfDpoint::end

```cpp
void* VectorOfDpoint::end();
AutoIt:
    $oVectorOfDpoint.end() -> retval
```

### VectorOfDpoint::get\_Item

```cpp
dlib::dpoint VectorOfDpoint::get_Item( size_t index );
AutoIt:
    $oVectorOfDpoint.Item( $index ) -> retval
    $oVectorOfDpoint( $index ) -> retval
```

### VectorOfDpoint::get\_\_NewEnum

```cpp
IUnknown* VectorOfDpoint::get__NewEnum();
AutoIt:
    $oVectorOfDpoint._NewEnum() -> retval
```

### VectorOfDpoint::push\_back

```cpp
void VectorOfDpoint::push_back( dlib::dpoint value );
AutoIt:
    $oVectorOfDpoint.push_back( $value ) -> None
```

### VectorOfDpoint::push\_vector

```cpp
void VectorOfDpoint::push_vector( VectorOfDpoint other );
AutoIt:
    $oVectorOfDpoint.push_vector( $other ) -> None
```

```cpp
void VectorOfDpoint::push_vector( VectorOfDpoint other,
                                  size_t         count,
                                  size_t         start = 0 );
AutoIt:
    $oVectorOfDpoint.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfDpoint::put\_Item

```cpp
void VectorOfDpoint::put_Item( size_t       index,
                               dlib::dpoint item );
AutoIt:
    $oVectorOfDpoint.Item( $index ) = $item
```

### VectorOfDpoint::size

```cpp
size_t VectorOfDpoint::size();
AutoIt:
    $oVectorOfDpoint.size() -> retval
```

### VectorOfDpoint::slice

```cpp
VectorOfDpoint VectorOfDpoint::slice( size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDpoint.slice( [$start[, $count]] ) -> retval
```

### VectorOfDpoint::sort

```cpp
void VectorOfDpoint::sort( void*  comparator,
                           size_t start = 0,
                           size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDpoint.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDpoint::sort\_variant

```cpp
void VectorOfDpoint::sort_variant( void*  comparator,
                                   size_t start = 0,
                                   size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDpoint.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDpoint::start

```cpp
void* VectorOfDpoint::start();
AutoIt:
    $oVectorOfDpoint.start() -> retval
```

## VectorOfPoint

### VectorOfPoint.Count

```cpp
size_t VectorOfPoint::size()
AutoIt:
    [propget] $oVectorOfPoint.Count
```

### VectorOfPoint::create

```cpp
static VectorOfPoint VectorOfPoint::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfPoint").create() -> <VectorOfPoint object>
```

```cpp
static VectorOfPoint VectorOfPoint::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfPoint").create( $size ) -> <VectorOfPoint object>
```

```cpp
static VectorOfPoint VectorOfPoint::create( VectorOfPoint other );
AutoIt:
    _Dlib_ObjCreate("VectorOfPoint").create( $other ) -> <VectorOfPoint object>
```

### VectorOfPoint::Add

```cpp
void VectorOfPoint::Add( dlib::point value );
AutoIt:
    $oVectorOfPoint.Add( $value ) -> None
```

### VectorOfPoint::Items

```cpp
VectorOfPoint VectorOfPoint::Items();
AutoIt:
    $oVectorOfPoint.Items() -> retval
```

### VectorOfPoint::Keys

```cpp
std::vector<int> VectorOfPoint::Keys();
AutoIt:
    $oVectorOfPoint.Keys() -> retval
```

### VectorOfPoint::Remove

```cpp
void VectorOfPoint::Remove( size_t index );
AutoIt:
    $oVectorOfPoint.Remove( $index ) -> None
```

### VectorOfPoint::append

```cpp
void VectorOfPoint::append( dlib::point value );
AutoIt:
    $oVectorOfPoint.append( $value ) -> None
```

### VectorOfPoint::at

```cpp
dlib::point VectorOfPoint::at( size_t index );
AutoIt:
    $oVectorOfPoint.at( $index ) -> retval
```

```cpp
void VectorOfPoint::at( size_t      index,
                        dlib::point value );
AutoIt:
    $oVectorOfPoint.at( $index, $value ) -> None
```

### VectorOfPoint::clear

```cpp
void VectorOfPoint::clear();
AutoIt:
    $oVectorOfPoint.clear() -> None
```

### VectorOfPoint::empty

```cpp
bool VectorOfPoint::empty();
AutoIt:
    $oVectorOfPoint.empty() -> retval
```

### VectorOfPoint::end

```cpp
void* VectorOfPoint::end();
AutoIt:
    $oVectorOfPoint.end() -> retval
```

### VectorOfPoint::get\_Item

```cpp
dlib::point VectorOfPoint::get_Item( size_t index );
AutoIt:
    $oVectorOfPoint.Item( $index ) -> retval
    $oVectorOfPoint( $index ) -> retval
```

### VectorOfPoint::get\_\_NewEnum

```cpp
IUnknown* VectorOfPoint::get__NewEnum();
AutoIt:
    $oVectorOfPoint._NewEnum() -> retval
```

### VectorOfPoint::push\_back

```cpp
void VectorOfPoint::push_back( dlib::point value );
AutoIt:
    $oVectorOfPoint.push_back( $value ) -> None
```

### VectorOfPoint::push\_vector

```cpp
void VectorOfPoint::push_vector( VectorOfPoint other );
AutoIt:
    $oVectorOfPoint.push_vector( $other ) -> None
```

```cpp
void VectorOfPoint::push_vector( VectorOfPoint other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfPoint.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPoint::put\_Item

```cpp
void VectorOfPoint::put_Item( size_t      index,
                              dlib::point item );
AutoIt:
    $oVectorOfPoint.Item( $index ) = $item
```

### VectorOfPoint::size

```cpp
size_t VectorOfPoint::size();
AutoIt:
    $oVectorOfPoint.size() -> retval
```

### VectorOfPoint::slice

```cpp
VectorOfPoint VectorOfPoint::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPoint.slice( [$start[, $count]] ) -> retval
```

### VectorOfPoint::sort

```cpp
void VectorOfPoint::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPoint.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPoint::sort\_variant

```cpp
void VectorOfPoint::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPoint.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPoint::start

```cpp
void* VectorOfPoint::start();
AutoIt:
    $oVectorOfPoint.start() -> retval
```

## VectorOfVectorOfDouble

### VectorOfVectorOfDouble.Count

```cpp
size_t VectorOfVectorOfDouble::size()
AutoIt:
    [propget] $oVectorOfVectorOfDouble.Count
```

### VectorOfVectorOfDouble::create

```cpp
static VectorOfVectorOfDouble VectorOfVectorOfDouble::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfDouble").create() -> <VectorOfVectorOfDouble object>
```

```cpp
static VectorOfVectorOfDouble VectorOfVectorOfDouble::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfDouble").create( $size ) -> <VectorOfVectorOfDouble object>
```

```cpp
static VectorOfVectorOfDouble VectorOfVectorOfDouble::create( VectorOfVectorOfDouble other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfDouble").create( $other ) -> <VectorOfVectorOfDouble object>
```

### VectorOfVectorOfDouble::Add

```cpp
void VectorOfVectorOfDouble::Add( std::vector<double> value );
AutoIt:
    $oVectorOfVectorOfDouble.Add( $value ) -> None
```

### VectorOfVectorOfDouble::Items

```cpp
VectorOfVectorOfDouble VectorOfVectorOfDouble::Items();
AutoIt:
    $oVectorOfVectorOfDouble.Items() -> retval
```

### VectorOfVectorOfDouble::Keys

```cpp
std::vector<int> VectorOfVectorOfDouble::Keys();
AutoIt:
    $oVectorOfVectorOfDouble.Keys() -> retval
```

### VectorOfVectorOfDouble::Remove

```cpp
void VectorOfVectorOfDouble::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfDouble.Remove( $index ) -> None
```

### VectorOfVectorOfDouble::append

```cpp
void VectorOfVectorOfDouble::append( std::vector<double> value );
AutoIt:
    $oVectorOfVectorOfDouble.append( $value ) -> None
```

### VectorOfVectorOfDouble::at

```cpp
std::vector<double> VectorOfVectorOfDouble::at( size_t index );
AutoIt:
    $oVectorOfVectorOfDouble.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfDouble::at( size_t              index,
                                 std::vector<double> value );
AutoIt:
    $oVectorOfVectorOfDouble.at( $index, $value ) -> None
```

### VectorOfVectorOfDouble::clear

```cpp
void VectorOfVectorOfDouble::clear();
AutoIt:
    $oVectorOfVectorOfDouble.clear() -> None
```

### VectorOfVectorOfDouble::empty

```cpp
bool VectorOfVectorOfDouble::empty();
AutoIt:
    $oVectorOfVectorOfDouble.empty() -> retval
```

### VectorOfVectorOfDouble::end

```cpp
void* VectorOfVectorOfDouble::end();
AutoIt:
    $oVectorOfVectorOfDouble.end() -> retval
```

### VectorOfVectorOfDouble::get\_Item

```cpp
std::vector<double> VectorOfVectorOfDouble::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfDouble.Item( $index ) -> retval
    $oVectorOfVectorOfDouble( $index ) -> retval
```

### VectorOfVectorOfDouble::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfDouble::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfDouble._NewEnum() -> retval
```

### VectorOfVectorOfDouble::push\_back

```cpp
void VectorOfVectorOfDouble::push_back( std::vector<double> value );
AutoIt:
    $oVectorOfVectorOfDouble.push_back( $value ) -> None
```

### VectorOfVectorOfDouble::push\_vector

```cpp
void VectorOfVectorOfDouble::push_vector( VectorOfVectorOfDouble other );
AutoIt:
    $oVectorOfVectorOfDouble.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfDouble::push_vector( VectorOfVectorOfDouble other,
                                          size_t                 count,
                                          size_t                 start = 0 );
AutoIt:
    $oVectorOfVectorOfDouble.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfDouble::put\_Item

```cpp
void VectorOfVectorOfDouble::put_Item( size_t              index,
                                       std::vector<double> item );
AutoIt:
    $oVectorOfVectorOfDouble.Item( $index ) = $item
```

### VectorOfVectorOfDouble::size

```cpp
size_t VectorOfVectorOfDouble::size();
AutoIt:
    $oVectorOfVectorOfDouble.size() -> retval
```

### VectorOfVectorOfDouble::slice

```cpp
VectorOfVectorOfDouble VectorOfVectorOfDouble::slice( size_t start = 0,
                                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfDouble.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfDouble::sort

```cpp
void VectorOfVectorOfDouble::sort( void*  comparator,
                                   size_t start = 0,
                                   size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfDouble.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfDouble::sort\_variant

```cpp
void VectorOfVectorOfDouble::sort_variant( void*  comparator,
                                           size_t start = 0,
                                           size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfDouble.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfDouble::start

```cpp
void* VectorOfVectorOfDouble::start();
AutoIt:
    $oVectorOfVectorOfDouble.start() -> retval
```

## VectorOfMmod\_rect

### VectorOfMmod\_rect.Count

```cpp
size_t VectorOfMmod_rect::size()
AutoIt:
    [propget] $oVectorOfMmod_rect.Count
```

### VectorOfMmod\_rect::create

```cpp
static VectorOfMmod_rect VectorOfMmod_rect::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfMmod_rect").create() -> <VectorOfMmod_rect object>
```

```cpp
static VectorOfMmod_rect VectorOfMmod_rect::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfMmod_rect").create( $size ) -> <VectorOfMmod_rect object>
```

```cpp
static VectorOfMmod_rect VectorOfMmod_rect::create( VectorOfMmod_rect other );
AutoIt:
    _Dlib_ObjCreate("VectorOfMmod_rect").create( $other ) -> <VectorOfMmod_rect object>
```

### VectorOfMmod\_rect::Add

```cpp
void VectorOfMmod_rect::Add( dlib::mmod_rect value );
AutoIt:
    $oVectorOfMmod_rect.Add( $value ) -> None
```

### VectorOfMmod\_rect::Items

```cpp
VectorOfMmod_rect VectorOfMmod_rect::Items();
AutoIt:
    $oVectorOfMmod_rect.Items() -> retval
```

### VectorOfMmod\_rect::Keys

```cpp
std::vector<int> VectorOfMmod_rect::Keys();
AutoIt:
    $oVectorOfMmod_rect.Keys() -> retval
```

### VectorOfMmod\_rect::Remove

```cpp
void VectorOfMmod_rect::Remove( size_t index );
AutoIt:
    $oVectorOfMmod_rect.Remove( $index ) -> None
```

### VectorOfMmod\_rect::append

```cpp
void VectorOfMmod_rect::append( dlib::mmod_rect value );
AutoIt:
    $oVectorOfMmod_rect.append( $value ) -> None
```

### VectorOfMmod\_rect::at

```cpp
dlib::mmod_rect VectorOfMmod_rect::at( size_t index );
AutoIt:
    $oVectorOfMmod_rect.at( $index ) -> retval
```

```cpp
void VectorOfMmod_rect::at( size_t          index,
                            dlib::mmod_rect value );
AutoIt:
    $oVectorOfMmod_rect.at( $index, $value ) -> None
```

### VectorOfMmod\_rect::clear

```cpp
void VectorOfMmod_rect::clear();
AutoIt:
    $oVectorOfMmod_rect.clear() -> None
```

### VectorOfMmod\_rect::empty

```cpp
bool VectorOfMmod_rect::empty();
AutoIt:
    $oVectorOfMmod_rect.empty() -> retval
```

### VectorOfMmod\_rect::end

```cpp
void* VectorOfMmod_rect::end();
AutoIt:
    $oVectorOfMmod_rect.end() -> retval
```

### VectorOfMmod\_rect::get\_Item

```cpp
dlib::mmod_rect VectorOfMmod_rect::get_Item( size_t index );
AutoIt:
    $oVectorOfMmod_rect.Item( $index ) -> retval
    $oVectorOfMmod_rect( $index ) -> retval
```

### VectorOfMmod\_rect::get\_\_NewEnum

```cpp
IUnknown* VectorOfMmod_rect::get__NewEnum();
AutoIt:
    $oVectorOfMmod_rect._NewEnum() -> retval
```

### VectorOfMmod\_rect::push\_back

```cpp
void VectorOfMmod_rect::push_back( dlib::mmod_rect value );
AutoIt:
    $oVectorOfMmod_rect.push_back( $value ) -> None
```

### VectorOfMmod\_rect::push\_vector

```cpp
void VectorOfMmod_rect::push_vector( VectorOfMmod_rect other );
AutoIt:
    $oVectorOfMmod_rect.push_vector( $other ) -> None
```

```cpp
void VectorOfMmod_rect::push_vector( VectorOfMmod_rect other,
                                     size_t            count,
                                     size_t            start = 0 );
AutoIt:
    $oVectorOfMmod_rect.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfMmod\_rect::put\_Item

```cpp
void VectorOfMmod_rect::put_Item( size_t          index,
                                  dlib::mmod_rect item );
AutoIt:
    $oVectorOfMmod_rect.Item( $index ) = $item
```

### VectorOfMmod\_rect::size

```cpp
size_t VectorOfMmod_rect::size();
AutoIt:
    $oVectorOfMmod_rect.size() -> retval
```

### VectorOfMmod\_rect::slice

```cpp
VectorOfMmod_rect VectorOfMmod_rect::slice( size_t start = 0,
                                            size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfMmod_rect.slice( [$start[, $count]] ) -> retval
```

### VectorOfMmod\_rect::sort

```cpp
void VectorOfMmod_rect::sort( void*  comparator,
                              size_t start = 0,
                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfMmod_rect.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMmod\_rect::sort\_variant

```cpp
void VectorOfMmod_rect::sort_variant( void*  comparator,
                                      size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfMmod_rect.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfMmod\_rect::start

```cpp
void* VectorOfMmod_rect::start();
AutoIt:
    $oVectorOfMmod_rect.start() -> retval
```

## VectorOfVectorOfMmod\_rect

### VectorOfVectorOfMmod\_rect.Count

```cpp
size_t VectorOfVectorOfMmod_rect::size()
AutoIt:
    [propget] $oVectorOfVectorOfMmod_rect.Count
```

### VectorOfVectorOfMmod\_rect::create

```cpp
static VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfMmod_rect").create() -> <VectorOfVectorOfMmod_rect object>
```

```cpp
static VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfMmod_rect").create( $size ) -> <VectorOfVectorOfMmod_rect object>
```

```cpp
static VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::create( VectorOfVectorOfMmod_rect other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfMmod_rect").create( $other ) -> <VectorOfVectorOfMmod_rect object>
```

### VectorOfVectorOfMmod\_rect::Add

```cpp
void VectorOfVectorOfMmod_rect::Add( std::vector<dlib::mmod_rect> value );
AutoIt:
    $oVectorOfVectorOfMmod_rect.Add( $value ) -> None
```

### VectorOfVectorOfMmod\_rect::Items

```cpp
VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::Items();
AutoIt:
    $oVectorOfVectorOfMmod_rect.Items() -> retval
```

### VectorOfVectorOfMmod\_rect::Keys

```cpp
std::vector<int> VectorOfVectorOfMmod_rect::Keys();
AutoIt:
    $oVectorOfVectorOfMmod_rect.Keys() -> retval
```

### VectorOfVectorOfMmod\_rect::Remove

```cpp
void VectorOfVectorOfMmod_rect::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfMmod_rect.Remove( $index ) -> None
```

### VectorOfVectorOfMmod\_rect::append

```cpp
void VectorOfVectorOfMmod_rect::append( std::vector<dlib::mmod_rect> value );
AutoIt:
    $oVectorOfVectorOfMmod_rect.append( $value ) -> None
```

### VectorOfVectorOfMmod\_rect::at

```cpp
std::vector<dlib::mmod_rect> VectorOfVectorOfMmod_rect::at( size_t index );
AutoIt:
    $oVectorOfVectorOfMmod_rect.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfMmod_rect::at( size_t                       index,
                                    std::vector<dlib::mmod_rect> value );
AutoIt:
    $oVectorOfVectorOfMmod_rect.at( $index, $value ) -> None
```

### VectorOfVectorOfMmod\_rect::clear

```cpp
void VectorOfVectorOfMmod_rect::clear();
AutoIt:
    $oVectorOfVectorOfMmod_rect.clear() -> None
```

### VectorOfVectorOfMmod\_rect::empty

```cpp
bool VectorOfVectorOfMmod_rect::empty();
AutoIt:
    $oVectorOfVectorOfMmod_rect.empty() -> retval
```

### VectorOfVectorOfMmod\_rect::end

```cpp
void* VectorOfVectorOfMmod_rect::end();
AutoIt:
    $oVectorOfVectorOfMmod_rect.end() -> retval
```

### VectorOfVectorOfMmod\_rect::get\_Item

```cpp
std::vector<dlib::mmod_rect> VectorOfVectorOfMmod_rect::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfMmod_rect.Item( $index ) -> retval
    $oVectorOfVectorOfMmod_rect( $index ) -> retval
```

### VectorOfVectorOfMmod\_rect::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfMmod_rect::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfMmod_rect._NewEnum() -> retval
```

### VectorOfVectorOfMmod\_rect::push\_back

```cpp
void VectorOfVectorOfMmod_rect::push_back( std::vector<dlib::mmod_rect> value );
AutoIt:
    $oVectorOfVectorOfMmod_rect.push_back( $value ) -> None
```

### VectorOfVectorOfMmod\_rect::push\_vector

```cpp
void VectorOfVectorOfMmod_rect::push_vector( VectorOfVectorOfMmod_rect other );
AutoIt:
    $oVectorOfVectorOfMmod_rect.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfMmod_rect::push_vector( VectorOfVectorOfMmod_rect other,
                                             size_t                    count,
                                             size_t                    start = 0 );
AutoIt:
    $oVectorOfVectorOfMmod_rect.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfMmod\_rect::put\_Item

```cpp
void VectorOfVectorOfMmod_rect::put_Item( size_t                       index,
                                          std::vector<dlib::mmod_rect> item );
AutoIt:
    $oVectorOfVectorOfMmod_rect.Item( $index ) = $item
```

### VectorOfVectorOfMmod\_rect::size

```cpp
size_t VectorOfVectorOfMmod_rect::size();
AutoIt:
    $oVectorOfVectorOfMmod_rect.size() -> retval
```

### VectorOfVectorOfMmod\_rect::slice

```cpp
VectorOfVectorOfMmod_rect VectorOfVectorOfMmod_rect::slice( size_t start = 0,
                                                            size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfMmod_rect.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfMmod\_rect::sort

```cpp
void VectorOfVectorOfMmod_rect::sort( void*  comparator,
                                      size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfMmod_rect.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfMmod\_rect::sort\_variant

```cpp
void VectorOfVectorOfMmod_rect::sort_variant( void*  comparator,
                                              size_t start = 0,
                                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfMmod_rect.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfMmod\_rect::start

```cpp
void* VectorOfVectorOfMmod_rect::start();
AutoIt:
    $oVectorOfVectorOfMmod_rect.start() -> retval
```

## VectorOfSimple\_object\_detector\_com

### VectorOfSimple\_object\_detector\_com.Count

```cpp
size_t VectorOfSimple_object_detector_com::size()
AutoIt:
    [propget] $oVectorOfSimple_object_detector_com.Count
```

### VectorOfSimple\_object\_detector\_com::create

```cpp
static VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfSimple_object_detector_com").create() -> <VectorOfSimple_object_detector_com object>
```

```cpp
static VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfSimple_object_detector_com").create( $size ) -> <VectorOfSimple_object_detector_com object>
```

```cpp
static VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::create( VectorOfSimple_object_detector_com other );
AutoIt:
    _Dlib_ObjCreate("VectorOfSimple_object_detector_com").create( $other ) -> <VectorOfSimple_object_detector_com object>
```

### VectorOfSimple\_object\_detector\_com::Add

```cpp
void VectorOfSimple_object_detector_com::Add( dlib::simple_object_detector_com value );
AutoIt:
    $oVectorOfSimple_object_detector_com.Add( $value ) -> None
```

### VectorOfSimple\_object\_detector\_com::Items

```cpp
VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::Items();
AutoIt:
    $oVectorOfSimple_object_detector_com.Items() -> retval
```

### VectorOfSimple\_object\_detector\_com::Keys

```cpp
std::vector<int> VectorOfSimple_object_detector_com::Keys();
AutoIt:
    $oVectorOfSimple_object_detector_com.Keys() -> retval
```

### VectorOfSimple\_object\_detector\_com::Remove

```cpp
void VectorOfSimple_object_detector_com::Remove( size_t index );
AutoIt:
    $oVectorOfSimple_object_detector_com.Remove( $index ) -> None
```

### VectorOfSimple\_object\_detector\_com::append

```cpp
void VectorOfSimple_object_detector_com::append( dlib::simple_object_detector_com value );
AutoIt:
    $oVectorOfSimple_object_detector_com.append( $value ) -> None
```

### VectorOfSimple\_object\_detector\_com::at

```cpp
dlib::simple_object_detector_com VectorOfSimple_object_detector_com::at( size_t index );
AutoIt:
    $oVectorOfSimple_object_detector_com.at( $index ) -> retval
```

```cpp
void VectorOfSimple_object_detector_com::at( size_t                           index,
                                             dlib::simple_object_detector_com value );
AutoIt:
    $oVectorOfSimple_object_detector_com.at( $index, $value ) -> None
```

### VectorOfSimple\_object\_detector\_com::clear

```cpp
void VectorOfSimple_object_detector_com::clear();
AutoIt:
    $oVectorOfSimple_object_detector_com.clear() -> None
```

### VectorOfSimple\_object\_detector\_com::empty

```cpp
bool VectorOfSimple_object_detector_com::empty();
AutoIt:
    $oVectorOfSimple_object_detector_com.empty() -> retval
```

### VectorOfSimple\_object\_detector\_com::end

```cpp
void* VectorOfSimple_object_detector_com::end();
AutoIt:
    $oVectorOfSimple_object_detector_com.end() -> retval
```

### VectorOfSimple\_object\_detector\_com::get\_Item

```cpp
dlib::simple_object_detector_com VectorOfSimple_object_detector_com::get_Item( size_t index );
AutoIt:
    $oVectorOfSimple_object_detector_com.Item( $index ) -> retval
    $oVectorOfSimple_object_detector_com( $index ) -> retval
```

### VectorOfSimple\_object\_detector\_com::get\_\_NewEnum

```cpp
IUnknown* VectorOfSimple_object_detector_com::get__NewEnum();
AutoIt:
    $oVectorOfSimple_object_detector_com._NewEnum() -> retval
```

### VectorOfSimple\_object\_detector\_com::push\_back

```cpp
void VectorOfSimple_object_detector_com::push_back( dlib::simple_object_detector_com value );
AutoIt:
    $oVectorOfSimple_object_detector_com.push_back( $value ) -> None
```

### VectorOfSimple\_object\_detector\_com::push\_vector

```cpp
void VectorOfSimple_object_detector_com::push_vector( VectorOfSimple_object_detector_com other );
AutoIt:
    $oVectorOfSimple_object_detector_com.push_vector( $other ) -> None
```

```cpp
void VectorOfSimple_object_detector_com::push_vector( VectorOfSimple_object_detector_com other,
                                                      size_t                             count,
                                                      size_t                             start = 0 );
AutoIt:
    $oVectorOfSimple_object_detector_com.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfSimple\_object\_detector\_com::put\_Item

```cpp
void VectorOfSimple_object_detector_com::put_Item( size_t                           index,
                                                   dlib::simple_object_detector_com item );
AutoIt:
    $oVectorOfSimple_object_detector_com.Item( $index ) = $item
```

### VectorOfSimple\_object\_detector\_com::size

```cpp
size_t VectorOfSimple_object_detector_com::size();
AutoIt:
    $oVectorOfSimple_object_detector_com.size() -> retval
```

### VectorOfSimple\_object\_detector\_com::slice

```cpp
VectorOfSimple_object_detector_com VectorOfSimple_object_detector_com::slice( size_t start = 0,
                                                                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSimple_object_detector_com.slice( [$start[, $count]] ) -> retval
```

### VectorOfSimple\_object\_detector\_com::sort

```cpp
void VectorOfSimple_object_detector_com::sort( void*  comparator,
                                               size_t start = 0,
                                               size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSimple_object_detector_com.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSimple\_object\_detector\_com::sort\_variant

```cpp
void VectorOfSimple_object_detector_com::sort_variant( void*  comparator,
                                                       size_t start = 0,
                                                       size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSimple_object_detector_com.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSimple\_object\_detector\_com::start

```cpp
void* VectorOfSimple_object_detector_com::start();
AutoIt:
    $oVectorOfSimple_object_detector_com.start() -> retval
```

## VectorOfFhog\_object\_detector

### VectorOfFhog\_object\_detector.Count

```cpp
size_t VectorOfFhog_object_detector::size()
AutoIt:
    [propget] $oVectorOfFhog_object_detector.Count
```

### VectorOfFhog\_object\_detector::create

```cpp
static VectorOfFhog_object_detector VectorOfFhog_object_detector::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfFhog_object_detector").create() -> <VectorOfFhog_object_detector object>
```

```cpp
static VectorOfFhog_object_detector VectorOfFhog_object_detector::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfFhog_object_detector").create( $size ) -> <VectorOfFhog_object_detector object>
```

```cpp
static VectorOfFhog_object_detector VectorOfFhog_object_detector::create( VectorOfFhog_object_detector other );
AutoIt:
    _Dlib_ObjCreate("VectorOfFhog_object_detector").create( $other ) -> <VectorOfFhog_object_detector object>
```

### VectorOfFhog\_object\_detector::Add

```cpp
void VectorOfFhog_object_detector::Add( dlib::fhog_object_detector value );
AutoIt:
    $oVectorOfFhog_object_detector.Add( $value ) -> None
```

### VectorOfFhog\_object\_detector::Items

```cpp
VectorOfFhog_object_detector VectorOfFhog_object_detector::Items();
AutoIt:
    $oVectorOfFhog_object_detector.Items() -> retval
```

### VectorOfFhog\_object\_detector::Keys

```cpp
std::vector<int> VectorOfFhog_object_detector::Keys();
AutoIt:
    $oVectorOfFhog_object_detector.Keys() -> retval
```

### VectorOfFhog\_object\_detector::Remove

```cpp
void VectorOfFhog_object_detector::Remove( size_t index );
AutoIt:
    $oVectorOfFhog_object_detector.Remove( $index ) -> None
```

### VectorOfFhog\_object\_detector::append

```cpp
void VectorOfFhog_object_detector::append( dlib::fhog_object_detector value );
AutoIt:
    $oVectorOfFhog_object_detector.append( $value ) -> None
```

### VectorOfFhog\_object\_detector::at

```cpp
dlib::fhog_object_detector VectorOfFhog_object_detector::at( size_t index );
AutoIt:
    $oVectorOfFhog_object_detector.at( $index ) -> retval
```

```cpp
void VectorOfFhog_object_detector::at( size_t                     index,
                                       dlib::fhog_object_detector value );
AutoIt:
    $oVectorOfFhog_object_detector.at( $index, $value ) -> None
```

### VectorOfFhog\_object\_detector::clear

```cpp
void VectorOfFhog_object_detector::clear();
AutoIt:
    $oVectorOfFhog_object_detector.clear() -> None
```

### VectorOfFhog\_object\_detector::empty

```cpp
bool VectorOfFhog_object_detector::empty();
AutoIt:
    $oVectorOfFhog_object_detector.empty() -> retval
```

### VectorOfFhog\_object\_detector::end

```cpp
void* VectorOfFhog_object_detector::end();
AutoIt:
    $oVectorOfFhog_object_detector.end() -> retval
```

### VectorOfFhog\_object\_detector::get\_Item

```cpp
dlib::fhog_object_detector VectorOfFhog_object_detector::get_Item( size_t index );
AutoIt:
    $oVectorOfFhog_object_detector.Item( $index ) -> retval
    $oVectorOfFhog_object_detector( $index ) -> retval
```

### VectorOfFhog\_object\_detector::get\_\_NewEnum

```cpp
IUnknown* VectorOfFhog_object_detector::get__NewEnum();
AutoIt:
    $oVectorOfFhog_object_detector._NewEnum() -> retval
```

### VectorOfFhog\_object\_detector::push\_back

```cpp
void VectorOfFhog_object_detector::push_back( dlib::fhog_object_detector value );
AutoIt:
    $oVectorOfFhog_object_detector.push_back( $value ) -> None
```

### VectorOfFhog\_object\_detector::push\_vector

```cpp
void VectorOfFhog_object_detector::push_vector( VectorOfFhog_object_detector other );
AutoIt:
    $oVectorOfFhog_object_detector.push_vector( $other ) -> None
```

```cpp
void VectorOfFhog_object_detector::push_vector( VectorOfFhog_object_detector other,
                                                size_t                       count,
                                                size_t                       start = 0 );
AutoIt:
    $oVectorOfFhog_object_detector.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFhog\_object\_detector::put\_Item

```cpp
void VectorOfFhog_object_detector::put_Item( size_t                     index,
                                             dlib::fhog_object_detector item );
AutoIt:
    $oVectorOfFhog_object_detector.Item( $index ) = $item
```

### VectorOfFhog\_object\_detector::size

```cpp
size_t VectorOfFhog_object_detector::size();
AutoIt:
    $oVectorOfFhog_object_detector.size() -> retval
```

### VectorOfFhog\_object\_detector::slice

```cpp
VectorOfFhog_object_detector VectorOfFhog_object_detector::slice( size_t start = 0,
                                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFhog_object_detector.slice( [$start[, $count]] ) -> retval
```

### VectorOfFhog\_object\_detector::sort

```cpp
void VectorOfFhog_object_detector::sort( void*  comparator,
                                         size_t start = 0,
                                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFhog_object_detector.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFhog\_object\_detector::sort\_variant

```cpp
void VectorOfFhog_object_detector::sort_variant( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFhog_object_detector.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFhog\_object\_detector::start

```cpp
void* VectorOfFhog_object_detector::start();
AutoIt:
    $oVectorOfFhog_object_detector.start() -> retval
```

## VectorOfUchar

### VectorOfUchar.Count

```cpp
size_t VectorOfUchar::size()
AutoIt:
    [propget] $oVectorOfUchar.Count
```

### VectorOfUchar::create

```cpp
static VectorOfUchar VectorOfUchar::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfUchar").create() -> <VectorOfUchar object>
```

```cpp
static VectorOfUchar VectorOfUchar::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfUchar").create( $size ) -> <VectorOfUchar object>
```

```cpp
static VectorOfUchar VectorOfUchar::create( VectorOfUchar other );
AutoIt:
    _Dlib_ObjCreate("VectorOfUchar").create( $other ) -> <VectorOfUchar object>
```

### VectorOfUchar::Add

```cpp
void VectorOfUchar::Add( uchar value );
AutoIt:
    $oVectorOfUchar.Add( $value ) -> None
```

### VectorOfUchar::Items

```cpp
VectorOfUchar VectorOfUchar::Items();
AutoIt:
    $oVectorOfUchar.Items() -> retval
```

### VectorOfUchar::Keys

```cpp
std::vector<int> VectorOfUchar::Keys();
AutoIt:
    $oVectorOfUchar.Keys() -> retval
```

### VectorOfUchar::Remove

```cpp
void VectorOfUchar::Remove( size_t index );
AutoIt:
    $oVectorOfUchar.Remove( $index ) -> None
```

### VectorOfUchar::append

```cpp
void VectorOfUchar::append( uchar value );
AutoIt:
    $oVectorOfUchar.append( $value ) -> None
```

### VectorOfUchar::at

```cpp
uchar VectorOfUchar::at( size_t index );
AutoIt:
    $oVectorOfUchar.at( $index ) -> retval
```

```cpp
void VectorOfUchar::at( size_t index,
                        uchar  value );
AutoIt:
    $oVectorOfUchar.at( $index, $value ) -> None
```

### VectorOfUchar::clear

```cpp
void VectorOfUchar::clear();
AutoIt:
    $oVectorOfUchar.clear() -> None
```

### VectorOfUchar::empty

```cpp
bool VectorOfUchar::empty();
AutoIt:
    $oVectorOfUchar.empty() -> retval
```

### VectorOfUchar::end

```cpp
void* VectorOfUchar::end();
AutoIt:
    $oVectorOfUchar.end() -> retval
```

### VectorOfUchar::get\_Item

```cpp
uchar VectorOfUchar::get_Item( size_t index );
AutoIt:
    $oVectorOfUchar.Item( $index ) -> retval
    $oVectorOfUchar( $index ) -> retval
```

### VectorOfUchar::get\_\_NewEnum

```cpp
IUnknown* VectorOfUchar::get__NewEnum();
AutoIt:
    $oVectorOfUchar._NewEnum() -> retval
```

### VectorOfUchar::push\_back

```cpp
void VectorOfUchar::push_back( uchar value );
AutoIt:
    $oVectorOfUchar.push_back( $value ) -> None
```

### VectorOfUchar::push\_vector

```cpp
void VectorOfUchar::push_vector( VectorOfUchar other );
AutoIt:
    $oVectorOfUchar.push_vector( $other ) -> None
```

```cpp
void VectorOfUchar::push_vector( VectorOfUchar other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfUchar.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfUchar::put\_Item

```cpp
void VectorOfUchar::put_Item( size_t index,
                              uchar  item );
AutoIt:
    $oVectorOfUchar.Item( $index ) = $item
```

### VectorOfUchar::size

```cpp
size_t VectorOfUchar::size();
AutoIt:
    $oVectorOfUchar.size() -> retval
```

### VectorOfUchar::slice

```cpp
VectorOfUchar VectorOfUchar::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfUchar.slice( [$start[, $count]] ) -> retval
```

### VectorOfUchar::sort

```cpp
void VectorOfUchar::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfUchar.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfUchar::sort\_variant

```cpp
void VectorOfUchar::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfUchar.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfUchar::start

```cpp
void* VectorOfUchar::start();
AutoIt:
    $oVectorOfUchar.start() -> retval
```

## VectorOfInt

### VectorOfInt.Count

```cpp
size_t VectorOfInt::size()
AutoIt:
    [propget] $oVectorOfInt.Count
```

### VectorOfInt::create

```cpp
static VectorOfInt VectorOfInt::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfInt").create() -> <VectorOfInt object>
```

```cpp
static VectorOfInt VectorOfInt::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfInt").create( $size ) -> <VectorOfInt object>
```

```cpp
static VectorOfInt VectorOfInt::create( VectorOfInt other );
AutoIt:
    _Dlib_ObjCreate("VectorOfInt").create( $other ) -> <VectorOfInt object>
```

### VectorOfInt::Add

```cpp
void VectorOfInt::Add( int value );
AutoIt:
    $oVectorOfInt.Add( $value ) -> None
```

### VectorOfInt::Items

```cpp
VectorOfInt VectorOfInt::Items();
AutoIt:
    $oVectorOfInt.Items() -> retval
```

### VectorOfInt::Keys

```cpp
std::vector<int> VectorOfInt::Keys();
AutoIt:
    $oVectorOfInt.Keys() -> retval
```

### VectorOfInt::Remove

```cpp
void VectorOfInt::Remove( size_t index );
AutoIt:
    $oVectorOfInt.Remove( $index ) -> None
```

### VectorOfInt::append

```cpp
void VectorOfInt::append( int value );
AutoIt:
    $oVectorOfInt.append( $value ) -> None
```

### VectorOfInt::at

```cpp
int VectorOfInt::at( size_t index );
AutoIt:
    $oVectorOfInt.at( $index ) -> retval
```

```cpp
void VectorOfInt::at( size_t index,
                      int    value );
AutoIt:
    $oVectorOfInt.at( $index, $value ) -> None
```

### VectorOfInt::clear

```cpp
void VectorOfInt::clear();
AutoIt:
    $oVectorOfInt.clear() -> None
```

### VectorOfInt::empty

```cpp
bool VectorOfInt::empty();
AutoIt:
    $oVectorOfInt.empty() -> retval
```

### VectorOfInt::end

```cpp
void* VectorOfInt::end();
AutoIt:
    $oVectorOfInt.end() -> retval
```

### VectorOfInt::get\_Item

```cpp
int VectorOfInt::get_Item( size_t index );
AutoIt:
    $oVectorOfInt.Item( $index ) -> retval
    $oVectorOfInt( $index ) -> retval
```

### VectorOfInt::get\_\_NewEnum

```cpp
IUnknown* VectorOfInt::get__NewEnum();
AutoIt:
    $oVectorOfInt._NewEnum() -> retval
```

### VectorOfInt::push\_back

```cpp
void VectorOfInt::push_back( int value );
AutoIt:
    $oVectorOfInt.push_back( $value ) -> None
```

### VectorOfInt::push\_vector

```cpp
void VectorOfInt::push_vector( VectorOfInt other );
AutoIt:
    $oVectorOfInt.push_vector( $other ) -> None
```

```cpp
void VectorOfInt::push_vector( VectorOfInt other,
                               size_t      count,
                               size_t      start = 0 );
AutoIt:
    $oVectorOfInt.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfInt::put\_Item

```cpp
void VectorOfInt::put_Item( size_t index,
                            int    item );
AutoIt:
    $oVectorOfInt.Item( $index ) = $item
```

### VectorOfInt::size

```cpp
size_t VectorOfInt::size();
AutoIt:
    $oVectorOfInt.size() -> retval
```

### VectorOfInt::slice

```cpp
VectorOfInt VectorOfInt::slice( size_t start = 0,
                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfInt.slice( [$start[, $count]] ) -> retval
```

### VectorOfInt::sort

```cpp
void VectorOfInt::sort( void*  comparator,
                        size_t start = 0,
                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfInt.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfInt::sort\_variant

```cpp
void VectorOfInt::sort_variant( void*  comparator,
                                size_t start = 0,
                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfInt.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfInt::start

```cpp
void* VectorOfInt::start();
AutoIt:
    $oVectorOfInt.start() -> retval
```

## VectorOfFunction\_spec

### VectorOfFunction\_spec.Count

```cpp
size_t VectorOfFunction_spec::size()
AutoIt:
    [propget] $oVectorOfFunction_spec.Count
```

### VectorOfFunction\_spec::create

```cpp
static VectorOfFunction_spec VectorOfFunction_spec::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_spec").create() -> <VectorOfFunction_spec object>
```

```cpp
static VectorOfFunction_spec VectorOfFunction_spec::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_spec").create( $size ) -> <VectorOfFunction_spec object>
```

```cpp
static VectorOfFunction_spec VectorOfFunction_spec::create( VectorOfFunction_spec other );
AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_spec").create( $other ) -> <VectorOfFunction_spec object>
```

### VectorOfFunction\_spec::Add

```cpp
void VectorOfFunction_spec::Add( dlib::function_spec value );
AutoIt:
    $oVectorOfFunction_spec.Add( $value ) -> None
```

### VectorOfFunction\_spec::Items

```cpp
VectorOfFunction_spec VectorOfFunction_spec::Items();
AutoIt:
    $oVectorOfFunction_spec.Items() -> retval
```

### VectorOfFunction\_spec::Keys

```cpp
std::vector<int> VectorOfFunction_spec::Keys();
AutoIt:
    $oVectorOfFunction_spec.Keys() -> retval
```

### VectorOfFunction\_spec::Remove

```cpp
void VectorOfFunction_spec::Remove( size_t index );
AutoIt:
    $oVectorOfFunction_spec.Remove( $index ) -> None
```

### VectorOfFunction\_spec::append

```cpp
void VectorOfFunction_spec::append( dlib::function_spec value );
AutoIt:
    $oVectorOfFunction_spec.append( $value ) -> None
```

### VectorOfFunction\_spec::at

```cpp
dlib::function_spec VectorOfFunction_spec::at( size_t index );
AutoIt:
    $oVectorOfFunction_spec.at( $index ) -> retval
```

```cpp
void VectorOfFunction_spec::at( size_t              index,
                                dlib::function_spec value );
AutoIt:
    $oVectorOfFunction_spec.at( $index, $value ) -> None
```

### VectorOfFunction\_spec::clear

```cpp
void VectorOfFunction_spec::clear();
AutoIt:
    $oVectorOfFunction_spec.clear() -> None
```

### VectorOfFunction\_spec::empty

```cpp
bool VectorOfFunction_spec::empty();
AutoIt:
    $oVectorOfFunction_spec.empty() -> retval
```

### VectorOfFunction\_spec::end

```cpp
void* VectorOfFunction_spec::end();
AutoIt:
    $oVectorOfFunction_spec.end() -> retval
```

### VectorOfFunction\_spec::get\_Item

```cpp
dlib::function_spec VectorOfFunction_spec::get_Item( size_t index );
AutoIt:
    $oVectorOfFunction_spec.Item( $index ) -> retval
    $oVectorOfFunction_spec( $index ) -> retval
```

### VectorOfFunction\_spec::get\_\_NewEnum

```cpp
IUnknown* VectorOfFunction_spec::get__NewEnum();
AutoIt:
    $oVectorOfFunction_spec._NewEnum() -> retval
```

### VectorOfFunction\_spec::push\_back

```cpp
void VectorOfFunction_spec::push_back( dlib::function_spec value );
AutoIt:
    $oVectorOfFunction_spec.push_back( $value ) -> None
```

### VectorOfFunction\_spec::push\_vector

```cpp
void VectorOfFunction_spec::push_vector( VectorOfFunction_spec other );
AutoIt:
    $oVectorOfFunction_spec.push_vector( $other ) -> None
```

```cpp
void VectorOfFunction_spec::push_vector( VectorOfFunction_spec other,
                                         size_t                count,
                                         size_t                start = 0 );
AutoIt:
    $oVectorOfFunction_spec.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFunction\_spec::put\_Item

```cpp
void VectorOfFunction_spec::put_Item( size_t              index,
                                      dlib::function_spec item );
AutoIt:
    $oVectorOfFunction_spec.Item( $index ) = $item
```

### VectorOfFunction\_spec::size

```cpp
size_t VectorOfFunction_spec::size();
AutoIt:
    $oVectorOfFunction_spec.size() -> retval
```

### VectorOfFunction\_spec::slice

```cpp
VectorOfFunction_spec VectorOfFunction_spec::slice( size_t start = 0,
                                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFunction_spec.slice( [$start[, $count]] ) -> retval
```

### VectorOfFunction\_spec::sort

```cpp
void VectorOfFunction_spec::sort( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFunction_spec.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction\_spec::sort\_variant

```cpp
void VectorOfFunction_spec::sort_variant( void*  comparator,
                                          size_t start = 0,
                                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFunction_spec.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction\_spec::start

```cpp
void* VectorOfFunction_spec::start();
AutoIt:
    $oVectorOfFunction_spec.start() -> retval
```

## VectorOfFunction\_evaluation

### VectorOfFunction\_evaluation.Count

```cpp
size_t VectorOfFunction_evaluation::size()
AutoIt:
    [propget] $oVectorOfFunction_evaluation.Count
```

### VectorOfFunction\_evaluation::create

```cpp
static VectorOfFunction_evaluation VectorOfFunction_evaluation::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_evaluation").create() -> <VectorOfFunction_evaluation object>
```

```cpp
static VectorOfFunction_evaluation VectorOfFunction_evaluation::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_evaluation").create( $size ) -> <VectorOfFunction_evaluation object>
```

```cpp
static VectorOfFunction_evaluation VectorOfFunction_evaluation::create( VectorOfFunction_evaluation other );
AutoIt:
    _Dlib_ObjCreate("VectorOfFunction_evaluation").create( $other ) -> <VectorOfFunction_evaluation object>
```

### VectorOfFunction\_evaluation::Add

```cpp
void VectorOfFunction_evaluation::Add( dlib::function_evaluation value );
AutoIt:
    $oVectorOfFunction_evaluation.Add( $value ) -> None
```

### VectorOfFunction\_evaluation::Items

```cpp
VectorOfFunction_evaluation VectorOfFunction_evaluation::Items();
AutoIt:
    $oVectorOfFunction_evaluation.Items() -> retval
```

### VectorOfFunction\_evaluation::Keys

```cpp
std::vector<int> VectorOfFunction_evaluation::Keys();
AutoIt:
    $oVectorOfFunction_evaluation.Keys() -> retval
```

### VectorOfFunction\_evaluation::Remove

```cpp
void VectorOfFunction_evaluation::Remove( size_t index );
AutoIt:
    $oVectorOfFunction_evaluation.Remove( $index ) -> None
```

### VectorOfFunction\_evaluation::append

```cpp
void VectorOfFunction_evaluation::append( dlib::function_evaluation value );
AutoIt:
    $oVectorOfFunction_evaluation.append( $value ) -> None
```

### VectorOfFunction\_evaluation::at

```cpp
dlib::function_evaluation VectorOfFunction_evaluation::at( size_t index );
AutoIt:
    $oVectorOfFunction_evaluation.at( $index ) -> retval
```

```cpp
void VectorOfFunction_evaluation::at( size_t                    index,
                                      dlib::function_evaluation value );
AutoIt:
    $oVectorOfFunction_evaluation.at( $index, $value ) -> None
```

### VectorOfFunction\_evaluation::clear

```cpp
void VectorOfFunction_evaluation::clear();
AutoIt:
    $oVectorOfFunction_evaluation.clear() -> None
```

### VectorOfFunction\_evaluation::empty

```cpp
bool VectorOfFunction_evaluation::empty();
AutoIt:
    $oVectorOfFunction_evaluation.empty() -> retval
```

### VectorOfFunction\_evaluation::end

```cpp
void* VectorOfFunction_evaluation::end();
AutoIt:
    $oVectorOfFunction_evaluation.end() -> retval
```

### VectorOfFunction\_evaluation::get\_Item

```cpp
dlib::function_evaluation VectorOfFunction_evaluation::get_Item( size_t index );
AutoIt:
    $oVectorOfFunction_evaluation.Item( $index ) -> retval
    $oVectorOfFunction_evaluation( $index ) -> retval
```

### VectorOfFunction\_evaluation::get\_\_NewEnum

```cpp
IUnknown* VectorOfFunction_evaluation::get__NewEnum();
AutoIt:
    $oVectorOfFunction_evaluation._NewEnum() -> retval
```

### VectorOfFunction\_evaluation::push\_back

```cpp
void VectorOfFunction_evaluation::push_back( dlib::function_evaluation value );
AutoIt:
    $oVectorOfFunction_evaluation.push_back( $value ) -> None
```

### VectorOfFunction\_evaluation::push\_vector

```cpp
void VectorOfFunction_evaluation::push_vector( VectorOfFunction_evaluation other );
AutoIt:
    $oVectorOfFunction_evaluation.push_vector( $other ) -> None
```

```cpp
void VectorOfFunction_evaluation::push_vector( VectorOfFunction_evaluation other,
                                               size_t                      count,
                                               size_t                      start = 0 );
AutoIt:
    $oVectorOfFunction_evaluation.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFunction\_evaluation::put\_Item

```cpp
void VectorOfFunction_evaluation::put_Item( size_t                    index,
                                            dlib::function_evaluation item );
AutoIt:
    $oVectorOfFunction_evaluation.Item( $index ) = $item
```

### VectorOfFunction\_evaluation::size

```cpp
size_t VectorOfFunction_evaluation::size();
AutoIt:
    $oVectorOfFunction_evaluation.size() -> retval
```

### VectorOfFunction\_evaluation::slice

```cpp
VectorOfFunction_evaluation VectorOfFunction_evaluation::slice( size_t start = 0,
                                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFunction_evaluation.slice( [$start[, $count]] ) -> retval
```

### VectorOfFunction\_evaluation::sort

```cpp
void VectorOfFunction_evaluation::sort( void*  comparator,
                                        size_t start = 0,
                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFunction_evaluation.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction\_evaluation::sort\_variant

```cpp
void VectorOfFunction_evaluation::sort_variant( void*  comparator,
                                                size_t start = 0,
                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFunction_evaluation.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFunction\_evaluation::start

```cpp
void* VectorOfFunction_evaluation::start();
AutoIt:
    $oVectorOfFunction_evaluation.start() -> retval
```

## VectorOfVectorOfFunction\_evaluation

### VectorOfVectorOfFunction\_evaluation.Count

```cpp
size_t VectorOfVectorOfFunction_evaluation::size()
AutoIt:
    [propget] $oVectorOfVectorOfFunction_evaluation.Count
```

### VectorOfVectorOfFunction\_evaluation::create

```cpp
static VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFunction_evaluation").create() -> <VectorOfVectorOfFunction_evaluation object>
```

```cpp
static VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFunction_evaluation").create( $size ) -> <VectorOfVectorOfFunction_evaluation object>
```

```cpp
static VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::create( VectorOfVectorOfFunction_evaluation other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVectorOfFunction_evaluation").create( $other ) -> <VectorOfVectorOfFunction_evaluation object>
```

### VectorOfVectorOfFunction\_evaluation::Add

```cpp
void VectorOfVectorOfFunction_evaluation::Add( std::vector<dlib::function_evaluation> value );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Add( $value ) -> None
```

### VectorOfVectorOfFunction\_evaluation::Items

```cpp
VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::Items();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Items() -> retval
```

### VectorOfVectorOfFunction\_evaluation::Keys

```cpp
std::vector<int> VectorOfVectorOfFunction_evaluation::Keys();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Keys() -> retval
```

### VectorOfVectorOfFunction\_evaluation::Remove

```cpp
void VectorOfVectorOfFunction_evaluation::Remove( size_t index );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Remove( $index ) -> None
```

### VectorOfVectorOfFunction\_evaluation::append

```cpp
void VectorOfVectorOfFunction_evaluation::append( std::vector<dlib::function_evaluation> value );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.append( $value ) -> None
```

### VectorOfVectorOfFunction\_evaluation::at

```cpp
std::vector<dlib::function_evaluation> VectorOfVectorOfFunction_evaluation::at( size_t index );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.at( $index ) -> retval
```

```cpp
void VectorOfVectorOfFunction_evaluation::at( size_t                                 index,
                                              std::vector<dlib::function_evaluation> value );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.at( $index, $value ) -> None
```

### VectorOfVectorOfFunction\_evaluation::clear

```cpp
void VectorOfVectorOfFunction_evaluation::clear();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.clear() -> None
```

### VectorOfVectorOfFunction\_evaluation::empty

```cpp
bool VectorOfVectorOfFunction_evaluation::empty();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.empty() -> retval
```

### VectorOfVectorOfFunction\_evaluation::end

```cpp
void* VectorOfVectorOfFunction_evaluation::end();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.end() -> retval
```

### VectorOfVectorOfFunction\_evaluation::get\_Item

```cpp
std::vector<dlib::function_evaluation> VectorOfVectorOfFunction_evaluation::get_Item( size_t index );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Item( $index ) -> retval
    $oVectorOfVectorOfFunction_evaluation( $index ) -> retval
```

### VectorOfVectorOfFunction\_evaluation::get\_\_NewEnum

```cpp
IUnknown* VectorOfVectorOfFunction_evaluation::get__NewEnum();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation._NewEnum() -> retval
```

### VectorOfVectorOfFunction\_evaluation::push\_back

```cpp
void VectorOfVectorOfFunction_evaluation::push_back( std::vector<dlib::function_evaluation> value );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.push_back( $value ) -> None
```

### VectorOfVectorOfFunction\_evaluation::push\_vector

```cpp
void VectorOfVectorOfFunction_evaluation::push_vector( VectorOfVectorOfFunction_evaluation other );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.push_vector( $other ) -> None
```

```cpp
void VectorOfVectorOfFunction_evaluation::push_vector( VectorOfVectorOfFunction_evaluation other,
                                                       size_t                              count,
                                                       size_t                              start = 0 );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVectorOfFunction\_evaluation::put\_Item

```cpp
void VectorOfVectorOfFunction_evaluation::put_Item( size_t                                 index,
                                                    std::vector<dlib::function_evaluation> item );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.Item( $index ) = $item
```

### VectorOfVectorOfFunction\_evaluation::size

```cpp
size_t VectorOfVectorOfFunction_evaluation::size();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.size() -> retval
```

### VectorOfVectorOfFunction\_evaluation::slice

```cpp
VectorOfVectorOfFunction_evaluation VectorOfVectorOfFunction_evaluation::slice( size_t start = 0,
                                                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.slice( [$start[, $count]] ) -> retval
```

### VectorOfVectorOfFunction\_evaluation::sort

```cpp
void VectorOfVectorOfFunction_evaluation::sort( void*  comparator,
                                                size_t start = 0,
                                                size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFunction\_evaluation::sort\_variant

```cpp
void VectorOfVectorOfFunction_evaluation::sort_variant( void*  comparator,
                                                        size_t start = 0,
                                                        size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVectorOfFunction\_evaluation::start

```cpp
void* VectorOfVectorOfFunction_evaluation::start();
AutoIt:
    $oVectorOfVectorOfFunction_evaluation.start() -> retval
```

## VectorOfDrectangle

### VectorOfDrectangle.Count

```cpp
size_t VectorOfDrectangle::size()
AutoIt:
    [propget] $oVectorOfDrectangle.Count
```

### VectorOfDrectangle::create

```cpp
static VectorOfDrectangle VectorOfDrectangle::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfDrectangle").create() -> <VectorOfDrectangle object>
```

```cpp
static VectorOfDrectangle VectorOfDrectangle::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfDrectangle").create( $size ) -> <VectorOfDrectangle object>
```

```cpp
static VectorOfDrectangle VectorOfDrectangle::create( VectorOfDrectangle other );
AutoIt:
    _Dlib_ObjCreate("VectorOfDrectangle").create( $other ) -> <VectorOfDrectangle object>
```

### VectorOfDrectangle::Add

```cpp
void VectorOfDrectangle::Add( dlib::drectangle value );
AutoIt:
    $oVectorOfDrectangle.Add( $value ) -> None
```

### VectorOfDrectangle::Items

```cpp
VectorOfDrectangle VectorOfDrectangle::Items();
AutoIt:
    $oVectorOfDrectangle.Items() -> retval
```

### VectorOfDrectangle::Keys

```cpp
std::vector<int> VectorOfDrectangle::Keys();
AutoIt:
    $oVectorOfDrectangle.Keys() -> retval
```

### VectorOfDrectangle::Remove

```cpp
void VectorOfDrectangle::Remove( size_t index );
AutoIt:
    $oVectorOfDrectangle.Remove( $index ) -> None
```

### VectorOfDrectangle::append

```cpp
void VectorOfDrectangle::append( dlib::drectangle value );
AutoIt:
    $oVectorOfDrectangle.append( $value ) -> None
```

### VectorOfDrectangle::at

```cpp
dlib::drectangle VectorOfDrectangle::at( size_t index );
AutoIt:
    $oVectorOfDrectangle.at( $index ) -> retval
```

```cpp
void VectorOfDrectangle::at( size_t           index,
                             dlib::drectangle value );
AutoIt:
    $oVectorOfDrectangle.at( $index, $value ) -> None
```

### VectorOfDrectangle::clear

```cpp
void VectorOfDrectangle::clear();
AutoIt:
    $oVectorOfDrectangle.clear() -> None
```

### VectorOfDrectangle::empty

```cpp
bool VectorOfDrectangle::empty();
AutoIt:
    $oVectorOfDrectangle.empty() -> retval
```

### VectorOfDrectangle::end

```cpp
void* VectorOfDrectangle::end();
AutoIt:
    $oVectorOfDrectangle.end() -> retval
```

### VectorOfDrectangle::get\_Item

```cpp
dlib::drectangle VectorOfDrectangle::get_Item( size_t index );
AutoIt:
    $oVectorOfDrectangle.Item( $index ) -> retval
    $oVectorOfDrectangle( $index ) -> retval
```

### VectorOfDrectangle::get\_\_NewEnum

```cpp
IUnknown* VectorOfDrectangle::get__NewEnum();
AutoIt:
    $oVectorOfDrectangle._NewEnum() -> retval
```

### VectorOfDrectangle::push\_back

```cpp
void VectorOfDrectangle::push_back( dlib::drectangle value );
AutoIt:
    $oVectorOfDrectangle.push_back( $value ) -> None
```

### VectorOfDrectangle::push\_vector

```cpp
void VectorOfDrectangle::push_vector( VectorOfDrectangle other );
AutoIt:
    $oVectorOfDrectangle.push_vector( $other ) -> None
```

```cpp
void VectorOfDrectangle::push_vector( VectorOfDrectangle other,
                                      size_t             count,
                                      size_t             start = 0 );
AutoIt:
    $oVectorOfDrectangle.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfDrectangle::put\_Item

```cpp
void VectorOfDrectangle::put_Item( size_t           index,
                                   dlib::drectangle item );
AutoIt:
    $oVectorOfDrectangle.Item( $index ) = $item
```

### VectorOfDrectangle::size

```cpp
size_t VectorOfDrectangle::size();
AutoIt:
    $oVectorOfDrectangle.size() -> retval
```

### VectorOfDrectangle::slice

```cpp
VectorOfDrectangle VectorOfDrectangle::slice( size_t start = 0,
                                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDrectangle.slice( [$start[, $count]] ) -> retval
```

### VectorOfDrectangle::sort

```cpp
void VectorOfDrectangle::sort( void*  comparator,
                               size_t start = 0,
                               size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDrectangle.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDrectangle::sort\_variant

```cpp
void VectorOfDrectangle::sort_variant( void*  comparator,
                                       size_t start = 0,
                                       size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfDrectangle.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfDrectangle::start

```cpp
void* VectorOfDrectangle::start();
AutoIt:
    $oVectorOfDrectangle.start() -> retval
```

## VectorOfImage\_window\_keyboard\_state\_masks

### VectorOfImage\_window\_keyboard\_state\_masks.Count

```cpp
size_t VectorOfImage_window_keyboard_state_masks::size()
AutoIt:
    [propget] $oVectorOfImage_window_keyboard_state_masks.Count
```

### VectorOfImage\_window\_keyboard\_state\_masks::create

```cpp
static VectorOfImage_window_keyboard_state_masks VectorOfImage_window_keyboard_state_masks::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_window_keyboard_state_masks").create() -> <VectorOfImage_window_keyboard_state_masks object>
```

```cpp
static VectorOfImage_window_keyboard_state_masks VectorOfImage_window_keyboard_state_masks::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_window_keyboard_state_masks").create( $size ) -> <VectorOfImage_window_keyboard_state_masks object>
```

```cpp
static VectorOfImage_window_keyboard_state_masks VectorOfImage_window_keyboard_state_masks::create( VectorOfImage_window_keyboard_state_masks other );
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_window_keyboard_state_masks").create( $other ) -> <VectorOfImage_window_keyboard_state_masks object>
```

### VectorOfImage\_window\_keyboard\_state\_masks::Add

```cpp
void VectorOfImage_window_keyboard_state_masks::Add( dlib::image_window::keyboard_state_masks value );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.Add( $value ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::Items

```cpp
VectorOfImage_window_keyboard_state_masks VectorOfImage_window_keyboard_state_masks::Items();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.Items() -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::Keys

```cpp
std::vector<int> VectorOfImage_window_keyboard_state_masks::Keys();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.Keys() -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::Remove

```cpp
void VectorOfImage_window_keyboard_state_masks::Remove( size_t index );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.Remove( $index ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::append

```cpp
void VectorOfImage_window_keyboard_state_masks::append( dlib::image_window::keyboard_state_masks value );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.append( $value ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::at

```cpp
dlib::image_window::keyboard_state_masks VectorOfImage_window_keyboard_state_masks::at( size_t index );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.at( $index ) -> retval
```

```cpp
void VectorOfImage_window_keyboard_state_masks::at( size_t                                   index,
                                                    dlib::image_window::keyboard_state_masks value );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.at( $index, $value ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::clear

```cpp
void VectorOfImage_window_keyboard_state_masks::clear();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.clear() -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::empty

```cpp
bool VectorOfImage_window_keyboard_state_masks::empty();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.empty() -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::end

```cpp
void* VectorOfImage_window_keyboard_state_masks::end();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.end() -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::get\_Item

```cpp
dlib::image_window::keyboard_state_masks VectorOfImage_window_keyboard_state_masks::get_Item( size_t index );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.Item( $index ) -> retval
    $oVectorOfImage_window_keyboard_state_masks( $index ) -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::get\_\_NewEnum

```cpp
IUnknown* VectorOfImage_window_keyboard_state_masks::get__NewEnum();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks._NewEnum() -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::push\_back

```cpp
void VectorOfImage_window_keyboard_state_masks::push_back( dlib::image_window::keyboard_state_masks value );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.push_back( $value ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::push\_vector

```cpp
void VectorOfImage_window_keyboard_state_masks::push_vector( VectorOfImage_window_keyboard_state_masks other );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.push_vector( $other ) -> None
```

```cpp
void VectorOfImage_window_keyboard_state_masks::push_vector( VectorOfImage_window_keyboard_state_masks other,
                                                             size_t                                    count,
                                                             size_t                                    start = 0 );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::put\_Item

```cpp
void VectorOfImage_window_keyboard_state_masks::put_Item( size_t                                   index,
                                                          dlib::image_window::keyboard_state_masks item );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.Item( $index ) = $item
```

### VectorOfImage\_window\_keyboard\_state\_masks::size

```cpp
size_t VectorOfImage_window_keyboard_state_masks::size();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.size() -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::slice

```cpp
VectorOfImage_window_keyboard_state_masks VectorOfImage_window_keyboard_state_masks::slice( size_t start = 0,
                                                                                            size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.slice( [$start[, $count]] ) -> retval
```

### VectorOfImage\_window\_keyboard\_state\_masks::sort

```cpp
void VectorOfImage_window_keyboard_state_masks::sort( void*  comparator,
                                                      size_t start = 0,
                                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::sort\_variant

```cpp
void VectorOfImage_window_keyboard_state_masks::sort_variant( void*  comparator,
                                                              size_t start = 0,
                                                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage\_window\_keyboard\_state\_masks::start

```cpp
void* VectorOfImage_window_keyboard_state_masks::start();
AutoIt:
    $oVectorOfImage_window_keyboard_state_masks.start() -> retval
```

## MapOfStringAndPoint

### MapOfStringAndPoint::create

```cpp
static MapOfStringAndPoint MapOfStringAndPoint::create();
AutoIt:
    _Dlib_ObjCreate("MapOfStringAndPoint").create() -> <MapOfStringAndPoint object>
```

```cpp
static std::shared_ptr<MapOfStringAndPoint> MapOfStringAndPoint::create( std::vector<std::pair<std::string, dlib::point>> pairs );
AutoIt:
    _Dlib_ObjCreate("MapOfStringAndPoint").create( $pairs ) -> retval
```

### MapOfStringAndPoint::Add

```cpp
void MapOfStringAndPoint::Add( std::string key,
                               dlib::point value );
AutoIt:
    $oMapOfStringAndPoint.Add( $key, $value ) -> None
```

### MapOfStringAndPoint::Get

```cpp
dlib::point MapOfStringAndPoint::Get( std::string key );
AutoIt:
    $oMapOfStringAndPoint.Get( $key ) -> retval
```

### MapOfStringAndPoint::Items

```cpp
std::vector<dlib::point> MapOfStringAndPoint::Items();
AutoIt:
    $oMapOfStringAndPoint.Items() -> retval
```

### MapOfStringAndPoint::Keys

```cpp
std::vector<std::string> MapOfStringAndPoint::Keys();
AutoIt:
    $oMapOfStringAndPoint.Keys() -> retval
```

### MapOfStringAndPoint::Remove

```cpp
size_t MapOfStringAndPoint::Remove( std::string key );
AutoIt:
    $oMapOfStringAndPoint.Remove( $key ) -> retval
```

### MapOfStringAndPoint::clear

```cpp
void MapOfStringAndPoint::clear();
AutoIt:
    $oMapOfStringAndPoint.clear() -> None
```

### MapOfStringAndPoint::contains

```cpp
bool MapOfStringAndPoint::contains( std::string key );
AutoIt:
    $oMapOfStringAndPoint.contains( $key ) -> retval
```

### MapOfStringAndPoint::count

```cpp
size_t MapOfStringAndPoint::count( std::string key );
AutoIt:
    $oMapOfStringAndPoint.count( $key ) -> retval
```

### MapOfStringAndPoint::empty

```cpp
bool MapOfStringAndPoint::empty();
AutoIt:
    $oMapOfStringAndPoint.empty() -> retval
```

### MapOfStringAndPoint::erase

```cpp
size_t MapOfStringAndPoint::erase( std::string key );
AutoIt:
    $oMapOfStringAndPoint.erase( $key ) -> retval
```

### MapOfStringAndPoint::get\_Item

```cpp
dlib::point MapOfStringAndPoint::get_Item( std::string key );
AutoIt:
    $oMapOfStringAndPoint.Item( $key ) -> retval
    $oMapOfStringAndPoint( $key ) -> retval
```

### MapOfStringAndPoint::get\_\_NewEnum

```cpp
IUnknown* MapOfStringAndPoint::get__NewEnum();
AutoIt:
    $oMapOfStringAndPoint._NewEnum() -> retval
```

### MapOfStringAndPoint::has

```cpp
bool MapOfStringAndPoint::has( std::string key );
AutoIt:
    $oMapOfStringAndPoint.has( $key ) -> retval
```

### MapOfStringAndPoint::max\_size

```cpp
size_t MapOfStringAndPoint::max_size();
AutoIt:
    $oMapOfStringAndPoint.max_size() -> retval
```

### MapOfStringAndPoint::merge

```cpp
void MapOfStringAndPoint::merge( MapOfStringAndPoint other );
AutoIt:
    $oMapOfStringAndPoint.merge( $other ) -> None
```

### MapOfStringAndPoint::put\_Item

```cpp
void MapOfStringAndPoint::put_Item( std::string key,
                                    dlib::point item );
AutoIt:
    $oMapOfStringAndPoint.Item( $key ) = $item
```

### MapOfStringAndPoint::size

```cpp
size_t MapOfStringAndPoint::size();
AutoIt:
    $oMapOfStringAndPoint.size() -> retval
```

## VectorOfPairOfStringAndPoint

### VectorOfPairOfStringAndPoint.Count

```cpp
size_t VectorOfPairOfStringAndPoint::size()
AutoIt:
    [propget] $oVectorOfPairOfStringAndPoint.Count
```

### VectorOfPairOfStringAndPoint::create

```cpp
static VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfStringAndPoint").create() -> <VectorOfPairOfStringAndPoint object>
```

```cpp
static VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfStringAndPoint").create( $size ) -> <VectorOfPairOfStringAndPoint object>
```

```cpp
static VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::create( VectorOfPairOfStringAndPoint other );
AutoIt:
    _Dlib_ObjCreate("VectorOfPairOfStringAndPoint").create( $other ) -> <VectorOfPairOfStringAndPoint object>
```

### VectorOfPairOfStringAndPoint::Add

```cpp
void VectorOfPairOfStringAndPoint::Add( std::pair<std::string, dlib::point> value );
AutoIt:
    $oVectorOfPairOfStringAndPoint.Add( $value ) -> None
```

### VectorOfPairOfStringAndPoint::Items

```cpp
VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::Items();
AutoIt:
    $oVectorOfPairOfStringAndPoint.Items() -> retval
```

### VectorOfPairOfStringAndPoint::Keys

```cpp
std::vector<int> VectorOfPairOfStringAndPoint::Keys();
AutoIt:
    $oVectorOfPairOfStringAndPoint.Keys() -> retval
```

### VectorOfPairOfStringAndPoint::Remove

```cpp
void VectorOfPairOfStringAndPoint::Remove( size_t index );
AutoIt:
    $oVectorOfPairOfStringAndPoint.Remove( $index ) -> None
```

### VectorOfPairOfStringAndPoint::append

```cpp
void VectorOfPairOfStringAndPoint::append( std::pair<std::string, dlib::point> value );
AutoIt:
    $oVectorOfPairOfStringAndPoint.append( $value ) -> None
```

### VectorOfPairOfStringAndPoint::at

```cpp
std::pair<std::string, dlib::point> VectorOfPairOfStringAndPoint::at( size_t index );
AutoIt:
    $oVectorOfPairOfStringAndPoint.at( $index ) -> retval
```

```cpp
void VectorOfPairOfStringAndPoint::at( size_t                              index,
                                       std::pair<std::string, dlib::point> value );
AutoIt:
    $oVectorOfPairOfStringAndPoint.at( $index, $value ) -> None
```

### VectorOfPairOfStringAndPoint::clear

```cpp
void VectorOfPairOfStringAndPoint::clear();
AutoIt:
    $oVectorOfPairOfStringAndPoint.clear() -> None
```

### VectorOfPairOfStringAndPoint::empty

```cpp
bool VectorOfPairOfStringAndPoint::empty();
AutoIt:
    $oVectorOfPairOfStringAndPoint.empty() -> retval
```

### VectorOfPairOfStringAndPoint::end

```cpp
void* VectorOfPairOfStringAndPoint::end();
AutoIt:
    $oVectorOfPairOfStringAndPoint.end() -> retval
```

### VectorOfPairOfStringAndPoint::get\_Item

```cpp
std::pair<std::string, dlib::point> VectorOfPairOfStringAndPoint::get_Item( size_t index );
AutoIt:
    $oVectorOfPairOfStringAndPoint.Item( $index ) -> retval
    $oVectorOfPairOfStringAndPoint( $index ) -> retval
```

### VectorOfPairOfStringAndPoint::get\_\_NewEnum

```cpp
IUnknown* VectorOfPairOfStringAndPoint::get__NewEnum();
AutoIt:
    $oVectorOfPairOfStringAndPoint._NewEnum() -> retval
```

### VectorOfPairOfStringAndPoint::push\_back

```cpp
void VectorOfPairOfStringAndPoint::push_back( std::pair<std::string, dlib::point> value );
AutoIt:
    $oVectorOfPairOfStringAndPoint.push_back( $value ) -> None
```

### VectorOfPairOfStringAndPoint::push\_vector

```cpp
void VectorOfPairOfStringAndPoint::push_vector( VectorOfPairOfStringAndPoint other );
AutoIt:
    $oVectorOfPairOfStringAndPoint.push_vector( $other ) -> None
```

```cpp
void VectorOfPairOfStringAndPoint::push_vector( VectorOfPairOfStringAndPoint other,
                                                size_t                       count,
                                                size_t                       start = 0 );
AutoIt:
    $oVectorOfPairOfStringAndPoint.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfPairOfStringAndPoint::put\_Item

```cpp
void VectorOfPairOfStringAndPoint::put_Item( size_t                              index,
                                             std::pair<std::string, dlib::point> item );
AutoIt:
    $oVectorOfPairOfStringAndPoint.Item( $index ) = $item
```

### VectorOfPairOfStringAndPoint::size

```cpp
size_t VectorOfPairOfStringAndPoint::size();
AutoIt:
    $oVectorOfPairOfStringAndPoint.size() -> retval
```

### VectorOfPairOfStringAndPoint::slice

```cpp
VectorOfPairOfStringAndPoint VectorOfPairOfStringAndPoint::slice( size_t start = 0,
                                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfStringAndPoint.slice( [$start[, $count]] ) -> retval
```

### VectorOfPairOfStringAndPoint::sort

```cpp
void VectorOfPairOfStringAndPoint::sort( void*  comparator,
                                         size_t start = 0,
                                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfStringAndPoint.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfStringAndPoint::sort\_variant

```cpp
void VectorOfPairOfStringAndPoint::sort_variant( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfPairOfStringAndPoint.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfPairOfStringAndPoint::start

```cpp
void* VectorOfPairOfStringAndPoint::start();
AutoIt:
    $oVectorOfPairOfStringAndPoint.start() -> retval
```

## VectorOfImage\_dataset\_metadata\_box

### VectorOfImage\_dataset\_metadata\_box.Count

```cpp
size_t VectorOfImage_dataset_metadata_box::size()
AutoIt:
    [propget] $oVectorOfImage_dataset_metadata_box.Count
```

### VectorOfImage\_dataset\_metadata\_box::create

```cpp
static VectorOfImage_dataset_metadata_box VectorOfImage_dataset_metadata_box::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_dataset_metadata_box").create() -> <VectorOfImage_dataset_metadata_box object>
```

```cpp
static VectorOfImage_dataset_metadata_box VectorOfImage_dataset_metadata_box::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_dataset_metadata_box").create( $size ) -> <VectorOfImage_dataset_metadata_box object>
```

```cpp
static VectorOfImage_dataset_metadata_box VectorOfImage_dataset_metadata_box::create( VectorOfImage_dataset_metadata_box other );
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_dataset_metadata_box").create( $other ) -> <VectorOfImage_dataset_metadata_box object>
```

### VectorOfImage\_dataset\_metadata\_box::Add

```cpp
void VectorOfImage_dataset_metadata_box::Add( dlib::image_dataset_metadata::box value );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.Add( $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::Items

```cpp
VectorOfImage_dataset_metadata_box VectorOfImage_dataset_metadata_box::Items();
AutoIt:
    $oVectorOfImage_dataset_metadata_box.Items() -> retval
```

### VectorOfImage\_dataset\_metadata\_box::Keys

```cpp
std::vector<int> VectorOfImage_dataset_metadata_box::Keys();
AutoIt:
    $oVectorOfImage_dataset_metadata_box.Keys() -> retval
```

### VectorOfImage\_dataset\_metadata\_box::Remove

```cpp
void VectorOfImage_dataset_metadata_box::Remove( size_t index );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.Remove( $index ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::append

```cpp
void VectorOfImage_dataset_metadata_box::append( dlib::image_dataset_metadata::box value );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.append( $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::at

```cpp
dlib::image_dataset_metadata::box VectorOfImage_dataset_metadata_box::at( size_t index );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.at( $index ) -> retval
```

```cpp
void VectorOfImage_dataset_metadata_box::at( size_t                            index,
                                             dlib::image_dataset_metadata::box value );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.at( $index, $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::clear

```cpp
void VectorOfImage_dataset_metadata_box::clear();
AutoIt:
    $oVectorOfImage_dataset_metadata_box.clear() -> None
```

### VectorOfImage\_dataset\_metadata\_box::empty

```cpp
bool VectorOfImage_dataset_metadata_box::empty();
AutoIt:
    $oVectorOfImage_dataset_metadata_box.empty() -> retval
```

### VectorOfImage\_dataset\_metadata\_box::end

```cpp
void* VectorOfImage_dataset_metadata_box::end();
AutoIt:
    $oVectorOfImage_dataset_metadata_box.end() -> retval
```

### VectorOfImage\_dataset\_metadata\_box::get\_Item

```cpp
dlib::image_dataset_metadata::box VectorOfImage_dataset_metadata_box::get_Item( size_t index );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.Item( $index ) -> retval
    $oVectorOfImage_dataset_metadata_box( $index ) -> retval
```

### VectorOfImage\_dataset\_metadata\_box::get\_\_NewEnum

```cpp
IUnknown* VectorOfImage_dataset_metadata_box::get__NewEnum();
AutoIt:
    $oVectorOfImage_dataset_metadata_box._NewEnum() -> retval
```

### VectorOfImage\_dataset\_metadata\_box::push\_back

```cpp
void VectorOfImage_dataset_metadata_box::push_back( dlib::image_dataset_metadata::box value );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.push_back( $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::push\_vector

```cpp
void VectorOfImage_dataset_metadata_box::push_vector( VectorOfImage_dataset_metadata_box other );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.push_vector( $other ) -> None
```

```cpp
void VectorOfImage_dataset_metadata_box::push_vector( VectorOfImage_dataset_metadata_box other,
                                                      size_t                             count,
                                                      size_t                             start = 0 );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::put\_Item

```cpp
void VectorOfImage_dataset_metadata_box::put_Item( size_t                            index,
                                                   dlib::image_dataset_metadata::box item );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.Item( $index ) = $item
```

### VectorOfImage\_dataset\_metadata\_box::size

```cpp
size_t VectorOfImage_dataset_metadata_box::size();
AutoIt:
    $oVectorOfImage_dataset_metadata_box.size() -> retval
```

### VectorOfImage\_dataset\_metadata\_box::slice

```cpp
VectorOfImage_dataset_metadata_box VectorOfImage_dataset_metadata_box::slice( size_t start = 0,
                                                                              size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.slice( [$start[, $count]] ) -> retval
```

### VectorOfImage\_dataset\_metadata\_box::sort

```cpp
void VectorOfImage_dataset_metadata_box::sort( void*  comparator,
                                               size_t start = 0,
                                               size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::sort\_variant

```cpp
void VectorOfImage_dataset_metadata_box::sort_variant( void*  comparator,
                                                       size_t start = 0,
                                                       size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_dataset_metadata_box.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage\_dataset\_metadata\_box::start

```cpp
void* VectorOfImage_dataset_metadata_box::start();
AutoIt:
    $oVectorOfImage_dataset_metadata_box.start() -> retval
```

## VectorOfImage\_dataset\_metadata\_image

### VectorOfImage\_dataset\_metadata\_image.Count

```cpp
size_t VectorOfImage_dataset_metadata_image::size()
AutoIt:
    [propget] $oVectorOfImage_dataset_metadata_image.Count
```

### VectorOfImage\_dataset\_metadata\_image::create

```cpp
static VectorOfImage_dataset_metadata_image VectorOfImage_dataset_metadata_image::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_dataset_metadata_image").create() -> <VectorOfImage_dataset_metadata_image object>
```

```cpp
static VectorOfImage_dataset_metadata_image VectorOfImage_dataset_metadata_image::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_dataset_metadata_image").create( $size ) -> <VectorOfImage_dataset_metadata_image object>
```

```cpp
static VectorOfImage_dataset_metadata_image VectorOfImage_dataset_metadata_image::create( VectorOfImage_dataset_metadata_image other );
AutoIt:
    _Dlib_ObjCreate("VectorOfImage_dataset_metadata_image").create( $other ) -> <VectorOfImage_dataset_metadata_image object>
```

### VectorOfImage\_dataset\_metadata\_image::Add

```cpp
void VectorOfImage_dataset_metadata_image::Add( dlib::image_dataset_metadata::image value );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.Add( $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::Items

```cpp
VectorOfImage_dataset_metadata_image VectorOfImage_dataset_metadata_image::Items();
AutoIt:
    $oVectorOfImage_dataset_metadata_image.Items() -> retval
```

### VectorOfImage\_dataset\_metadata\_image::Keys

```cpp
std::vector<int> VectorOfImage_dataset_metadata_image::Keys();
AutoIt:
    $oVectorOfImage_dataset_metadata_image.Keys() -> retval
```

### VectorOfImage\_dataset\_metadata\_image::Remove

```cpp
void VectorOfImage_dataset_metadata_image::Remove( size_t index );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.Remove( $index ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::append

```cpp
void VectorOfImage_dataset_metadata_image::append( dlib::image_dataset_metadata::image value );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.append( $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::at

```cpp
dlib::image_dataset_metadata::image VectorOfImage_dataset_metadata_image::at( size_t index );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.at( $index ) -> retval
```

```cpp
void VectorOfImage_dataset_metadata_image::at( size_t                              index,
                                               dlib::image_dataset_metadata::image value );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.at( $index, $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::clear

```cpp
void VectorOfImage_dataset_metadata_image::clear();
AutoIt:
    $oVectorOfImage_dataset_metadata_image.clear() -> None
```

### VectorOfImage\_dataset\_metadata\_image::empty

```cpp
bool VectorOfImage_dataset_metadata_image::empty();
AutoIt:
    $oVectorOfImage_dataset_metadata_image.empty() -> retval
```

### VectorOfImage\_dataset\_metadata\_image::end

```cpp
void* VectorOfImage_dataset_metadata_image::end();
AutoIt:
    $oVectorOfImage_dataset_metadata_image.end() -> retval
```

### VectorOfImage\_dataset\_metadata\_image::get\_Item

```cpp
dlib::image_dataset_metadata::image VectorOfImage_dataset_metadata_image::get_Item( size_t index );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.Item( $index ) -> retval
    $oVectorOfImage_dataset_metadata_image( $index ) -> retval
```

### VectorOfImage\_dataset\_metadata\_image::get\_\_NewEnum

```cpp
IUnknown* VectorOfImage_dataset_metadata_image::get__NewEnum();
AutoIt:
    $oVectorOfImage_dataset_metadata_image._NewEnum() -> retval
```

### VectorOfImage\_dataset\_metadata\_image::push\_back

```cpp
void VectorOfImage_dataset_metadata_image::push_back( dlib::image_dataset_metadata::image value );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.push_back( $value ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::push\_vector

```cpp
void VectorOfImage_dataset_metadata_image::push_vector( VectorOfImage_dataset_metadata_image other );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.push_vector( $other ) -> None
```

```cpp
void VectorOfImage_dataset_metadata_image::push_vector( VectorOfImage_dataset_metadata_image other,
                                                        size_t                               count,
                                                        size_t                               start = 0 );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::put\_Item

```cpp
void VectorOfImage_dataset_metadata_image::put_Item( size_t                              index,
                                                     dlib::image_dataset_metadata::image item );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.Item( $index ) = $item
```

### VectorOfImage\_dataset\_metadata\_image::size

```cpp
size_t VectorOfImage_dataset_metadata_image::size();
AutoIt:
    $oVectorOfImage_dataset_metadata_image.size() -> retval
```

### VectorOfImage\_dataset\_metadata\_image::slice

```cpp
VectorOfImage_dataset_metadata_image VectorOfImage_dataset_metadata_image::slice( size_t start = 0,
                                                                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.slice( [$start[, $count]] ) -> retval
```

### VectorOfImage\_dataset\_metadata\_image::sort

```cpp
void VectorOfImage_dataset_metadata_image::sort( void*  comparator,
                                                 size_t start = 0,
                                                 size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::sort\_variant

```cpp
void VectorOfImage_dataset_metadata_image::sort_variant( void*  comparator,
                                                         size_t start = 0,
                                                         size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfImage_dataset_metadata_image.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfImage\_dataset\_metadata\_image::start

```cpp
void* VectorOfImage_dataset_metadata_image::start();
AutoIt:
    $oVectorOfImage_dataset_metadata_image.start() -> retval
```

## VectorOfSize\_t

### VectorOfSize\_t.Count

```cpp
size_t VectorOfSize_t::size()
AutoIt:
    [propget] $oVectorOfSize_t.Count
```

### VectorOfSize\_t::create

```cpp
static VectorOfSize_t VectorOfSize_t::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfSize_t").create() -> <VectorOfSize_t object>
```

```cpp
static VectorOfSize_t VectorOfSize_t::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfSize_t").create( $size ) -> <VectorOfSize_t object>
```

```cpp
static VectorOfSize_t VectorOfSize_t::create( VectorOfSize_t other );
AutoIt:
    _Dlib_ObjCreate("VectorOfSize_t").create( $other ) -> <VectorOfSize_t object>
```

### VectorOfSize\_t::Add

```cpp
void VectorOfSize_t::Add( size_t value );
AutoIt:
    $oVectorOfSize_t.Add( $value ) -> None
```

### VectorOfSize\_t::Items

```cpp
VectorOfSize_t VectorOfSize_t::Items();
AutoIt:
    $oVectorOfSize_t.Items() -> retval
```

### VectorOfSize\_t::Keys

```cpp
std::vector<int> VectorOfSize_t::Keys();
AutoIt:
    $oVectorOfSize_t.Keys() -> retval
```

### VectorOfSize\_t::Remove

```cpp
void VectorOfSize_t::Remove( size_t index );
AutoIt:
    $oVectorOfSize_t.Remove( $index ) -> None
```

### VectorOfSize\_t::append

```cpp
void VectorOfSize_t::append( size_t value );
AutoIt:
    $oVectorOfSize_t.append( $value ) -> None
```

### VectorOfSize\_t::at

```cpp
size_t VectorOfSize_t::at( size_t index );
AutoIt:
    $oVectorOfSize_t.at( $index ) -> retval
```

```cpp
void VectorOfSize_t::at( size_t index,
                         size_t value );
AutoIt:
    $oVectorOfSize_t.at( $index, $value ) -> None
```

### VectorOfSize\_t::clear

```cpp
void VectorOfSize_t::clear();
AutoIt:
    $oVectorOfSize_t.clear() -> None
```

### VectorOfSize\_t::empty

```cpp
bool VectorOfSize_t::empty();
AutoIt:
    $oVectorOfSize_t.empty() -> retval
```

### VectorOfSize\_t::end

```cpp
void* VectorOfSize_t::end();
AutoIt:
    $oVectorOfSize_t.end() -> retval
```

### VectorOfSize\_t::get\_Item

```cpp
size_t VectorOfSize_t::get_Item( size_t index );
AutoIt:
    $oVectorOfSize_t.Item( $index ) -> retval
    $oVectorOfSize_t( $index ) -> retval
```

### VectorOfSize\_t::get\_\_NewEnum

```cpp
IUnknown* VectorOfSize_t::get__NewEnum();
AutoIt:
    $oVectorOfSize_t._NewEnum() -> retval
```

### VectorOfSize\_t::push\_back

```cpp
void VectorOfSize_t::push_back( size_t value );
AutoIt:
    $oVectorOfSize_t.push_back( $value ) -> None
```

### VectorOfSize\_t::push\_vector

```cpp
void VectorOfSize_t::push_vector( VectorOfSize_t other );
AutoIt:
    $oVectorOfSize_t.push_vector( $other ) -> None
```

```cpp
void VectorOfSize_t::push_vector( VectorOfSize_t other,
                                  size_t         count,
                                  size_t         start = 0 );
AutoIt:
    $oVectorOfSize_t.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfSize\_t::put\_Item

```cpp
void VectorOfSize_t::put_Item( size_t index,
                               size_t item );
AutoIt:
    $oVectorOfSize_t.Item( $index ) = $item
```

### VectorOfSize\_t::size

```cpp
size_t VectorOfSize_t::size();
AutoIt:
    $oVectorOfSize_t.size() -> retval
```

### VectorOfSize\_t::slice

```cpp
VectorOfSize_t VectorOfSize_t::slice( size_t start = 0,
                                      size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSize_t.slice( [$start[, $count]] ) -> retval
```

### VectorOfSize\_t::sort

```cpp
void VectorOfSize_t::sort( void*  comparator,
                           size_t start = 0,
                           size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSize_t.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSize\_t::sort\_variant

```cpp
void VectorOfSize_t::sort_variant( void*  comparator,
                                   size_t start = 0,
                                   size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfSize_t.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfSize\_t::start

```cpp
void* VectorOfSize_t::start();
AutoIt:
    $oVectorOfSize_t.start() -> retval
```

## VectorOfRange

### VectorOfRange.Count

```cpp
size_t VectorOfRange::size()
AutoIt:
    [propget] $oVectorOfRange.Count
```

### VectorOfRange::create

```cpp
static VectorOfRange VectorOfRange::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfRange").create() -> <VectorOfRange object>
```

```cpp
static VectorOfRange VectorOfRange::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfRange").create( $size ) -> <VectorOfRange object>
```

```cpp
static VectorOfRange VectorOfRange::create( VectorOfRange other );
AutoIt:
    _Dlib_ObjCreate("VectorOfRange").create( $other ) -> <VectorOfRange object>
```

### VectorOfRange::Add

```cpp
void VectorOfRange::Add( cv::Range value );
AutoIt:
    $oVectorOfRange.Add( $value ) -> None
```

### VectorOfRange::Items

```cpp
VectorOfRange VectorOfRange::Items();
AutoIt:
    $oVectorOfRange.Items() -> retval
```

### VectorOfRange::Keys

```cpp
std::vector<int> VectorOfRange::Keys();
AutoIt:
    $oVectorOfRange.Keys() -> retval
```

### VectorOfRange::Remove

```cpp
void VectorOfRange::Remove( size_t index );
AutoIt:
    $oVectorOfRange.Remove( $index ) -> None
```

### VectorOfRange::append

```cpp
void VectorOfRange::append( cv::Range value );
AutoIt:
    $oVectorOfRange.append( $value ) -> None
```

### VectorOfRange::at

```cpp
cv::Range VectorOfRange::at( size_t index );
AutoIt:
    $oVectorOfRange.at( $index ) -> retval
```

```cpp
void VectorOfRange::at( size_t    index,
                        cv::Range value );
AutoIt:
    $oVectorOfRange.at( $index, $value ) -> None
```

### VectorOfRange::clear

```cpp
void VectorOfRange::clear();
AutoIt:
    $oVectorOfRange.clear() -> None
```

### VectorOfRange::empty

```cpp
bool VectorOfRange::empty();
AutoIt:
    $oVectorOfRange.empty() -> retval
```

### VectorOfRange::end

```cpp
void* VectorOfRange::end();
AutoIt:
    $oVectorOfRange.end() -> retval
```

### VectorOfRange::get\_Item

```cpp
cv::Range VectorOfRange::get_Item( size_t index );
AutoIt:
    $oVectorOfRange.Item( $index ) -> retval
    $oVectorOfRange( $index ) -> retval
```

### VectorOfRange::get\_\_NewEnum

```cpp
IUnknown* VectorOfRange::get__NewEnum();
AutoIt:
    $oVectorOfRange._NewEnum() -> retval
```

### VectorOfRange::push\_back

```cpp
void VectorOfRange::push_back( cv::Range value );
AutoIt:
    $oVectorOfRange.push_back( $value ) -> None
```

### VectorOfRange::push\_vector

```cpp
void VectorOfRange::push_vector( VectorOfRange other );
AutoIt:
    $oVectorOfRange.push_vector( $other ) -> None
```

```cpp
void VectorOfRange::push_vector( VectorOfRange other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfRange.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfRange::put\_Item

```cpp
void VectorOfRange::put_Item( size_t    index,
                              cv::Range item );
AutoIt:
    $oVectorOfRange.Item( $index ) = $item
```

### VectorOfRange::size

```cpp
size_t VectorOfRange::size();
AutoIt:
    $oVectorOfRange.size() -> retval
```

### VectorOfRange::slice

```cpp
VectorOfRange VectorOfRange::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfRange.slice( [$start[, $count]] ) -> retval
```

### VectorOfRange::sort

```cpp
void VectorOfRange::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfRange.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfRange::sort\_variant

```cpp
void VectorOfRange::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfRange.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfRange::start

```cpp
void* VectorOfRange::start();
AutoIt:
    $oVectorOfRange.start() -> retval
```

## VectorOfFloat

### VectorOfFloat.Count

```cpp
size_t VectorOfFloat::size()
AutoIt:
    [propget] $oVectorOfFloat.Count
```

### VectorOfFloat::create

```cpp
static VectorOfFloat VectorOfFloat::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfFloat").create() -> <VectorOfFloat object>
```

```cpp
static VectorOfFloat VectorOfFloat::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfFloat").create( $size ) -> <VectorOfFloat object>
```

```cpp
static VectorOfFloat VectorOfFloat::create( VectorOfFloat other );
AutoIt:
    _Dlib_ObjCreate("VectorOfFloat").create( $other ) -> <VectorOfFloat object>
```

### VectorOfFloat::Add

```cpp
void VectorOfFloat::Add( float value );
AutoIt:
    $oVectorOfFloat.Add( $value ) -> None
```

### VectorOfFloat::Items

```cpp
VectorOfFloat VectorOfFloat::Items();
AutoIt:
    $oVectorOfFloat.Items() -> retval
```

### VectorOfFloat::Keys

```cpp
std::vector<int> VectorOfFloat::Keys();
AutoIt:
    $oVectorOfFloat.Keys() -> retval
```

### VectorOfFloat::Remove

```cpp
void VectorOfFloat::Remove( size_t index );
AutoIt:
    $oVectorOfFloat.Remove( $index ) -> None
```

### VectorOfFloat::append

```cpp
void VectorOfFloat::append( float value );
AutoIt:
    $oVectorOfFloat.append( $value ) -> None
```

### VectorOfFloat::at

```cpp
float VectorOfFloat::at( size_t index );
AutoIt:
    $oVectorOfFloat.at( $index ) -> retval
```

```cpp
void VectorOfFloat::at( size_t index,
                        float  value );
AutoIt:
    $oVectorOfFloat.at( $index, $value ) -> None
```

### VectorOfFloat::clear

```cpp
void VectorOfFloat::clear();
AutoIt:
    $oVectorOfFloat.clear() -> None
```

### VectorOfFloat::empty

```cpp
bool VectorOfFloat::empty();
AutoIt:
    $oVectorOfFloat.empty() -> retval
```

### VectorOfFloat::end

```cpp
void* VectorOfFloat::end();
AutoIt:
    $oVectorOfFloat.end() -> retval
```

### VectorOfFloat::get\_Item

```cpp
float VectorOfFloat::get_Item( size_t index );
AutoIt:
    $oVectorOfFloat.Item( $index ) -> retval
    $oVectorOfFloat( $index ) -> retval
```

### VectorOfFloat::get\_\_NewEnum

```cpp
IUnknown* VectorOfFloat::get__NewEnum();
AutoIt:
    $oVectorOfFloat._NewEnum() -> retval
```

### VectorOfFloat::push\_back

```cpp
void VectorOfFloat::push_back( float value );
AutoIt:
    $oVectorOfFloat.push_back( $value ) -> None
```

### VectorOfFloat::push\_vector

```cpp
void VectorOfFloat::push_vector( VectorOfFloat other );
AutoIt:
    $oVectorOfFloat.push_vector( $other ) -> None
```

```cpp
void VectorOfFloat::push_vector( VectorOfFloat other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfFloat.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfFloat::put\_Item

```cpp
void VectorOfFloat::put_Item( size_t index,
                              float  item );
AutoIt:
    $oVectorOfFloat.Item( $index ) = $item
```

### VectorOfFloat::size

```cpp
size_t VectorOfFloat::size();
AutoIt:
    $oVectorOfFloat.size() -> retval
```

### VectorOfFloat::slice

```cpp
VectorOfFloat VectorOfFloat::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFloat.slice( [$start[, $count]] ) -> retval
```

### VectorOfFloat::sort

```cpp
void VectorOfFloat::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFloat.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFloat::sort\_variant

```cpp
void VectorOfFloat::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfFloat.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfFloat::start

```cpp
void* VectorOfFloat::start();
AutoIt:
    $oVectorOfFloat.start() -> retval
```

## VectorOfVec2b

### VectorOfVec2b.Count

```cpp
size_t VectorOfVec2b::size()
AutoIt:
    [propget] $oVectorOfVec2b.Count
```

### VectorOfVec2b::create

```cpp
static VectorOfVec2b VectorOfVec2b::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2b").create() -> <VectorOfVec2b object>
```

```cpp
static VectorOfVec2b VectorOfVec2b::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2b").create( $size ) -> <VectorOfVec2b object>
```

```cpp
static VectorOfVec2b VectorOfVec2b::create( VectorOfVec2b other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2b").create( $other ) -> <VectorOfVec2b object>
```

### VectorOfVec2b::Add

```cpp
void VectorOfVec2b::Add( cv::Vec2b value );
AutoIt:
    $oVectorOfVec2b.Add( $value ) -> None
```

### VectorOfVec2b::Items

```cpp
VectorOfVec2b VectorOfVec2b::Items();
AutoIt:
    $oVectorOfVec2b.Items() -> retval
```

### VectorOfVec2b::Keys

```cpp
std::vector<int> VectorOfVec2b::Keys();
AutoIt:
    $oVectorOfVec2b.Keys() -> retval
```

### VectorOfVec2b::Remove

```cpp
void VectorOfVec2b::Remove( size_t index );
AutoIt:
    $oVectorOfVec2b.Remove( $index ) -> None
```

### VectorOfVec2b::append

```cpp
void VectorOfVec2b::append( cv::Vec2b value );
AutoIt:
    $oVectorOfVec2b.append( $value ) -> None
```

### VectorOfVec2b::at

```cpp
cv::Vec2b VectorOfVec2b::at( size_t index );
AutoIt:
    $oVectorOfVec2b.at( $index ) -> retval
```

```cpp
void VectorOfVec2b::at( size_t    index,
                        cv::Vec2b value );
AutoIt:
    $oVectorOfVec2b.at( $index, $value ) -> None
```

### VectorOfVec2b::clear

```cpp
void VectorOfVec2b::clear();
AutoIt:
    $oVectorOfVec2b.clear() -> None
```

### VectorOfVec2b::empty

```cpp
bool VectorOfVec2b::empty();
AutoIt:
    $oVectorOfVec2b.empty() -> retval
```

### VectorOfVec2b::end

```cpp
void* VectorOfVec2b::end();
AutoIt:
    $oVectorOfVec2b.end() -> retval
```

### VectorOfVec2b::get\_Item

```cpp
cv::Vec2b VectorOfVec2b::get_Item( size_t index );
AutoIt:
    $oVectorOfVec2b.Item( $index ) -> retval
    $oVectorOfVec2b( $index ) -> retval
```

### VectorOfVec2b::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec2b::get__NewEnum();
AutoIt:
    $oVectorOfVec2b._NewEnum() -> retval
```

### VectorOfVec2b::push\_back

```cpp
void VectorOfVec2b::push_back( cv::Vec2b value );
AutoIt:
    $oVectorOfVec2b.push_back( $value ) -> None
```

### VectorOfVec2b::push\_vector

```cpp
void VectorOfVec2b::push_vector( VectorOfVec2b other );
AutoIt:
    $oVectorOfVec2b.push_vector( $other ) -> None
```

```cpp
void VectorOfVec2b::push_vector( VectorOfVec2b other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec2b.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec2b::put\_Item

```cpp
void VectorOfVec2b::put_Item( size_t    index,
                              cv::Vec2b item );
AutoIt:
    $oVectorOfVec2b.Item( $index ) = $item
```

### VectorOfVec2b::size

```cpp
size_t VectorOfVec2b::size();
AutoIt:
    $oVectorOfVec2b.size() -> retval
```

### VectorOfVec2b::slice

```cpp
VectorOfVec2b VectorOfVec2b::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2b.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec2b::sort

```cpp
void VectorOfVec2b::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2b.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2b::sort\_variant

```cpp
void VectorOfVec2b::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2b.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2b::start

```cpp
void* VectorOfVec2b::start();
AutoIt:
    $oVectorOfVec2b.start() -> retval
```

## VectorOfVec3b

### VectorOfVec3b.Count

```cpp
size_t VectorOfVec3b::size()
AutoIt:
    [propget] $oVectorOfVec3b.Count
```

### VectorOfVec3b::create

```cpp
static VectorOfVec3b VectorOfVec3b::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3b").create() -> <VectorOfVec3b object>
```

```cpp
static VectorOfVec3b VectorOfVec3b::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3b").create( $size ) -> <VectorOfVec3b object>
```

```cpp
static VectorOfVec3b VectorOfVec3b::create( VectorOfVec3b other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3b").create( $other ) -> <VectorOfVec3b object>
```

### VectorOfVec3b::Add

```cpp
void VectorOfVec3b::Add( cv::Vec3b value );
AutoIt:
    $oVectorOfVec3b.Add( $value ) -> None
```

### VectorOfVec3b::Items

```cpp
VectorOfVec3b VectorOfVec3b::Items();
AutoIt:
    $oVectorOfVec3b.Items() -> retval
```

### VectorOfVec3b::Keys

```cpp
std::vector<int> VectorOfVec3b::Keys();
AutoIt:
    $oVectorOfVec3b.Keys() -> retval
```

### VectorOfVec3b::Remove

```cpp
void VectorOfVec3b::Remove( size_t index );
AutoIt:
    $oVectorOfVec3b.Remove( $index ) -> None
```

### VectorOfVec3b::append

```cpp
void VectorOfVec3b::append( cv::Vec3b value );
AutoIt:
    $oVectorOfVec3b.append( $value ) -> None
```

### VectorOfVec3b::at

```cpp
cv::Vec3b VectorOfVec3b::at( size_t index );
AutoIt:
    $oVectorOfVec3b.at( $index ) -> retval
```

```cpp
void VectorOfVec3b::at( size_t    index,
                        cv::Vec3b value );
AutoIt:
    $oVectorOfVec3b.at( $index, $value ) -> None
```

### VectorOfVec3b::clear

```cpp
void VectorOfVec3b::clear();
AutoIt:
    $oVectorOfVec3b.clear() -> None
```

### VectorOfVec3b::empty

```cpp
bool VectorOfVec3b::empty();
AutoIt:
    $oVectorOfVec3b.empty() -> retval
```

### VectorOfVec3b::end

```cpp
void* VectorOfVec3b::end();
AutoIt:
    $oVectorOfVec3b.end() -> retval
```

### VectorOfVec3b::get\_Item

```cpp
cv::Vec3b VectorOfVec3b::get_Item( size_t index );
AutoIt:
    $oVectorOfVec3b.Item( $index ) -> retval
    $oVectorOfVec3b( $index ) -> retval
```

### VectorOfVec3b::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec3b::get__NewEnum();
AutoIt:
    $oVectorOfVec3b._NewEnum() -> retval
```

### VectorOfVec3b::push\_back

```cpp
void VectorOfVec3b::push_back( cv::Vec3b value );
AutoIt:
    $oVectorOfVec3b.push_back( $value ) -> None
```

### VectorOfVec3b::push\_vector

```cpp
void VectorOfVec3b::push_vector( VectorOfVec3b other );
AutoIt:
    $oVectorOfVec3b.push_vector( $other ) -> None
```

```cpp
void VectorOfVec3b::push_vector( VectorOfVec3b other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec3b.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec3b::put\_Item

```cpp
void VectorOfVec3b::put_Item( size_t    index,
                              cv::Vec3b item );
AutoIt:
    $oVectorOfVec3b.Item( $index ) = $item
```

### VectorOfVec3b::size

```cpp
size_t VectorOfVec3b::size();
AutoIt:
    $oVectorOfVec3b.size() -> retval
```

### VectorOfVec3b::slice

```cpp
VectorOfVec3b VectorOfVec3b::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3b.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec3b::sort

```cpp
void VectorOfVec3b::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3b.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3b::sort\_variant

```cpp
void VectorOfVec3b::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3b.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3b::start

```cpp
void* VectorOfVec3b::start();
AutoIt:
    $oVectorOfVec3b.start() -> retval
```

## VectorOfVec4b

### VectorOfVec4b.Count

```cpp
size_t VectorOfVec4b::size()
AutoIt:
    [propget] $oVectorOfVec4b.Count
```

### VectorOfVec4b::create

```cpp
static VectorOfVec4b VectorOfVec4b::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4b").create() -> <VectorOfVec4b object>
```

```cpp
static VectorOfVec4b VectorOfVec4b::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4b").create( $size ) -> <VectorOfVec4b object>
```

```cpp
static VectorOfVec4b VectorOfVec4b::create( VectorOfVec4b other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4b").create( $other ) -> <VectorOfVec4b object>
```

### VectorOfVec4b::Add

```cpp
void VectorOfVec4b::Add( cv::Vec4b value );
AutoIt:
    $oVectorOfVec4b.Add( $value ) -> None
```

### VectorOfVec4b::Items

```cpp
VectorOfVec4b VectorOfVec4b::Items();
AutoIt:
    $oVectorOfVec4b.Items() -> retval
```

### VectorOfVec4b::Keys

```cpp
std::vector<int> VectorOfVec4b::Keys();
AutoIt:
    $oVectorOfVec4b.Keys() -> retval
```

### VectorOfVec4b::Remove

```cpp
void VectorOfVec4b::Remove( size_t index );
AutoIt:
    $oVectorOfVec4b.Remove( $index ) -> None
```

### VectorOfVec4b::append

```cpp
void VectorOfVec4b::append( cv::Vec4b value );
AutoIt:
    $oVectorOfVec4b.append( $value ) -> None
```

### VectorOfVec4b::at

```cpp
cv::Vec4b VectorOfVec4b::at( size_t index );
AutoIt:
    $oVectorOfVec4b.at( $index ) -> retval
```

```cpp
void VectorOfVec4b::at( size_t    index,
                        cv::Vec4b value );
AutoIt:
    $oVectorOfVec4b.at( $index, $value ) -> None
```

### VectorOfVec4b::clear

```cpp
void VectorOfVec4b::clear();
AutoIt:
    $oVectorOfVec4b.clear() -> None
```

### VectorOfVec4b::empty

```cpp
bool VectorOfVec4b::empty();
AutoIt:
    $oVectorOfVec4b.empty() -> retval
```

### VectorOfVec4b::end

```cpp
void* VectorOfVec4b::end();
AutoIt:
    $oVectorOfVec4b.end() -> retval
```

### VectorOfVec4b::get\_Item

```cpp
cv::Vec4b VectorOfVec4b::get_Item( size_t index );
AutoIt:
    $oVectorOfVec4b.Item( $index ) -> retval
    $oVectorOfVec4b( $index ) -> retval
```

### VectorOfVec4b::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec4b::get__NewEnum();
AutoIt:
    $oVectorOfVec4b._NewEnum() -> retval
```

### VectorOfVec4b::push\_back

```cpp
void VectorOfVec4b::push_back( cv::Vec4b value );
AutoIt:
    $oVectorOfVec4b.push_back( $value ) -> None
```

### VectorOfVec4b::push\_vector

```cpp
void VectorOfVec4b::push_vector( VectorOfVec4b other );
AutoIt:
    $oVectorOfVec4b.push_vector( $other ) -> None
```

```cpp
void VectorOfVec4b::push_vector( VectorOfVec4b other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec4b.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec4b::put\_Item

```cpp
void VectorOfVec4b::put_Item( size_t    index,
                              cv::Vec4b item );
AutoIt:
    $oVectorOfVec4b.Item( $index ) = $item
```

### VectorOfVec4b::size

```cpp
size_t VectorOfVec4b::size();
AutoIt:
    $oVectorOfVec4b.size() -> retval
```

### VectorOfVec4b::slice

```cpp
VectorOfVec4b VectorOfVec4b::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4b.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec4b::sort

```cpp
void VectorOfVec4b::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4b.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4b::sort\_variant

```cpp
void VectorOfVec4b::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4b.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4b::start

```cpp
void* VectorOfVec4b::start();
AutoIt:
    $oVectorOfVec4b.start() -> retval
```

## VectorOfVec2s

### VectorOfVec2s.Count

```cpp
size_t VectorOfVec2s::size()
AutoIt:
    [propget] $oVectorOfVec2s.Count
```

### VectorOfVec2s::create

```cpp
static VectorOfVec2s VectorOfVec2s::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2s").create() -> <VectorOfVec2s object>
```

```cpp
static VectorOfVec2s VectorOfVec2s::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2s").create( $size ) -> <VectorOfVec2s object>
```

```cpp
static VectorOfVec2s VectorOfVec2s::create( VectorOfVec2s other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2s").create( $other ) -> <VectorOfVec2s object>
```

### VectorOfVec2s::Add

```cpp
void VectorOfVec2s::Add( cv::Vec2s value );
AutoIt:
    $oVectorOfVec2s.Add( $value ) -> None
```

### VectorOfVec2s::Items

```cpp
VectorOfVec2s VectorOfVec2s::Items();
AutoIt:
    $oVectorOfVec2s.Items() -> retval
```

### VectorOfVec2s::Keys

```cpp
std::vector<int> VectorOfVec2s::Keys();
AutoIt:
    $oVectorOfVec2s.Keys() -> retval
```

### VectorOfVec2s::Remove

```cpp
void VectorOfVec2s::Remove( size_t index );
AutoIt:
    $oVectorOfVec2s.Remove( $index ) -> None
```

### VectorOfVec2s::append

```cpp
void VectorOfVec2s::append( cv::Vec2s value );
AutoIt:
    $oVectorOfVec2s.append( $value ) -> None
```

### VectorOfVec2s::at

```cpp
cv::Vec2s VectorOfVec2s::at( size_t index );
AutoIt:
    $oVectorOfVec2s.at( $index ) -> retval
```

```cpp
void VectorOfVec2s::at( size_t    index,
                        cv::Vec2s value );
AutoIt:
    $oVectorOfVec2s.at( $index, $value ) -> None
```

### VectorOfVec2s::clear

```cpp
void VectorOfVec2s::clear();
AutoIt:
    $oVectorOfVec2s.clear() -> None
```

### VectorOfVec2s::empty

```cpp
bool VectorOfVec2s::empty();
AutoIt:
    $oVectorOfVec2s.empty() -> retval
```

### VectorOfVec2s::end

```cpp
void* VectorOfVec2s::end();
AutoIt:
    $oVectorOfVec2s.end() -> retval
```

### VectorOfVec2s::get\_Item

```cpp
cv::Vec2s VectorOfVec2s::get_Item( size_t index );
AutoIt:
    $oVectorOfVec2s.Item( $index ) -> retval
    $oVectorOfVec2s( $index ) -> retval
```

### VectorOfVec2s::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec2s::get__NewEnum();
AutoIt:
    $oVectorOfVec2s._NewEnum() -> retval
```

### VectorOfVec2s::push\_back

```cpp
void VectorOfVec2s::push_back( cv::Vec2s value );
AutoIt:
    $oVectorOfVec2s.push_back( $value ) -> None
```

### VectorOfVec2s::push\_vector

```cpp
void VectorOfVec2s::push_vector( VectorOfVec2s other );
AutoIt:
    $oVectorOfVec2s.push_vector( $other ) -> None
```

```cpp
void VectorOfVec2s::push_vector( VectorOfVec2s other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec2s.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec2s::put\_Item

```cpp
void VectorOfVec2s::put_Item( size_t    index,
                              cv::Vec2s item );
AutoIt:
    $oVectorOfVec2s.Item( $index ) = $item
```

### VectorOfVec2s::size

```cpp
size_t VectorOfVec2s::size();
AutoIt:
    $oVectorOfVec2s.size() -> retval
```

### VectorOfVec2s::slice

```cpp
VectorOfVec2s VectorOfVec2s::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2s.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec2s::sort

```cpp
void VectorOfVec2s::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2s.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2s::sort\_variant

```cpp
void VectorOfVec2s::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2s.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2s::start

```cpp
void* VectorOfVec2s::start();
AutoIt:
    $oVectorOfVec2s.start() -> retval
```

## VectorOfVec3s

### VectorOfVec3s.Count

```cpp
size_t VectorOfVec3s::size()
AutoIt:
    [propget] $oVectorOfVec3s.Count
```

### VectorOfVec3s::create

```cpp
static VectorOfVec3s VectorOfVec3s::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3s").create() -> <VectorOfVec3s object>
```

```cpp
static VectorOfVec3s VectorOfVec3s::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3s").create( $size ) -> <VectorOfVec3s object>
```

```cpp
static VectorOfVec3s VectorOfVec3s::create( VectorOfVec3s other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3s").create( $other ) -> <VectorOfVec3s object>
```

### VectorOfVec3s::Add

```cpp
void VectorOfVec3s::Add( cv::Vec3s value );
AutoIt:
    $oVectorOfVec3s.Add( $value ) -> None
```

### VectorOfVec3s::Items

```cpp
VectorOfVec3s VectorOfVec3s::Items();
AutoIt:
    $oVectorOfVec3s.Items() -> retval
```

### VectorOfVec3s::Keys

```cpp
std::vector<int> VectorOfVec3s::Keys();
AutoIt:
    $oVectorOfVec3s.Keys() -> retval
```

### VectorOfVec3s::Remove

```cpp
void VectorOfVec3s::Remove( size_t index );
AutoIt:
    $oVectorOfVec3s.Remove( $index ) -> None
```

### VectorOfVec3s::append

```cpp
void VectorOfVec3s::append( cv::Vec3s value );
AutoIt:
    $oVectorOfVec3s.append( $value ) -> None
```

### VectorOfVec3s::at

```cpp
cv::Vec3s VectorOfVec3s::at( size_t index );
AutoIt:
    $oVectorOfVec3s.at( $index ) -> retval
```

```cpp
void VectorOfVec3s::at( size_t    index,
                        cv::Vec3s value );
AutoIt:
    $oVectorOfVec3s.at( $index, $value ) -> None
```

### VectorOfVec3s::clear

```cpp
void VectorOfVec3s::clear();
AutoIt:
    $oVectorOfVec3s.clear() -> None
```

### VectorOfVec3s::empty

```cpp
bool VectorOfVec3s::empty();
AutoIt:
    $oVectorOfVec3s.empty() -> retval
```

### VectorOfVec3s::end

```cpp
void* VectorOfVec3s::end();
AutoIt:
    $oVectorOfVec3s.end() -> retval
```

### VectorOfVec3s::get\_Item

```cpp
cv::Vec3s VectorOfVec3s::get_Item( size_t index );
AutoIt:
    $oVectorOfVec3s.Item( $index ) -> retval
    $oVectorOfVec3s( $index ) -> retval
```

### VectorOfVec3s::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec3s::get__NewEnum();
AutoIt:
    $oVectorOfVec3s._NewEnum() -> retval
```

### VectorOfVec3s::push\_back

```cpp
void VectorOfVec3s::push_back( cv::Vec3s value );
AutoIt:
    $oVectorOfVec3s.push_back( $value ) -> None
```

### VectorOfVec3s::push\_vector

```cpp
void VectorOfVec3s::push_vector( VectorOfVec3s other );
AutoIt:
    $oVectorOfVec3s.push_vector( $other ) -> None
```

```cpp
void VectorOfVec3s::push_vector( VectorOfVec3s other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec3s.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec3s::put\_Item

```cpp
void VectorOfVec3s::put_Item( size_t    index,
                              cv::Vec3s item );
AutoIt:
    $oVectorOfVec3s.Item( $index ) = $item
```

### VectorOfVec3s::size

```cpp
size_t VectorOfVec3s::size();
AutoIt:
    $oVectorOfVec3s.size() -> retval
```

### VectorOfVec3s::slice

```cpp
VectorOfVec3s VectorOfVec3s::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3s.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec3s::sort

```cpp
void VectorOfVec3s::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3s.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3s::sort\_variant

```cpp
void VectorOfVec3s::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3s.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3s::start

```cpp
void* VectorOfVec3s::start();
AutoIt:
    $oVectorOfVec3s.start() -> retval
```

## VectorOfVec4s

### VectorOfVec4s.Count

```cpp
size_t VectorOfVec4s::size()
AutoIt:
    [propget] $oVectorOfVec4s.Count
```

### VectorOfVec4s::create

```cpp
static VectorOfVec4s VectorOfVec4s::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4s").create() -> <VectorOfVec4s object>
```

```cpp
static VectorOfVec4s VectorOfVec4s::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4s").create( $size ) -> <VectorOfVec4s object>
```

```cpp
static VectorOfVec4s VectorOfVec4s::create( VectorOfVec4s other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4s").create( $other ) -> <VectorOfVec4s object>
```

### VectorOfVec4s::Add

```cpp
void VectorOfVec4s::Add( cv::Vec4s value );
AutoIt:
    $oVectorOfVec4s.Add( $value ) -> None
```

### VectorOfVec4s::Items

```cpp
VectorOfVec4s VectorOfVec4s::Items();
AutoIt:
    $oVectorOfVec4s.Items() -> retval
```

### VectorOfVec4s::Keys

```cpp
std::vector<int> VectorOfVec4s::Keys();
AutoIt:
    $oVectorOfVec4s.Keys() -> retval
```

### VectorOfVec4s::Remove

```cpp
void VectorOfVec4s::Remove( size_t index );
AutoIt:
    $oVectorOfVec4s.Remove( $index ) -> None
```

### VectorOfVec4s::append

```cpp
void VectorOfVec4s::append( cv::Vec4s value );
AutoIt:
    $oVectorOfVec4s.append( $value ) -> None
```

### VectorOfVec4s::at

```cpp
cv::Vec4s VectorOfVec4s::at( size_t index );
AutoIt:
    $oVectorOfVec4s.at( $index ) -> retval
```

```cpp
void VectorOfVec4s::at( size_t    index,
                        cv::Vec4s value );
AutoIt:
    $oVectorOfVec4s.at( $index, $value ) -> None
```

### VectorOfVec4s::clear

```cpp
void VectorOfVec4s::clear();
AutoIt:
    $oVectorOfVec4s.clear() -> None
```

### VectorOfVec4s::empty

```cpp
bool VectorOfVec4s::empty();
AutoIt:
    $oVectorOfVec4s.empty() -> retval
```

### VectorOfVec4s::end

```cpp
void* VectorOfVec4s::end();
AutoIt:
    $oVectorOfVec4s.end() -> retval
```

### VectorOfVec4s::get\_Item

```cpp
cv::Vec4s VectorOfVec4s::get_Item( size_t index );
AutoIt:
    $oVectorOfVec4s.Item( $index ) -> retval
    $oVectorOfVec4s( $index ) -> retval
```

### VectorOfVec4s::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec4s::get__NewEnum();
AutoIt:
    $oVectorOfVec4s._NewEnum() -> retval
```

### VectorOfVec4s::push\_back

```cpp
void VectorOfVec4s::push_back( cv::Vec4s value );
AutoIt:
    $oVectorOfVec4s.push_back( $value ) -> None
```

### VectorOfVec4s::push\_vector

```cpp
void VectorOfVec4s::push_vector( VectorOfVec4s other );
AutoIt:
    $oVectorOfVec4s.push_vector( $other ) -> None
```

```cpp
void VectorOfVec4s::push_vector( VectorOfVec4s other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec4s.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec4s::put\_Item

```cpp
void VectorOfVec4s::put_Item( size_t    index,
                              cv::Vec4s item );
AutoIt:
    $oVectorOfVec4s.Item( $index ) = $item
```

### VectorOfVec4s::size

```cpp
size_t VectorOfVec4s::size();
AutoIt:
    $oVectorOfVec4s.size() -> retval
```

### VectorOfVec4s::slice

```cpp
VectorOfVec4s VectorOfVec4s::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4s.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec4s::sort

```cpp
void VectorOfVec4s::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4s.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4s::sort\_variant

```cpp
void VectorOfVec4s::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4s.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4s::start

```cpp
void* VectorOfVec4s::start();
AutoIt:
    $oVectorOfVec4s.start() -> retval
```

## VectorOfVec2w

### VectorOfVec2w.Count

```cpp
size_t VectorOfVec2w::size()
AutoIt:
    [propget] $oVectorOfVec2w.Count
```

### VectorOfVec2w::create

```cpp
static VectorOfVec2w VectorOfVec2w::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2w").create() -> <VectorOfVec2w object>
```

```cpp
static VectorOfVec2w VectorOfVec2w::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2w").create( $size ) -> <VectorOfVec2w object>
```

```cpp
static VectorOfVec2w VectorOfVec2w::create( VectorOfVec2w other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2w").create( $other ) -> <VectorOfVec2w object>
```

### VectorOfVec2w::Add

```cpp
void VectorOfVec2w::Add( cv::Vec2w value );
AutoIt:
    $oVectorOfVec2w.Add( $value ) -> None
```

### VectorOfVec2w::Items

```cpp
VectorOfVec2w VectorOfVec2w::Items();
AutoIt:
    $oVectorOfVec2w.Items() -> retval
```

### VectorOfVec2w::Keys

```cpp
std::vector<int> VectorOfVec2w::Keys();
AutoIt:
    $oVectorOfVec2w.Keys() -> retval
```

### VectorOfVec2w::Remove

```cpp
void VectorOfVec2w::Remove( size_t index );
AutoIt:
    $oVectorOfVec2w.Remove( $index ) -> None
```

### VectorOfVec2w::append

```cpp
void VectorOfVec2w::append( cv::Vec2w value );
AutoIt:
    $oVectorOfVec2w.append( $value ) -> None
```

### VectorOfVec2w::at

```cpp
cv::Vec2w VectorOfVec2w::at( size_t index );
AutoIt:
    $oVectorOfVec2w.at( $index ) -> retval
```

```cpp
void VectorOfVec2w::at( size_t    index,
                        cv::Vec2w value );
AutoIt:
    $oVectorOfVec2w.at( $index, $value ) -> None
```

### VectorOfVec2w::clear

```cpp
void VectorOfVec2w::clear();
AutoIt:
    $oVectorOfVec2w.clear() -> None
```

### VectorOfVec2w::empty

```cpp
bool VectorOfVec2w::empty();
AutoIt:
    $oVectorOfVec2w.empty() -> retval
```

### VectorOfVec2w::end

```cpp
void* VectorOfVec2w::end();
AutoIt:
    $oVectorOfVec2w.end() -> retval
```

### VectorOfVec2w::get\_Item

```cpp
cv::Vec2w VectorOfVec2w::get_Item( size_t index );
AutoIt:
    $oVectorOfVec2w.Item( $index ) -> retval
    $oVectorOfVec2w( $index ) -> retval
```

### VectorOfVec2w::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec2w::get__NewEnum();
AutoIt:
    $oVectorOfVec2w._NewEnum() -> retval
```

### VectorOfVec2w::push\_back

```cpp
void VectorOfVec2w::push_back( cv::Vec2w value );
AutoIt:
    $oVectorOfVec2w.push_back( $value ) -> None
```

### VectorOfVec2w::push\_vector

```cpp
void VectorOfVec2w::push_vector( VectorOfVec2w other );
AutoIt:
    $oVectorOfVec2w.push_vector( $other ) -> None
```

```cpp
void VectorOfVec2w::push_vector( VectorOfVec2w other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec2w.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec2w::put\_Item

```cpp
void VectorOfVec2w::put_Item( size_t    index,
                              cv::Vec2w item );
AutoIt:
    $oVectorOfVec2w.Item( $index ) = $item
```

### VectorOfVec2w::size

```cpp
size_t VectorOfVec2w::size();
AutoIt:
    $oVectorOfVec2w.size() -> retval
```

### VectorOfVec2w::slice

```cpp
VectorOfVec2w VectorOfVec2w::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2w.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec2w::sort

```cpp
void VectorOfVec2w::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2w.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2w::sort\_variant

```cpp
void VectorOfVec2w::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2w.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2w::start

```cpp
void* VectorOfVec2w::start();
AutoIt:
    $oVectorOfVec2w.start() -> retval
```

## VectorOfVec3w

### VectorOfVec3w.Count

```cpp
size_t VectorOfVec3w::size()
AutoIt:
    [propget] $oVectorOfVec3w.Count
```

### VectorOfVec3w::create

```cpp
static VectorOfVec3w VectorOfVec3w::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3w").create() -> <VectorOfVec3w object>
```

```cpp
static VectorOfVec3w VectorOfVec3w::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3w").create( $size ) -> <VectorOfVec3w object>
```

```cpp
static VectorOfVec3w VectorOfVec3w::create( VectorOfVec3w other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3w").create( $other ) -> <VectorOfVec3w object>
```

### VectorOfVec3w::Add

```cpp
void VectorOfVec3w::Add( cv::Vec3w value );
AutoIt:
    $oVectorOfVec3w.Add( $value ) -> None
```

### VectorOfVec3w::Items

```cpp
VectorOfVec3w VectorOfVec3w::Items();
AutoIt:
    $oVectorOfVec3w.Items() -> retval
```

### VectorOfVec3w::Keys

```cpp
std::vector<int> VectorOfVec3w::Keys();
AutoIt:
    $oVectorOfVec3w.Keys() -> retval
```

### VectorOfVec3w::Remove

```cpp
void VectorOfVec3w::Remove( size_t index );
AutoIt:
    $oVectorOfVec3w.Remove( $index ) -> None
```

### VectorOfVec3w::append

```cpp
void VectorOfVec3w::append( cv::Vec3w value );
AutoIt:
    $oVectorOfVec3w.append( $value ) -> None
```

### VectorOfVec3w::at

```cpp
cv::Vec3w VectorOfVec3w::at( size_t index );
AutoIt:
    $oVectorOfVec3w.at( $index ) -> retval
```

```cpp
void VectorOfVec3w::at( size_t    index,
                        cv::Vec3w value );
AutoIt:
    $oVectorOfVec3w.at( $index, $value ) -> None
```

### VectorOfVec3w::clear

```cpp
void VectorOfVec3w::clear();
AutoIt:
    $oVectorOfVec3w.clear() -> None
```

### VectorOfVec3w::empty

```cpp
bool VectorOfVec3w::empty();
AutoIt:
    $oVectorOfVec3w.empty() -> retval
```

### VectorOfVec3w::end

```cpp
void* VectorOfVec3w::end();
AutoIt:
    $oVectorOfVec3w.end() -> retval
```

### VectorOfVec3w::get\_Item

```cpp
cv::Vec3w VectorOfVec3w::get_Item( size_t index );
AutoIt:
    $oVectorOfVec3w.Item( $index ) -> retval
    $oVectorOfVec3w( $index ) -> retval
```

### VectorOfVec3w::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec3w::get__NewEnum();
AutoIt:
    $oVectorOfVec3w._NewEnum() -> retval
```

### VectorOfVec3w::push\_back

```cpp
void VectorOfVec3w::push_back( cv::Vec3w value );
AutoIt:
    $oVectorOfVec3w.push_back( $value ) -> None
```

### VectorOfVec3w::push\_vector

```cpp
void VectorOfVec3w::push_vector( VectorOfVec3w other );
AutoIt:
    $oVectorOfVec3w.push_vector( $other ) -> None
```

```cpp
void VectorOfVec3w::push_vector( VectorOfVec3w other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec3w.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec3w::put\_Item

```cpp
void VectorOfVec3w::put_Item( size_t    index,
                              cv::Vec3w item );
AutoIt:
    $oVectorOfVec3w.Item( $index ) = $item
```

### VectorOfVec3w::size

```cpp
size_t VectorOfVec3w::size();
AutoIt:
    $oVectorOfVec3w.size() -> retval
```

### VectorOfVec3w::slice

```cpp
VectorOfVec3w VectorOfVec3w::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3w.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec3w::sort

```cpp
void VectorOfVec3w::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3w.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3w::sort\_variant

```cpp
void VectorOfVec3w::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3w.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3w::start

```cpp
void* VectorOfVec3w::start();
AutoIt:
    $oVectorOfVec3w.start() -> retval
```

## VectorOfVec4w

### VectorOfVec4w.Count

```cpp
size_t VectorOfVec4w::size()
AutoIt:
    [propget] $oVectorOfVec4w.Count
```

### VectorOfVec4w::create

```cpp
static VectorOfVec4w VectorOfVec4w::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4w").create() -> <VectorOfVec4w object>
```

```cpp
static VectorOfVec4w VectorOfVec4w::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4w").create( $size ) -> <VectorOfVec4w object>
```

```cpp
static VectorOfVec4w VectorOfVec4w::create( VectorOfVec4w other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4w").create( $other ) -> <VectorOfVec4w object>
```

### VectorOfVec4w::Add

```cpp
void VectorOfVec4w::Add( cv::Vec4w value );
AutoIt:
    $oVectorOfVec4w.Add( $value ) -> None
```

### VectorOfVec4w::Items

```cpp
VectorOfVec4w VectorOfVec4w::Items();
AutoIt:
    $oVectorOfVec4w.Items() -> retval
```

### VectorOfVec4w::Keys

```cpp
std::vector<int> VectorOfVec4w::Keys();
AutoIt:
    $oVectorOfVec4w.Keys() -> retval
```

### VectorOfVec4w::Remove

```cpp
void VectorOfVec4w::Remove( size_t index );
AutoIt:
    $oVectorOfVec4w.Remove( $index ) -> None
```

### VectorOfVec4w::append

```cpp
void VectorOfVec4w::append( cv::Vec4w value );
AutoIt:
    $oVectorOfVec4w.append( $value ) -> None
```

### VectorOfVec4w::at

```cpp
cv::Vec4w VectorOfVec4w::at( size_t index );
AutoIt:
    $oVectorOfVec4w.at( $index ) -> retval
```

```cpp
void VectorOfVec4w::at( size_t    index,
                        cv::Vec4w value );
AutoIt:
    $oVectorOfVec4w.at( $index, $value ) -> None
```

### VectorOfVec4w::clear

```cpp
void VectorOfVec4w::clear();
AutoIt:
    $oVectorOfVec4w.clear() -> None
```

### VectorOfVec4w::empty

```cpp
bool VectorOfVec4w::empty();
AutoIt:
    $oVectorOfVec4w.empty() -> retval
```

### VectorOfVec4w::end

```cpp
void* VectorOfVec4w::end();
AutoIt:
    $oVectorOfVec4w.end() -> retval
```

### VectorOfVec4w::get\_Item

```cpp
cv::Vec4w VectorOfVec4w::get_Item( size_t index );
AutoIt:
    $oVectorOfVec4w.Item( $index ) -> retval
    $oVectorOfVec4w( $index ) -> retval
```

### VectorOfVec4w::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec4w::get__NewEnum();
AutoIt:
    $oVectorOfVec4w._NewEnum() -> retval
```

### VectorOfVec4w::push\_back

```cpp
void VectorOfVec4w::push_back( cv::Vec4w value );
AutoIt:
    $oVectorOfVec4w.push_back( $value ) -> None
```

### VectorOfVec4w::push\_vector

```cpp
void VectorOfVec4w::push_vector( VectorOfVec4w other );
AutoIt:
    $oVectorOfVec4w.push_vector( $other ) -> None
```

```cpp
void VectorOfVec4w::push_vector( VectorOfVec4w other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec4w.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec4w::put\_Item

```cpp
void VectorOfVec4w::put_Item( size_t    index,
                              cv::Vec4w item );
AutoIt:
    $oVectorOfVec4w.Item( $index ) = $item
```

### VectorOfVec4w::size

```cpp
size_t VectorOfVec4w::size();
AutoIt:
    $oVectorOfVec4w.size() -> retval
```

### VectorOfVec4w::slice

```cpp
VectorOfVec4w VectorOfVec4w::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4w.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec4w::sort

```cpp
void VectorOfVec4w::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4w.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4w::sort\_variant

```cpp
void VectorOfVec4w::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4w.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4w::start

```cpp
void* VectorOfVec4w::start();
AutoIt:
    $oVectorOfVec4w.start() -> retval
```

## VectorOfVec2i

### VectorOfVec2i.Count

```cpp
size_t VectorOfVec2i::size()
AutoIt:
    [propget] $oVectorOfVec2i.Count
```

### VectorOfVec2i::create

```cpp
static VectorOfVec2i VectorOfVec2i::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2i").create() -> <VectorOfVec2i object>
```

```cpp
static VectorOfVec2i VectorOfVec2i::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2i").create( $size ) -> <VectorOfVec2i object>
```

```cpp
static VectorOfVec2i VectorOfVec2i::create( VectorOfVec2i other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2i").create( $other ) -> <VectorOfVec2i object>
```

### VectorOfVec2i::Add

```cpp
void VectorOfVec2i::Add( cv::Vec2i value );
AutoIt:
    $oVectorOfVec2i.Add( $value ) -> None
```

### VectorOfVec2i::Items

```cpp
VectorOfVec2i VectorOfVec2i::Items();
AutoIt:
    $oVectorOfVec2i.Items() -> retval
```

### VectorOfVec2i::Keys

```cpp
std::vector<int> VectorOfVec2i::Keys();
AutoIt:
    $oVectorOfVec2i.Keys() -> retval
```

### VectorOfVec2i::Remove

```cpp
void VectorOfVec2i::Remove( size_t index );
AutoIt:
    $oVectorOfVec2i.Remove( $index ) -> None
```

### VectorOfVec2i::append

```cpp
void VectorOfVec2i::append( cv::Vec2i value );
AutoIt:
    $oVectorOfVec2i.append( $value ) -> None
```

### VectorOfVec2i::at

```cpp
cv::Vec2i VectorOfVec2i::at( size_t index );
AutoIt:
    $oVectorOfVec2i.at( $index ) -> retval
```

```cpp
void VectorOfVec2i::at( size_t    index,
                        cv::Vec2i value );
AutoIt:
    $oVectorOfVec2i.at( $index, $value ) -> None
```

### VectorOfVec2i::clear

```cpp
void VectorOfVec2i::clear();
AutoIt:
    $oVectorOfVec2i.clear() -> None
```

### VectorOfVec2i::empty

```cpp
bool VectorOfVec2i::empty();
AutoIt:
    $oVectorOfVec2i.empty() -> retval
```

### VectorOfVec2i::end

```cpp
void* VectorOfVec2i::end();
AutoIt:
    $oVectorOfVec2i.end() -> retval
```

### VectorOfVec2i::get\_Item

```cpp
cv::Vec2i VectorOfVec2i::get_Item( size_t index );
AutoIt:
    $oVectorOfVec2i.Item( $index ) -> retval
    $oVectorOfVec2i( $index ) -> retval
```

### VectorOfVec2i::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec2i::get__NewEnum();
AutoIt:
    $oVectorOfVec2i._NewEnum() -> retval
```

### VectorOfVec2i::push\_back

```cpp
void VectorOfVec2i::push_back( cv::Vec2i value );
AutoIt:
    $oVectorOfVec2i.push_back( $value ) -> None
```

### VectorOfVec2i::push\_vector

```cpp
void VectorOfVec2i::push_vector( VectorOfVec2i other );
AutoIt:
    $oVectorOfVec2i.push_vector( $other ) -> None
```

```cpp
void VectorOfVec2i::push_vector( VectorOfVec2i other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec2i.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec2i::put\_Item

```cpp
void VectorOfVec2i::put_Item( size_t    index,
                              cv::Vec2i item );
AutoIt:
    $oVectorOfVec2i.Item( $index ) = $item
```

### VectorOfVec2i::size

```cpp
size_t VectorOfVec2i::size();
AutoIt:
    $oVectorOfVec2i.size() -> retval
```

### VectorOfVec2i::slice

```cpp
VectorOfVec2i VectorOfVec2i::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2i.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec2i::sort

```cpp
void VectorOfVec2i::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2i.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2i::sort\_variant

```cpp
void VectorOfVec2i::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2i.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2i::start

```cpp
void* VectorOfVec2i::start();
AutoIt:
    $oVectorOfVec2i.start() -> retval
```

## VectorOfVec3i

### VectorOfVec3i.Count

```cpp
size_t VectorOfVec3i::size()
AutoIt:
    [propget] $oVectorOfVec3i.Count
```

### VectorOfVec3i::create

```cpp
static VectorOfVec3i VectorOfVec3i::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3i").create() -> <VectorOfVec3i object>
```

```cpp
static VectorOfVec3i VectorOfVec3i::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3i").create( $size ) -> <VectorOfVec3i object>
```

```cpp
static VectorOfVec3i VectorOfVec3i::create( VectorOfVec3i other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3i").create( $other ) -> <VectorOfVec3i object>
```

### VectorOfVec3i::Add

```cpp
void VectorOfVec3i::Add( cv::Vec3i value );
AutoIt:
    $oVectorOfVec3i.Add( $value ) -> None
```

### VectorOfVec3i::Items

```cpp
VectorOfVec3i VectorOfVec3i::Items();
AutoIt:
    $oVectorOfVec3i.Items() -> retval
```

### VectorOfVec3i::Keys

```cpp
std::vector<int> VectorOfVec3i::Keys();
AutoIt:
    $oVectorOfVec3i.Keys() -> retval
```

### VectorOfVec3i::Remove

```cpp
void VectorOfVec3i::Remove( size_t index );
AutoIt:
    $oVectorOfVec3i.Remove( $index ) -> None
```

### VectorOfVec3i::append

```cpp
void VectorOfVec3i::append( cv::Vec3i value );
AutoIt:
    $oVectorOfVec3i.append( $value ) -> None
```

### VectorOfVec3i::at

```cpp
cv::Vec3i VectorOfVec3i::at( size_t index );
AutoIt:
    $oVectorOfVec3i.at( $index ) -> retval
```

```cpp
void VectorOfVec3i::at( size_t    index,
                        cv::Vec3i value );
AutoIt:
    $oVectorOfVec3i.at( $index, $value ) -> None
```

### VectorOfVec3i::clear

```cpp
void VectorOfVec3i::clear();
AutoIt:
    $oVectorOfVec3i.clear() -> None
```

### VectorOfVec3i::empty

```cpp
bool VectorOfVec3i::empty();
AutoIt:
    $oVectorOfVec3i.empty() -> retval
```

### VectorOfVec3i::end

```cpp
void* VectorOfVec3i::end();
AutoIt:
    $oVectorOfVec3i.end() -> retval
```

### VectorOfVec3i::get\_Item

```cpp
cv::Vec3i VectorOfVec3i::get_Item( size_t index );
AutoIt:
    $oVectorOfVec3i.Item( $index ) -> retval
    $oVectorOfVec3i( $index ) -> retval
```

### VectorOfVec3i::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec3i::get__NewEnum();
AutoIt:
    $oVectorOfVec3i._NewEnum() -> retval
```

### VectorOfVec3i::push\_back

```cpp
void VectorOfVec3i::push_back( cv::Vec3i value );
AutoIt:
    $oVectorOfVec3i.push_back( $value ) -> None
```

### VectorOfVec3i::push\_vector

```cpp
void VectorOfVec3i::push_vector( VectorOfVec3i other );
AutoIt:
    $oVectorOfVec3i.push_vector( $other ) -> None
```

```cpp
void VectorOfVec3i::push_vector( VectorOfVec3i other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec3i.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec3i::put\_Item

```cpp
void VectorOfVec3i::put_Item( size_t    index,
                              cv::Vec3i item );
AutoIt:
    $oVectorOfVec3i.Item( $index ) = $item
```

### VectorOfVec3i::size

```cpp
size_t VectorOfVec3i::size();
AutoIt:
    $oVectorOfVec3i.size() -> retval
```

### VectorOfVec3i::slice

```cpp
VectorOfVec3i VectorOfVec3i::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3i.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec3i::sort

```cpp
void VectorOfVec3i::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3i.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3i::sort\_variant

```cpp
void VectorOfVec3i::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3i.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3i::start

```cpp
void* VectorOfVec3i::start();
AutoIt:
    $oVectorOfVec3i.start() -> retval
```

## VectorOfVec4i

### VectorOfVec4i.Count

```cpp
size_t VectorOfVec4i::size()
AutoIt:
    [propget] $oVectorOfVec4i.Count
```

### VectorOfVec4i::create

```cpp
static VectorOfVec4i VectorOfVec4i::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4i").create() -> <VectorOfVec4i object>
```

```cpp
static VectorOfVec4i VectorOfVec4i::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4i").create( $size ) -> <VectorOfVec4i object>
```

```cpp
static VectorOfVec4i VectorOfVec4i::create( VectorOfVec4i other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4i").create( $other ) -> <VectorOfVec4i object>
```

### VectorOfVec4i::Add

```cpp
void VectorOfVec4i::Add( cv::Vec4i value );
AutoIt:
    $oVectorOfVec4i.Add( $value ) -> None
```

### VectorOfVec4i::Items

```cpp
VectorOfVec4i VectorOfVec4i::Items();
AutoIt:
    $oVectorOfVec4i.Items() -> retval
```

### VectorOfVec4i::Keys

```cpp
std::vector<int> VectorOfVec4i::Keys();
AutoIt:
    $oVectorOfVec4i.Keys() -> retval
```

### VectorOfVec4i::Remove

```cpp
void VectorOfVec4i::Remove( size_t index );
AutoIt:
    $oVectorOfVec4i.Remove( $index ) -> None
```

### VectorOfVec4i::append

```cpp
void VectorOfVec4i::append( cv::Vec4i value );
AutoIt:
    $oVectorOfVec4i.append( $value ) -> None
```

### VectorOfVec4i::at

```cpp
cv::Vec4i VectorOfVec4i::at( size_t index );
AutoIt:
    $oVectorOfVec4i.at( $index ) -> retval
```

```cpp
void VectorOfVec4i::at( size_t    index,
                        cv::Vec4i value );
AutoIt:
    $oVectorOfVec4i.at( $index, $value ) -> None
```

### VectorOfVec4i::clear

```cpp
void VectorOfVec4i::clear();
AutoIt:
    $oVectorOfVec4i.clear() -> None
```

### VectorOfVec4i::empty

```cpp
bool VectorOfVec4i::empty();
AutoIt:
    $oVectorOfVec4i.empty() -> retval
```

### VectorOfVec4i::end

```cpp
void* VectorOfVec4i::end();
AutoIt:
    $oVectorOfVec4i.end() -> retval
```

### VectorOfVec4i::get\_Item

```cpp
cv::Vec4i VectorOfVec4i::get_Item( size_t index );
AutoIt:
    $oVectorOfVec4i.Item( $index ) -> retval
    $oVectorOfVec4i( $index ) -> retval
```

### VectorOfVec4i::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec4i::get__NewEnum();
AutoIt:
    $oVectorOfVec4i._NewEnum() -> retval
```

### VectorOfVec4i::push\_back

```cpp
void VectorOfVec4i::push_back( cv::Vec4i value );
AutoIt:
    $oVectorOfVec4i.push_back( $value ) -> None
```

### VectorOfVec4i::push\_vector

```cpp
void VectorOfVec4i::push_vector( VectorOfVec4i other );
AutoIt:
    $oVectorOfVec4i.push_vector( $other ) -> None
```

```cpp
void VectorOfVec4i::push_vector( VectorOfVec4i other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec4i.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec4i::put\_Item

```cpp
void VectorOfVec4i::put_Item( size_t    index,
                              cv::Vec4i item );
AutoIt:
    $oVectorOfVec4i.Item( $index ) = $item
```

### VectorOfVec4i::size

```cpp
size_t VectorOfVec4i::size();
AutoIt:
    $oVectorOfVec4i.size() -> retval
```

### VectorOfVec4i::slice

```cpp
VectorOfVec4i VectorOfVec4i::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4i.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec4i::sort

```cpp
void VectorOfVec4i::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4i.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4i::sort\_variant

```cpp
void VectorOfVec4i::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4i.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4i::start

```cpp
void* VectorOfVec4i::start();
AutoIt:
    $oVectorOfVec4i.start() -> retval
```

## VectorOfVec6i

### VectorOfVec6i.Count

```cpp
size_t VectorOfVec6i::size()
AutoIt:
    [propget] $oVectorOfVec6i.Count
```

### VectorOfVec6i::create

```cpp
static VectorOfVec6i VectorOfVec6i::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6i").create() -> <VectorOfVec6i object>
```

```cpp
static VectorOfVec6i VectorOfVec6i::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6i").create( $size ) -> <VectorOfVec6i object>
```

```cpp
static VectorOfVec6i VectorOfVec6i::create( VectorOfVec6i other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6i").create( $other ) -> <VectorOfVec6i object>
```

### VectorOfVec6i::Add

```cpp
void VectorOfVec6i::Add( cv::Vec6i value );
AutoIt:
    $oVectorOfVec6i.Add( $value ) -> None
```

### VectorOfVec6i::Items

```cpp
VectorOfVec6i VectorOfVec6i::Items();
AutoIt:
    $oVectorOfVec6i.Items() -> retval
```

### VectorOfVec6i::Keys

```cpp
std::vector<int> VectorOfVec6i::Keys();
AutoIt:
    $oVectorOfVec6i.Keys() -> retval
```

### VectorOfVec6i::Remove

```cpp
void VectorOfVec6i::Remove( size_t index );
AutoIt:
    $oVectorOfVec6i.Remove( $index ) -> None
```

### VectorOfVec6i::append

```cpp
void VectorOfVec6i::append( cv::Vec6i value );
AutoIt:
    $oVectorOfVec6i.append( $value ) -> None
```

### VectorOfVec6i::at

```cpp
cv::Vec6i VectorOfVec6i::at( size_t index );
AutoIt:
    $oVectorOfVec6i.at( $index ) -> retval
```

```cpp
void VectorOfVec6i::at( size_t    index,
                        cv::Vec6i value );
AutoIt:
    $oVectorOfVec6i.at( $index, $value ) -> None
```

### VectorOfVec6i::clear

```cpp
void VectorOfVec6i::clear();
AutoIt:
    $oVectorOfVec6i.clear() -> None
```

### VectorOfVec6i::empty

```cpp
bool VectorOfVec6i::empty();
AutoIt:
    $oVectorOfVec6i.empty() -> retval
```

### VectorOfVec6i::end

```cpp
void* VectorOfVec6i::end();
AutoIt:
    $oVectorOfVec6i.end() -> retval
```

### VectorOfVec6i::get\_Item

```cpp
cv::Vec6i VectorOfVec6i::get_Item( size_t index );
AutoIt:
    $oVectorOfVec6i.Item( $index ) -> retval
    $oVectorOfVec6i( $index ) -> retval
```

### VectorOfVec6i::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec6i::get__NewEnum();
AutoIt:
    $oVectorOfVec6i._NewEnum() -> retval
```

### VectorOfVec6i::push\_back

```cpp
void VectorOfVec6i::push_back( cv::Vec6i value );
AutoIt:
    $oVectorOfVec6i.push_back( $value ) -> None
```

### VectorOfVec6i::push\_vector

```cpp
void VectorOfVec6i::push_vector( VectorOfVec6i other );
AutoIt:
    $oVectorOfVec6i.push_vector( $other ) -> None
```

```cpp
void VectorOfVec6i::push_vector( VectorOfVec6i other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec6i.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec6i::put\_Item

```cpp
void VectorOfVec6i::put_Item( size_t    index,
                              cv::Vec6i item );
AutoIt:
    $oVectorOfVec6i.Item( $index ) = $item
```

### VectorOfVec6i::size

```cpp
size_t VectorOfVec6i::size();
AutoIt:
    $oVectorOfVec6i.size() -> retval
```

### VectorOfVec6i::slice

```cpp
VectorOfVec6i VectorOfVec6i::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6i.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec6i::sort

```cpp
void VectorOfVec6i::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6i.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec6i::sort\_variant

```cpp
void VectorOfVec6i::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6i.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec6i::start

```cpp
void* VectorOfVec6i::start();
AutoIt:
    $oVectorOfVec6i.start() -> retval
```

## VectorOfVec8i

### VectorOfVec8i.Count

```cpp
size_t VectorOfVec8i::size()
AutoIt:
    [propget] $oVectorOfVec8i.Count
```

### VectorOfVec8i::create

```cpp
static VectorOfVec8i VectorOfVec8i::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec8i").create() -> <VectorOfVec8i object>
```

```cpp
static VectorOfVec8i VectorOfVec8i::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec8i").create( $size ) -> <VectorOfVec8i object>
```

```cpp
static VectorOfVec8i VectorOfVec8i::create( VectorOfVec8i other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec8i").create( $other ) -> <VectorOfVec8i object>
```

### VectorOfVec8i::Add

```cpp
void VectorOfVec8i::Add( cv::Vec8i value );
AutoIt:
    $oVectorOfVec8i.Add( $value ) -> None
```

### VectorOfVec8i::Items

```cpp
VectorOfVec8i VectorOfVec8i::Items();
AutoIt:
    $oVectorOfVec8i.Items() -> retval
```

### VectorOfVec8i::Keys

```cpp
std::vector<int> VectorOfVec8i::Keys();
AutoIt:
    $oVectorOfVec8i.Keys() -> retval
```

### VectorOfVec8i::Remove

```cpp
void VectorOfVec8i::Remove( size_t index );
AutoIt:
    $oVectorOfVec8i.Remove( $index ) -> None
```

### VectorOfVec8i::append

```cpp
void VectorOfVec8i::append( cv::Vec8i value );
AutoIt:
    $oVectorOfVec8i.append( $value ) -> None
```

### VectorOfVec8i::at

```cpp
cv::Vec8i VectorOfVec8i::at( size_t index );
AutoIt:
    $oVectorOfVec8i.at( $index ) -> retval
```

```cpp
void VectorOfVec8i::at( size_t    index,
                        cv::Vec8i value );
AutoIt:
    $oVectorOfVec8i.at( $index, $value ) -> None
```

### VectorOfVec8i::clear

```cpp
void VectorOfVec8i::clear();
AutoIt:
    $oVectorOfVec8i.clear() -> None
```

### VectorOfVec8i::empty

```cpp
bool VectorOfVec8i::empty();
AutoIt:
    $oVectorOfVec8i.empty() -> retval
```

### VectorOfVec8i::end

```cpp
void* VectorOfVec8i::end();
AutoIt:
    $oVectorOfVec8i.end() -> retval
```

### VectorOfVec8i::get\_Item

```cpp
cv::Vec8i VectorOfVec8i::get_Item( size_t index );
AutoIt:
    $oVectorOfVec8i.Item( $index ) -> retval
    $oVectorOfVec8i( $index ) -> retval
```

### VectorOfVec8i::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec8i::get__NewEnum();
AutoIt:
    $oVectorOfVec8i._NewEnum() -> retval
```

### VectorOfVec8i::push\_back

```cpp
void VectorOfVec8i::push_back( cv::Vec8i value );
AutoIt:
    $oVectorOfVec8i.push_back( $value ) -> None
```

### VectorOfVec8i::push\_vector

```cpp
void VectorOfVec8i::push_vector( VectorOfVec8i other );
AutoIt:
    $oVectorOfVec8i.push_vector( $other ) -> None
```

```cpp
void VectorOfVec8i::push_vector( VectorOfVec8i other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec8i.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec8i::put\_Item

```cpp
void VectorOfVec8i::put_Item( size_t    index,
                              cv::Vec8i item );
AutoIt:
    $oVectorOfVec8i.Item( $index ) = $item
```

### VectorOfVec8i::size

```cpp
size_t VectorOfVec8i::size();
AutoIt:
    $oVectorOfVec8i.size() -> retval
```

### VectorOfVec8i::slice

```cpp
VectorOfVec8i VectorOfVec8i::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec8i.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec8i::sort

```cpp
void VectorOfVec8i::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec8i.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec8i::sort\_variant

```cpp
void VectorOfVec8i::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec8i.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec8i::start

```cpp
void* VectorOfVec8i::start();
AutoIt:
    $oVectorOfVec8i.start() -> retval
```

## VectorOfVec2f

### VectorOfVec2f.Count

```cpp
size_t VectorOfVec2f::size()
AutoIt:
    [propget] $oVectorOfVec2f.Count
```

### VectorOfVec2f::create

```cpp
static VectorOfVec2f VectorOfVec2f::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2f").create() -> <VectorOfVec2f object>
```

```cpp
static VectorOfVec2f VectorOfVec2f::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2f").create( $size ) -> <VectorOfVec2f object>
```

```cpp
static VectorOfVec2f VectorOfVec2f::create( VectorOfVec2f other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2f").create( $other ) -> <VectorOfVec2f object>
```

### VectorOfVec2f::Add

```cpp
void VectorOfVec2f::Add( cv::Vec2f value );
AutoIt:
    $oVectorOfVec2f.Add( $value ) -> None
```

### VectorOfVec2f::Items

```cpp
VectorOfVec2f VectorOfVec2f::Items();
AutoIt:
    $oVectorOfVec2f.Items() -> retval
```

### VectorOfVec2f::Keys

```cpp
std::vector<int> VectorOfVec2f::Keys();
AutoIt:
    $oVectorOfVec2f.Keys() -> retval
```

### VectorOfVec2f::Remove

```cpp
void VectorOfVec2f::Remove( size_t index );
AutoIt:
    $oVectorOfVec2f.Remove( $index ) -> None
```

### VectorOfVec2f::append

```cpp
void VectorOfVec2f::append( cv::Vec2f value );
AutoIt:
    $oVectorOfVec2f.append( $value ) -> None
```

### VectorOfVec2f::at

```cpp
cv::Vec2f VectorOfVec2f::at( size_t index );
AutoIt:
    $oVectorOfVec2f.at( $index ) -> retval
```

```cpp
void VectorOfVec2f::at( size_t    index,
                        cv::Vec2f value );
AutoIt:
    $oVectorOfVec2f.at( $index, $value ) -> None
```

### VectorOfVec2f::clear

```cpp
void VectorOfVec2f::clear();
AutoIt:
    $oVectorOfVec2f.clear() -> None
```

### VectorOfVec2f::empty

```cpp
bool VectorOfVec2f::empty();
AutoIt:
    $oVectorOfVec2f.empty() -> retval
```

### VectorOfVec2f::end

```cpp
void* VectorOfVec2f::end();
AutoIt:
    $oVectorOfVec2f.end() -> retval
```

### VectorOfVec2f::get\_Item

```cpp
cv::Vec2f VectorOfVec2f::get_Item( size_t index );
AutoIt:
    $oVectorOfVec2f.Item( $index ) -> retval
    $oVectorOfVec2f( $index ) -> retval
```

### VectorOfVec2f::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec2f::get__NewEnum();
AutoIt:
    $oVectorOfVec2f._NewEnum() -> retval
```

### VectorOfVec2f::push\_back

```cpp
void VectorOfVec2f::push_back( cv::Vec2f value );
AutoIt:
    $oVectorOfVec2f.push_back( $value ) -> None
```

### VectorOfVec2f::push\_vector

```cpp
void VectorOfVec2f::push_vector( VectorOfVec2f other );
AutoIt:
    $oVectorOfVec2f.push_vector( $other ) -> None
```

```cpp
void VectorOfVec2f::push_vector( VectorOfVec2f other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec2f.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec2f::put\_Item

```cpp
void VectorOfVec2f::put_Item( size_t    index,
                              cv::Vec2f item );
AutoIt:
    $oVectorOfVec2f.Item( $index ) = $item
```

### VectorOfVec2f::size

```cpp
size_t VectorOfVec2f::size();
AutoIt:
    $oVectorOfVec2f.size() -> retval
```

### VectorOfVec2f::slice

```cpp
VectorOfVec2f VectorOfVec2f::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2f.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec2f::sort

```cpp
void VectorOfVec2f::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2f.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2f::sort\_variant

```cpp
void VectorOfVec2f::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2f.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2f::start

```cpp
void* VectorOfVec2f::start();
AutoIt:
    $oVectorOfVec2f.start() -> retval
```

## VectorOfVec3f

### VectorOfVec3f.Count

```cpp
size_t VectorOfVec3f::size()
AutoIt:
    [propget] $oVectorOfVec3f.Count
```

### VectorOfVec3f::create

```cpp
static VectorOfVec3f VectorOfVec3f::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3f").create() -> <VectorOfVec3f object>
```

```cpp
static VectorOfVec3f VectorOfVec3f::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3f").create( $size ) -> <VectorOfVec3f object>
```

```cpp
static VectorOfVec3f VectorOfVec3f::create( VectorOfVec3f other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3f").create( $other ) -> <VectorOfVec3f object>
```

### VectorOfVec3f::Add

```cpp
void VectorOfVec3f::Add( cv::Vec3f value );
AutoIt:
    $oVectorOfVec3f.Add( $value ) -> None
```

### VectorOfVec3f::Items

```cpp
VectorOfVec3f VectorOfVec3f::Items();
AutoIt:
    $oVectorOfVec3f.Items() -> retval
```

### VectorOfVec3f::Keys

```cpp
std::vector<int> VectorOfVec3f::Keys();
AutoIt:
    $oVectorOfVec3f.Keys() -> retval
```

### VectorOfVec3f::Remove

```cpp
void VectorOfVec3f::Remove( size_t index );
AutoIt:
    $oVectorOfVec3f.Remove( $index ) -> None
```

### VectorOfVec3f::append

```cpp
void VectorOfVec3f::append( cv::Vec3f value );
AutoIt:
    $oVectorOfVec3f.append( $value ) -> None
```

### VectorOfVec3f::at

```cpp
cv::Vec3f VectorOfVec3f::at( size_t index );
AutoIt:
    $oVectorOfVec3f.at( $index ) -> retval
```

```cpp
void VectorOfVec3f::at( size_t    index,
                        cv::Vec3f value );
AutoIt:
    $oVectorOfVec3f.at( $index, $value ) -> None
```

### VectorOfVec3f::clear

```cpp
void VectorOfVec3f::clear();
AutoIt:
    $oVectorOfVec3f.clear() -> None
```

### VectorOfVec3f::empty

```cpp
bool VectorOfVec3f::empty();
AutoIt:
    $oVectorOfVec3f.empty() -> retval
```

### VectorOfVec3f::end

```cpp
void* VectorOfVec3f::end();
AutoIt:
    $oVectorOfVec3f.end() -> retval
```

### VectorOfVec3f::get\_Item

```cpp
cv::Vec3f VectorOfVec3f::get_Item( size_t index );
AutoIt:
    $oVectorOfVec3f.Item( $index ) -> retval
    $oVectorOfVec3f( $index ) -> retval
```

### VectorOfVec3f::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec3f::get__NewEnum();
AutoIt:
    $oVectorOfVec3f._NewEnum() -> retval
```

### VectorOfVec3f::push\_back

```cpp
void VectorOfVec3f::push_back( cv::Vec3f value );
AutoIt:
    $oVectorOfVec3f.push_back( $value ) -> None
```

### VectorOfVec3f::push\_vector

```cpp
void VectorOfVec3f::push_vector( VectorOfVec3f other );
AutoIt:
    $oVectorOfVec3f.push_vector( $other ) -> None
```

```cpp
void VectorOfVec3f::push_vector( VectorOfVec3f other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec3f.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec3f::put\_Item

```cpp
void VectorOfVec3f::put_Item( size_t    index,
                              cv::Vec3f item );
AutoIt:
    $oVectorOfVec3f.Item( $index ) = $item
```

### VectorOfVec3f::size

```cpp
size_t VectorOfVec3f::size();
AutoIt:
    $oVectorOfVec3f.size() -> retval
```

### VectorOfVec3f::slice

```cpp
VectorOfVec3f VectorOfVec3f::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3f.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec3f::sort

```cpp
void VectorOfVec3f::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3f.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3f::sort\_variant

```cpp
void VectorOfVec3f::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3f.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3f::start

```cpp
void* VectorOfVec3f::start();
AutoIt:
    $oVectorOfVec3f.start() -> retval
```

## VectorOfVec4f

### VectorOfVec4f.Count

```cpp
size_t VectorOfVec4f::size()
AutoIt:
    [propget] $oVectorOfVec4f.Count
```

### VectorOfVec4f::create

```cpp
static VectorOfVec4f VectorOfVec4f::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4f").create() -> <VectorOfVec4f object>
```

```cpp
static VectorOfVec4f VectorOfVec4f::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4f").create( $size ) -> <VectorOfVec4f object>
```

```cpp
static VectorOfVec4f VectorOfVec4f::create( VectorOfVec4f other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4f").create( $other ) -> <VectorOfVec4f object>
```

### VectorOfVec4f::Add

```cpp
void VectorOfVec4f::Add( cv::Vec4f value );
AutoIt:
    $oVectorOfVec4f.Add( $value ) -> None
```

### VectorOfVec4f::Items

```cpp
VectorOfVec4f VectorOfVec4f::Items();
AutoIt:
    $oVectorOfVec4f.Items() -> retval
```

### VectorOfVec4f::Keys

```cpp
std::vector<int> VectorOfVec4f::Keys();
AutoIt:
    $oVectorOfVec4f.Keys() -> retval
```

### VectorOfVec4f::Remove

```cpp
void VectorOfVec4f::Remove( size_t index );
AutoIt:
    $oVectorOfVec4f.Remove( $index ) -> None
```

### VectorOfVec4f::append

```cpp
void VectorOfVec4f::append( cv::Vec4f value );
AutoIt:
    $oVectorOfVec4f.append( $value ) -> None
```

### VectorOfVec4f::at

```cpp
cv::Vec4f VectorOfVec4f::at( size_t index );
AutoIt:
    $oVectorOfVec4f.at( $index ) -> retval
```

```cpp
void VectorOfVec4f::at( size_t    index,
                        cv::Vec4f value );
AutoIt:
    $oVectorOfVec4f.at( $index, $value ) -> None
```

### VectorOfVec4f::clear

```cpp
void VectorOfVec4f::clear();
AutoIt:
    $oVectorOfVec4f.clear() -> None
```

### VectorOfVec4f::empty

```cpp
bool VectorOfVec4f::empty();
AutoIt:
    $oVectorOfVec4f.empty() -> retval
```

### VectorOfVec4f::end

```cpp
void* VectorOfVec4f::end();
AutoIt:
    $oVectorOfVec4f.end() -> retval
```

### VectorOfVec4f::get\_Item

```cpp
cv::Vec4f VectorOfVec4f::get_Item( size_t index );
AutoIt:
    $oVectorOfVec4f.Item( $index ) -> retval
    $oVectorOfVec4f( $index ) -> retval
```

### VectorOfVec4f::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec4f::get__NewEnum();
AutoIt:
    $oVectorOfVec4f._NewEnum() -> retval
```

### VectorOfVec4f::push\_back

```cpp
void VectorOfVec4f::push_back( cv::Vec4f value );
AutoIt:
    $oVectorOfVec4f.push_back( $value ) -> None
```

### VectorOfVec4f::push\_vector

```cpp
void VectorOfVec4f::push_vector( VectorOfVec4f other );
AutoIt:
    $oVectorOfVec4f.push_vector( $other ) -> None
```

```cpp
void VectorOfVec4f::push_vector( VectorOfVec4f other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec4f.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec4f::put\_Item

```cpp
void VectorOfVec4f::put_Item( size_t    index,
                              cv::Vec4f item );
AutoIt:
    $oVectorOfVec4f.Item( $index ) = $item
```

### VectorOfVec4f::size

```cpp
size_t VectorOfVec4f::size();
AutoIt:
    $oVectorOfVec4f.size() -> retval
```

### VectorOfVec4f::slice

```cpp
VectorOfVec4f VectorOfVec4f::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4f.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec4f::sort

```cpp
void VectorOfVec4f::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4f.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4f::sort\_variant

```cpp
void VectorOfVec4f::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4f.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4f::start

```cpp
void* VectorOfVec4f::start();
AutoIt:
    $oVectorOfVec4f.start() -> retval
```

## VectorOfVec6f

### VectorOfVec6f.Count

```cpp
size_t VectorOfVec6f::size()
AutoIt:
    [propget] $oVectorOfVec6f.Count
```

### VectorOfVec6f::create

```cpp
static VectorOfVec6f VectorOfVec6f::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6f").create() -> <VectorOfVec6f object>
```

```cpp
static VectorOfVec6f VectorOfVec6f::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6f").create( $size ) -> <VectorOfVec6f object>
```

```cpp
static VectorOfVec6f VectorOfVec6f::create( VectorOfVec6f other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6f").create( $other ) -> <VectorOfVec6f object>
```

### VectorOfVec6f::Add

```cpp
void VectorOfVec6f::Add( cv::Vec6f value );
AutoIt:
    $oVectorOfVec6f.Add( $value ) -> None
```

### VectorOfVec6f::Items

```cpp
VectorOfVec6f VectorOfVec6f::Items();
AutoIt:
    $oVectorOfVec6f.Items() -> retval
```

### VectorOfVec6f::Keys

```cpp
std::vector<int> VectorOfVec6f::Keys();
AutoIt:
    $oVectorOfVec6f.Keys() -> retval
```

### VectorOfVec6f::Remove

```cpp
void VectorOfVec6f::Remove( size_t index );
AutoIt:
    $oVectorOfVec6f.Remove( $index ) -> None
```

### VectorOfVec6f::append

```cpp
void VectorOfVec6f::append( cv::Vec6f value );
AutoIt:
    $oVectorOfVec6f.append( $value ) -> None
```

### VectorOfVec6f::at

```cpp
cv::Vec6f VectorOfVec6f::at( size_t index );
AutoIt:
    $oVectorOfVec6f.at( $index ) -> retval
```

```cpp
void VectorOfVec6f::at( size_t    index,
                        cv::Vec6f value );
AutoIt:
    $oVectorOfVec6f.at( $index, $value ) -> None
```

### VectorOfVec6f::clear

```cpp
void VectorOfVec6f::clear();
AutoIt:
    $oVectorOfVec6f.clear() -> None
```

### VectorOfVec6f::empty

```cpp
bool VectorOfVec6f::empty();
AutoIt:
    $oVectorOfVec6f.empty() -> retval
```

### VectorOfVec6f::end

```cpp
void* VectorOfVec6f::end();
AutoIt:
    $oVectorOfVec6f.end() -> retval
```

### VectorOfVec6f::get\_Item

```cpp
cv::Vec6f VectorOfVec6f::get_Item( size_t index );
AutoIt:
    $oVectorOfVec6f.Item( $index ) -> retval
    $oVectorOfVec6f( $index ) -> retval
```

### VectorOfVec6f::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec6f::get__NewEnum();
AutoIt:
    $oVectorOfVec6f._NewEnum() -> retval
```

### VectorOfVec6f::push\_back

```cpp
void VectorOfVec6f::push_back( cv::Vec6f value );
AutoIt:
    $oVectorOfVec6f.push_back( $value ) -> None
```

### VectorOfVec6f::push\_vector

```cpp
void VectorOfVec6f::push_vector( VectorOfVec6f other );
AutoIt:
    $oVectorOfVec6f.push_vector( $other ) -> None
```

```cpp
void VectorOfVec6f::push_vector( VectorOfVec6f other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec6f.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec6f::put\_Item

```cpp
void VectorOfVec6f::put_Item( size_t    index,
                              cv::Vec6f item );
AutoIt:
    $oVectorOfVec6f.Item( $index ) = $item
```

### VectorOfVec6f::size

```cpp
size_t VectorOfVec6f::size();
AutoIt:
    $oVectorOfVec6f.size() -> retval
```

### VectorOfVec6f::slice

```cpp
VectorOfVec6f VectorOfVec6f::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6f.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec6f::sort

```cpp
void VectorOfVec6f::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6f.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec6f::sort\_variant

```cpp
void VectorOfVec6f::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6f.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec6f::start

```cpp
void* VectorOfVec6f::start();
AutoIt:
    $oVectorOfVec6f.start() -> retval
```

## VectorOfVec2d

### VectorOfVec2d.Count

```cpp
size_t VectorOfVec2d::size()
AutoIt:
    [propget] $oVectorOfVec2d.Count
```

### VectorOfVec2d::create

```cpp
static VectorOfVec2d VectorOfVec2d::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2d").create() -> <VectorOfVec2d object>
```

```cpp
static VectorOfVec2d VectorOfVec2d::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2d").create( $size ) -> <VectorOfVec2d object>
```

```cpp
static VectorOfVec2d VectorOfVec2d::create( VectorOfVec2d other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec2d").create( $other ) -> <VectorOfVec2d object>
```

### VectorOfVec2d::Add

```cpp
void VectorOfVec2d::Add( cv::Vec2d value );
AutoIt:
    $oVectorOfVec2d.Add( $value ) -> None
```

### VectorOfVec2d::Items

```cpp
VectorOfVec2d VectorOfVec2d::Items();
AutoIt:
    $oVectorOfVec2d.Items() -> retval
```

### VectorOfVec2d::Keys

```cpp
std::vector<int> VectorOfVec2d::Keys();
AutoIt:
    $oVectorOfVec2d.Keys() -> retval
```

### VectorOfVec2d::Remove

```cpp
void VectorOfVec2d::Remove( size_t index );
AutoIt:
    $oVectorOfVec2d.Remove( $index ) -> None
```

### VectorOfVec2d::append

```cpp
void VectorOfVec2d::append( cv::Vec2d value );
AutoIt:
    $oVectorOfVec2d.append( $value ) -> None
```

### VectorOfVec2d::at

```cpp
cv::Vec2d VectorOfVec2d::at( size_t index );
AutoIt:
    $oVectorOfVec2d.at( $index ) -> retval
```

```cpp
void VectorOfVec2d::at( size_t    index,
                        cv::Vec2d value );
AutoIt:
    $oVectorOfVec2d.at( $index, $value ) -> None
```

### VectorOfVec2d::clear

```cpp
void VectorOfVec2d::clear();
AutoIt:
    $oVectorOfVec2d.clear() -> None
```

### VectorOfVec2d::empty

```cpp
bool VectorOfVec2d::empty();
AutoIt:
    $oVectorOfVec2d.empty() -> retval
```

### VectorOfVec2d::end

```cpp
void* VectorOfVec2d::end();
AutoIt:
    $oVectorOfVec2d.end() -> retval
```

### VectorOfVec2d::get\_Item

```cpp
cv::Vec2d VectorOfVec2d::get_Item( size_t index );
AutoIt:
    $oVectorOfVec2d.Item( $index ) -> retval
    $oVectorOfVec2d( $index ) -> retval
```

### VectorOfVec2d::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec2d::get__NewEnum();
AutoIt:
    $oVectorOfVec2d._NewEnum() -> retval
```

### VectorOfVec2d::push\_back

```cpp
void VectorOfVec2d::push_back( cv::Vec2d value );
AutoIt:
    $oVectorOfVec2d.push_back( $value ) -> None
```

### VectorOfVec2d::push\_vector

```cpp
void VectorOfVec2d::push_vector( VectorOfVec2d other );
AutoIt:
    $oVectorOfVec2d.push_vector( $other ) -> None
```

```cpp
void VectorOfVec2d::push_vector( VectorOfVec2d other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec2d.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec2d::put\_Item

```cpp
void VectorOfVec2d::put_Item( size_t    index,
                              cv::Vec2d item );
AutoIt:
    $oVectorOfVec2d.Item( $index ) = $item
```

### VectorOfVec2d::size

```cpp
size_t VectorOfVec2d::size();
AutoIt:
    $oVectorOfVec2d.size() -> retval
```

### VectorOfVec2d::slice

```cpp
VectorOfVec2d VectorOfVec2d::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2d.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec2d::sort

```cpp
void VectorOfVec2d::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2d.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2d::sort\_variant

```cpp
void VectorOfVec2d::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec2d.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec2d::start

```cpp
void* VectorOfVec2d::start();
AutoIt:
    $oVectorOfVec2d.start() -> retval
```

## VectorOfVec3d

### VectorOfVec3d.Count

```cpp
size_t VectorOfVec3d::size()
AutoIt:
    [propget] $oVectorOfVec3d.Count
```

### VectorOfVec3d::create

```cpp
static VectorOfVec3d VectorOfVec3d::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3d").create() -> <VectorOfVec3d object>
```

```cpp
static VectorOfVec3d VectorOfVec3d::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3d").create( $size ) -> <VectorOfVec3d object>
```

```cpp
static VectorOfVec3d VectorOfVec3d::create( VectorOfVec3d other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec3d").create( $other ) -> <VectorOfVec3d object>
```

### VectorOfVec3d::Add

```cpp
void VectorOfVec3d::Add( cv::Vec3d value );
AutoIt:
    $oVectorOfVec3d.Add( $value ) -> None
```

### VectorOfVec3d::Items

```cpp
VectorOfVec3d VectorOfVec3d::Items();
AutoIt:
    $oVectorOfVec3d.Items() -> retval
```

### VectorOfVec3d::Keys

```cpp
std::vector<int> VectorOfVec3d::Keys();
AutoIt:
    $oVectorOfVec3d.Keys() -> retval
```

### VectorOfVec3d::Remove

```cpp
void VectorOfVec3d::Remove( size_t index );
AutoIt:
    $oVectorOfVec3d.Remove( $index ) -> None
```

### VectorOfVec3d::append

```cpp
void VectorOfVec3d::append( cv::Vec3d value );
AutoIt:
    $oVectorOfVec3d.append( $value ) -> None
```

### VectorOfVec3d::at

```cpp
cv::Vec3d VectorOfVec3d::at( size_t index );
AutoIt:
    $oVectorOfVec3d.at( $index ) -> retval
```

```cpp
void VectorOfVec3d::at( size_t    index,
                        cv::Vec3d value );
AutoIt:
    $oVectorOfVec3d.at( $index, $value ) -> None
```

### VectorOfVec3d::clear

```cpp
void VectorOfVec3d::clear();
AutoIt:
    $oVectorOfVec3d.clear() -> None
```

### VectorOfVec3d::empty

```cpp
bool VectorOfVec3d::empty();
AutoIt:
    $oVectorOfVec3d.empty() -> retval
```

### VectorOfVec3d::end

```cpp
void* VectorOfVec3d::end();
AutoIt:
    $oVectorOfVec3d.end() -> retval
```

### VectorOfVec3d::get\_Item

```cpp
cv::Vec3d VectorOfVec3d::get_Item( size_t index );
AutoIt:
    $oVectorOfVec3d.Item( $index ) -> retval
    $oVectorOfVec3d( $index ) -> retval
```

### VectorOfVec3d::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec3d::get__NewEnum();
AutoIt:
    $oVectorOfVec3d._NewEnum() -> retval
```

### VectorOfVec3d::push\_back

```cpp
void VectorOfVec3d::push_back( cv::Vec3d value );
AutoIt:
    $oVectorOfVec3d.push_back( $value ) -> None
```

### VectorOfVec3d::push\_vector

```cpp
void VectorOfVec3d::push_vector( VectorOfVec3d other );
AutoIt:
    $oVectorOfVec3d.push_vector( $other ) -> None
```

```cpp
void VectorOfVec3d::push_vector( VectorOfVec3d other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec3d.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec3d::put\_Item

```cpp
void VectorOfVec3d::put_Item( size_t    index,
                              cv::Vec3d item );
AutoIt:
    $oVectorOfVec3d.Item( $index ) = $item
```

### VectorOfVec3d::size

```cpp
size_t VectorOfVec3d::size();
AutoIt:
    $oVectorOfVec3d.size() -> retval
```

### VectorOfVec3d::slice

```cpp
VectorOfVec3d VectorOfVec3d::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3d.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec3d::sort

```cpp
void VectorOfVec3d::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3d.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3d::sort\_variant

```cpp
void VectorOfVec3d::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec3d.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec3d::start

```cpp
void* VectorOfVec3d::start();
AutoIt:
    $oVectorOfVec3d.start() -> retval
```

## VectorOfVec4d

### VectorOfVec4d.Count

```cpp
size_t VectorOfVec4d::size()
AutoIt:
    [propget] $oVectorOfVec4d.Count
```

### VectorOfVec4d::create

```cpp
static VectorOfVec4d VectorOfVec4d::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4d").create() -> <VectorOfVec4d object>
```

```cpp
static VectorOfVec4d VectorOfVec4d::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4d").create( $size ) -> <VectorOfVec4d object>
```

```cpp
static VectorOfVec4d VectorOfVec4d::create( VectorOfVec4d other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec4d").create( $other ) -> <VectorOfVec4d object>
```

### VectorOfVec4d::Add

```cpp
void VectorOfVec4d::Add( cv::Vec4d value );
AutoIt:
    $oVectorOfVec4d.Add( $value ) -> None
```

### VectorOfVec4d::Items

```cpp
VectorOfVec4d VectorOfVec4d::Items();
AutoIt:
    $oVectorOfVec4d.Items() -> retval
```

### VectorOfVec4d::Keys

```cpp
std::vector<int> VectorOfVec4d::Keys();
AutoIt:
    $oVectorOfVec4d.Keys() -> retval
```

### VectorOfVec4d::Remove

```cpp
void VectorOfVec4d::Remove( size_t index );
AutoIt:
    $oVectorOfVec4d.Remove( $index ) -> None
```

### VectorOfVec4d::append

```cpp
void VectorOfVec4d::append( cv::Vec4d value );
AutoIt:
    $oVectorOfVec4d.append( $value ) -> None
```

### VectorOfVec4d::at

```cpp
cv::Vec4d VectorOfVec4d::at( size_t index );
AutoIt:
    $oVectorOfVec4d.at( $index ) -> retval
```

```cpp
void VectorOfVec4d::at( size_t    index,
                        cv::Vec4d value );
AutoIt:
    $oVectorOfVec4d.at( $index, $value ) -> None
```

### VectorOfVec4d::clear

```cpp
void VectorOfVec4d::clear();
AutoIt:
    $oVectorOfVec4d.clear() -> None
```

### VectorOfVec4d::empty

```cpp
bool VectorOfVec4d::empty();
AutoIt:
    $oVectorOfVec4d.empty() -> retval
```

### VectorOfVec4d::end

```cpp
void* VectorOfVec4d::end();
AutoIt:
    $oVectorOfVec4d.end() -> retval
```

### VectorOfVec4d::get\_Item

```cpp
cv::Vec4d VectorOfVec4d::get_Item( size_t index );
AutoIt:
    $oVectorOfVec4d.Item( $index ) -> retval
    $oVectorOfVec4d( $index ) -> retval
```

### VectorOfVec4d::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec4d::get__NewEnum();
AutoIt:
    $oVectorOfVec4d._NewEnum() -> retval
```

### VectorOfVec4d::push\_back

```cpp
void VectorOfVec4d::push_back( cv::Vec4d value );
AutoIt:
    $oVectorOfVec4d.push_back( $value ) -> None
```

### VectorOfVec4d::push\_vector

```cpp
void VectorOfVec4d::push_vector( VectorOfVec4d other );
AutoIt:
    $oVectorOfVec4d.push_vector( $other ) -> None
```

```cpp
void VectorOfVec4d::push_vector( VectorOfVec4d other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec4d.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec4d::put\_Item

```cpp
void VectorOfVec4d::put_Item( size_t    index,
                              cv::Vec4d item );
AutoIt:
    $oVectorOfVec4d.Item( $index ) = $item
```

### VectorOfVec4d::size

```cpp
size_t VectorOfVec4d::size();
AutoIt:
    $oVectorOfVec4d.size() -> retval
```

### VectorOfVec4d::slice

```cpp
VectorOfVec4d VectorOfVec4d::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4d.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec4d::sort

```cpp
void VectorOfVec4d::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4d.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4d::sort\_variant

```cpp
void VectorOfVec4d::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec4d.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec4d::start

```cpp
void* VectorOfVec4d::start();
AutoIt:
    $oVectorOfVec4d.start() -> retval
```

## VectorOfVec6d

### VectorOfVec6d.Count

```cpp
size_t VectorOfVec6d::size()
AutoIt:
    [propget] $oVectorOfVec6d.Count
```

### VectorOfVec6d::create

```cpp
static VectorOfVec6d VectorOfVec6d::create();
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6d").create() -> <VectorOfVec6d object>
```

```cpp
static VectorOfVec6d VectorOfVec6d::create( size_t size );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6d").create( $size ) -> <VectorOfVec6d object>
```

```cpp
static VectorOfVec6d VectorOfVec6d::create( VectorOfVec6d other );
AutoIt:
    _Dlib_ObjCreate("VectorOfVec6d").create( $other ) -> <VectorOfVec6d object>
```

### VectorOfVec6d::Add

```cpp
void VectorOfVec6d::Add( cv::Vec6d value );
AutoIt:
    $oVectorOfVec6d.Add( $value ) -> None
```

### VectorOfVec6d::Items

```cpp
VectorOfVec6d VectorOfVec6d::Items();
AutoIt:
    $oVectorOfVec6d.Items() -> retval
```

### VectorOfVec6d::Keys

```cpp
std::vector<int> VectorOfVec6d::Keys();
AutoIt:
    $oVectorOfVec6d.Keys() -> retval
```

### VectorOfVec6d::Remove

```cpp
void VectorOfVec6d::Remove( size_t index );
AutoIt:
    $oVectorOfVec6d.Remove( $index ) -> None
```

### VectorOfVec6d::append

```cpp
void VectorOfVec6d::append( cv::Vec6d value );
AutoIt:
    $oVectorOfVec6d.append( $value ) -> None
```

### VectorOfVec6d::at

```cpp
cv::Vec6d VectorOfVec6d::at( size_t index );
AutoIt:
    $oVectorOfVec6d.at( $index ) -> retval
```

```cpp
void VectorOfVec6d::at( size_t    index,
                        cv::Vec6d value );
AutoIt:
    $oVectorOfVec6d.at( $index, $value ) -> None
```

### VectorOfVec6d::clear

```cpp
void VectorOfVec6d::clear();
AutoIt:
    $oVectorOfVec6d.clear() -> None
```

### VectorOfVec6d::empty

```cpp
bool VectorOfVec6d::empty();
AutoIt:
    $oVectorOfVec6d.empty() -> retval
```

### VectorOfVec6d::end

```cpp
void* VectorOfVec6d::end();
AutoIt:
    $oVectorOfVec6d.end() -> retval
```

### VectorOfVec6d::get\_Item

```cpp
cv::Vec6d VectorOfVec6d::get_Item( size_t index );
AutoIt:
    $oVectorOfVec6d.Item( $index ) -> retval
    $oVectorOfVec6d( $index ) -> retval
```

### VectorOfVec6d::get\_\_NewEnum

```cpp
IUnknown* VectorOfVec6d::get__NewEnum();
AutoIt:
    $oVectorOfVec6d._NewEnum() -> retval
```

### VectorOfVec6d::push\_back

```cpp
void VectorOfVec6d::push_back( cv::Vec6d value );
AutoIt:
    $oVectorOfVec6d.push_back( $value ) -> None
```

### VectorOfVec6d::push\_vector

```cpp
void VectorOfVec6d::push_vector( VectorOfVec6d other );
AutoIt:
    $oVectorOfVec6d.push_vector( $other ) -> None
```

```cpp
void VectorOfVec6d::push_vector( VectorOfVec6d other,
                                 size_t        count,
                                 size_t        start = 0 );
AutoIt:
    $oVectorOfVec6d.push_vector( $other, $count[, $start] ) -> None
```

### VectorOfVec6d::put\_Item

```cpp
void VectorOfVec6d::put_Item( size_t    index,
                              cv::Vec6d item );
AutoIt:
    $oVectorOfVec6d.Item( $index ) = $item
```

### VectorOfVec6d::size

```cpp
size_t VectorOfVec6d::size();
AutoIt:
    $oVectorOfVec6d.size() -> retval
```

### VectorOfVec6d::slice

```cpp
VectorOfVec6d VectorOfVec6d::slice( size_t start = 0,
                                    size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6d.slice( [$start[, $count]] ) -> retval
```

### VectorOfVec6d::sort

```cpp
void VectorOfVec6d::sort( void*  comparator,
                          size_t start = 0,
                          size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6d.sort( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec6d::sort\_variant

```cpp
void VectorOfVec6d::sort_variant( void*  comparator,
                                  size_t start = 0,
                                  size_t count = __self->get()->size() );
AutoIt:
    $oVectorOfVec6d.sort_variant( $comparator[, $start[, $count]] ) -> None
```

### VectorOfVec6d::start

```cpp
void* VectorOfVec6d::start();
AutoIt:
    $oVectorOfVec6d.start() -> retval
```
