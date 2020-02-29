double areaOfScreen = g->get_visible_world().area();
    std::cout << areaOfScreen << std::endl;
    
//    std::vector<int> lv4_ways; // vector street segements ids
//    std::vector<int> lv3_ways;
//    std::vector<int> lv2_ways;
//    std::vector<int> lv1_ways;
    
    std::set<std::string> existingStreetSegments; 
    g->set_color(ezgl::BLACK);

    if(areaOfScreen >= 0.0000320935){
        // Loop through biggest vector and draw names 
        for(int i = 0; i < lv4_ways.size(); i++){
            //int middleStreetSegment = lv4_ways.size() / 2;
            
            LatLon beginOfSegment = getIntersectionPosition(getInfoStreetSegment(lv4_ways[i]).from); 
            LatLon endOfSegment = getIntersectionPosition(getInfoStreetSegment(lv4_ways[i]).to); 
            
            int street_ID = getInfoStreetSegment(lv4_ways[i]).streetID;
            
            std::string streetName = getStreetName(street_ID);

            double begin_x = x_from_lon(beginOfSegment.lon());
            double begin_y = y_from_lat(beginOfSegment.lat());

            double end_x = x_from_lon(endOfSegment.lon());
            double end_y = y_from_lat(endOfSegment.lat());

            double middle_point_x = (begin_x + end_x)/2;
            double middle_point_y = (begin_y + end_y)/2;

            double strtLength = find_distance_between_two_points(std::make_pair(beginOfSegment, endOfSegment));

            ezgl::point2d point(middle_point_x, middle_point_y);

//            double angle_Of_Street_Seg_In_Radians = atan2((end_y - begin_y),(end_x - begin_x))/DEGREE_TO_RADIAN;
//            
//            if(angle_Of_Street_Seg_In_Radians >= -90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians + 180;
//            } else if (angle_Of_Street_Seg_In_Radians <= 90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians - 180;
//            }
            
//            g->set_text_rotation(angle_Of_Street_Seg_In_Radians); //works but messes up Ians code

            // Check if street segment is NOT in the set 
            if(existingStreetSegments.find(streetName) == existingStreetSegments.end()){
                g->draw_text(point, streetName, strtLength, 50);
                existingStreetSegments.insert(streetName);
            }
        }
        
    } else if(areaOfScreen < 0.00000891487 && areaOfScreen >= 0.00000415932){
        // Loop through second largest vector and draw names 
        for(int i = 0; i < lv3_ways.size(); i++){
            //int middleStreetSegment = lv4_ways.size() / 2;
            
            LatLon beginOfSegment = getIntersectionPosition(getInfoStreetSegment(lv3_ways[i]).from); 
            LatLon endOfSegment = getIntersectionPosition(getInfoStreetSegment(lv3_ways[i]).to); 
            
            int street_ID = getInfoStreetSegment(lv3_ways[i]).streetID;
            
            std::string streetName = getStreetName(street_ID);

            double begin_x = x_from_lon(beginOfSegment.lon());
            double begin_y = y_from_lat(beginOfSegment.lat());

            double end_x = x_from_lon(endOfSegment.lon());
            double end_y = y_from_lat(endOfSegment.lat());

            double middle_point_x = (begin_x + end_x)/2;
            double middle_point_y = (begin_y + end_y)/2;

            double strtLength = find_distance_between_two_points(std::make_pair(beginOfSegment, endOfSegment));

            ezgl::point2d point(middle_point_x, middle_point_y);

//            double angle_Of_Street_Seg_In_Radians = atan2((end_y - begin_y),(end_x - begin_x))/DEGREE_TO_RADIAN;
            
//            if(angle_Of_Street_Seg_In_Radians >= -90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians + 180;
//            } else if (angle_Of_Street_Seg_In_Radians <= 90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians - 180;
//            }
//            
//            g->set_text_rotation(angle_Of_Street_Seg_In_Radians); //works but messes up Ians code

            // Check if street segment is NOT in the set 
            if(existingStreetSegments.find(streetName) == existingStreetSegments.end()){
                g->draw_text(point, streetName, strtLength, 50);
                existingStreetSegments.insert(streetName);
            }
        }
    } else if(areaOfScreen < 0.00000415932 && areaOfScreen >= 0.000000194057){
        // Loop through second smallest vector and draw names 
        for(int i = 0; i < lv2_ways.size(); i++){
            //int middleStreetSegment = lv4_ways.size() / 2;
            
            LatLon beginOfSegment = getIntersectionPosition(getInfoStreetSegment(lv2_ways[i]).from); 
            LatLon endOfSegment = getIntersectionPosition(getInfoStreetSegment(lv2_ways[i]).to); 
            
            int street_ID = getInfoStreetSegment(lv2_ways[i]).streetID;
            
            std::string streetName = getStreetName(street_ID);

            double begin_x = x_from_lon(beginOfSegment.lon());
            double begin_y = y_from_lat(beginOfSegment.lat());

            double end_x = x_from_lon(endOfSegment.lon());
            double end_y = y_from_lat(endOfSegment.lat());

            double middle_point_x = (begin_x + end_x)/2;
            double middle_point_y = (begin_y + end_y)/2;

            double strtLength = find_distance_between_two_points(std::make_pair(beginOfSegment, endOfSegment));

            ezgl::point2d point(middle_point_x, middle_point_y);

//            double angle_Of_Street_Seg_In_Radians = atan2((end_y - begin_y),(end_x - begin_x))/DEGREE_TO_RADIAN;
//            
//            if(angle_Of_Street_Seg_In_Radians >= -90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians + 180;
//            } else if (angle_Of_Street_Seg_In_Radians <= 90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians - 180;
//            }
            
//            g->set_text_rotation(angle_Of_Street_Seg_In_Radians); //works but messes up Ians code

            // Check if street segment is NOT in the set 
            if(existingStreetSegments.find(streetName) == existingStreetSegments.end()){
                g->draw_text(point, streetName, strtLength, 50);
                existingStreetSegments.insert(streetName);
            }
        }
    } else if (areaOfScreen < 0.000000194057) {
        // Loop through  smallest vector and draw names
        for(int i = 0; i < lv1_ways.size(); i++){
            //int middleStreetSegment = lv4_ways.size() / 2;
            
            LatLon beginOfSegment = getIntersectionPosition(getInfoStreetSegment(lv1_ways[i]).from); 
            LatLon endOfSegment = getIntersectionPosition(getInfoStreetSegment(lv1_ways[i]).to); 
            
            int street_ID = getInfoStreetSegment(lv1_ways[i]).streetID;
            
            std::string streetName = getStreetName(street_ID);

            double begin_x = x_from_lon(beginOfSegment.lon());
            double begin_y = y_from_lat(beginOfSegment.lat());

            double end_x = x_from_lon(endOfSegment.lon());
            double end_y = y_from_lat(endOfSegment.lat());

            double middle_point_x = (begin_x + end_x)/2;
            double middle_point_y = (begin_y + end_y)/2;

            double strtLength = find_distance_between_two_points(std::make_pair(beginOfSegment, endOfSegment));

            ezgl::point2d point(middle_point_x, middle_point_y);

            double angle_Of_Street_Seg_In_Radians = atan2((end_y - begin_y),(end_x - begin_x))/DEGREE_TO_RADIAN;
//            
//            if(angle_Of_Street_Seg_In_Radians >= -90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians + 180;
//            } else if (angle_Of_Street_Seg_In_Radians <= 90){
//                angle_Of_Street_Seg_In_Radians = angle_Of_Street_Seg_In_Radians - 180;
//            }
//            
//            g->set_text_rotation(angle_Of_Street_Seg_In_Radians); //works but messes up Ians code

            // Check if street segment is NOT in the set 
            if(existingStreetSegments.find(streetName) == existingStreetSegments.end()){
                g->draw_text(point, streetName, strtLength, 50);
                existingStreetSegments.insert(streetName);
            }
        }
    } 
