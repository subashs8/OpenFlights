add_test( [==[check if map has correct size]==] /workspaces/OpenFlights/build/test [==[check if map has correct size]==]  )
set_tests_properties( [==[check if map has correct size]==] PROPERTIES WORKING_DIRECTORY /workspaces/OpenFlights/build)
add_test( [==[check if there are no null cases in the data]==] /workspaces/OpenFlights/build/test [==[check if there are no null cases in the data]==]  )
set_tests_properties( [==[check if there are no null cases in the data]==] PROPERTIES WORKING_DIRECTORY /workspaces/OpenFlights/build)
add_test( [==[check size of routes vector]==] /workspaces/OpenFlights/build/test [==[check size of routes vector]==]  )
set_tests_properties( [==[check size of routes vector]==] PROPERTIES WORKING_DIRECTORY /workspaces/OpenFlights/build)
add_test( [==[check if there are no null cases in the route vector]==] /workspaces/OpenFlights/build/test [==[check if there are no null cases in the route vector]==]  )
set_tests_properties( [==[check if there are no null cases in the route vector]==] PROPERTIES WORKING_DIRECTORY /workspaces/OpenFlights/build)
add_test( [==[a star algorithim test 1]==] /workspaces/OpenFlights/build/test [==[a star algorithim test 1]==]  )
set_tests_properties( [==[a star algorithim test 1]==] PROPERTIES WORKING_DIRECTORY /workspaces/OpenFlights/build)
add_test( [==[a star algorithim test 2]==] /workspaces/OpenFlights/build/test [==[a star algorithim test 2]==]  )
set_tests_properties( [==[a star algorithim test 2]==] PROPERTIES WORKING_DIRECTORY /workspaces/OpenFlights/build)
set( test_TESTS [==[check if map has correct size]==] [==[check if there are no null cases in the data]==] [==[check size of routes vector]==] [==[check if there are no null cases in the route vector]==] [==[a star algorithim test 1]==] [==[a star algorithim test 2]==])
