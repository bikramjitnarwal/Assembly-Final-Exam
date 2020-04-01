void draw_player(int boardIndex, char Turn){
	if(Turn == 'X'){
		draw_player_X(boardIndex);
	} else {
		draw_player_O(boardIndex);
	}
}

void draw_player_X(int boardIndex){
	int initial_\_X0 = 25, initial_\_Y0 = 25, initial_\_X1 = 115, initial_\_Y1 = 88;
	int initial_/_X0 = 115, initial_/_Y0 = 25, initial_/_X1 = 25, initial_/_Y1 = 88;
	
	if(boardIndex == 1){
		draw_line(initial_\_X0, initial_\_Y0, initial_\_X1, initial_\_Y1, 0xFFFF);
		draw_line(initial_/_X0, initial_/_Y0, initial_/_X1, initial_/_Y1, 0xFFFF);
		
	} else if(boardIndex == 2){
		draw_line(initial_\_X0 + 90, initial_\_Y0, initial_\_X1 + 90, initial_\_Y1, 0xFFFF);
		draw_line(initial_/_X0 + 90, initial_/_Y0, initial_/_X1 + 90, initial_/_Y1, 0xFFFF);	
		
	} else if(boardIndex = 3){
		draw_line(initial_\_X0 + 180, initial_\_Y0, initial_\_X1 + 180, initial_\_Y1, 0xFFFF);
		draw_line(initial_/_X0 + 180, initial_/_Y0, initial_/_X1 + 180, initial_/_Y1, 0xFFFF);	
		
	} else if(boardIndex == 4){
		draw_line(initial_\_X0, initial_\_Y0 + 65, initial_\_X1, initial_\_Y1 + 65, 0xFFFF);
		draw_line(initial_/_X0, initial_/_Y0 + 65, initial_/_X1, initial_/_Y1 + 65, 0xFFFF);
	
	} else if(boardIndex == 5){
		draw_line(initial_\_X0 + 90, initial_\_Y0 + 65, initial_\_X1 + 90, initial_\_Y1 + 65, 0xFFFF);
		draw_line(initial_/_X0 + 90, initial_/_Y0 + 65, initial_/_X1 + 90, initial_/_Y1 + 65, 0xFFFF);
		
	} else if(boardIndex == 6){
		draw_line(initial_\_X0 + 180, initial_\_Y0 + 65, initial_\_X1 + 180, initial_\_Y1 + 65, 0xFFFF);
		draw_line(initial_/_X0 + 180, initial_/_Y0 + 65, initial_/_X1 + 180, initial_/_Y1 + 65, 0xFFFF);
		
	} else if(boardIndex == 7){
		draw_line(initial_\_X0, initial_\_Y0 + 130, initial_\_X1, initial_\_Y1 + 130, 0xFFFF);
		draw_line(initial_/_X0, initial_/_Y0 + 130, initial_/_X1, initial_/_Y1 + 130, 0xFFFF);
		
	} else if(boardIndex == 8){
		draw_line(initial_\_X0 + 90, initial_\_Y0 + 130, initial_\_X1 + 90, initial_\_Y1 + 130, 0xFFFF);
		draw_line(initial_/_X0 + 90, initial_/_Y0 + 130, initial_/_X1 + 90, initial_/_Y1 + 130, 0xFFFF);
		
	} else if(boardIndex == 9){
		draw_line(initial_\_X0 + 180, initial_\_Y0 + 130, initial_\_X1 + 180 initial_\_Y1 + 130, 0xFFFF);
		draw_line(initial_/_X0 + 180, initial_/_Y0 + 130, initial_/_X1 + 180, initial_/_Y1 + 130, 0xFFFF);
	}
}
