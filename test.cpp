void write_Intersection_Text(ezgl::renderer *g){
    g->set_font_size(10);
    
    // Num of streets in the map
    int numStreets = getNumStreets();
    
    g->set_color(ezgl::BLACK);
    
    // Empty set of street segments 
    std::set<std::string> existingStreetSegments; 
    
    for(int i = 0; i < numStreets; i++){
        std::vector<int> streetSegs = find_street_segments_of_street(i);
        for(int j = 0; j < streetSegs.size(); j++){
            LatLon beginOfSegment = getIntersectionPosition(getInfoStreetSegment(streetSegs[j]).from); 
            LatLon endOfSegment = getIntersectionPosition(getInfoStreetSegment(streetSegs[j]).to); 

            std::string streetName = getStreetName(i);

            double begin_x = x_from_lon(beginOfSegment.lon());
            double begin_y = y_from_lat(beginOfSegment.lat());

            double end_x = x_from_lon(endOfSegment.lon());
            double end_y = y_from_lat(endOfSegment.lat());

            double middle_point_x = (begin_x + end_x)/2;
            double middle_point_y = (begin_y + end_y)/2;

            double strtLength = find_distance_between_two_points(std::make_pair(beginOfSegment, endOfSegment));

            ezgl::point2d point(middle_point_x, middle_point_y);

            // Check if street segment is NOT in the set 
            //if(existingStreetSegments.find(streetName) == existingStreetSegments.end()){
            g->draw_text(point, streetName, strtLength, 50);
                //existingStreetSegments.insert(streetName);
            //}
        }
    }
}
