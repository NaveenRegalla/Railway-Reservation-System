train : main.o display_trains.o display_seats.o get_available_seats.o get_current_seat.o update_seat_file.o create_node.o insert_last.o load_passengers.o search_passenger.o delete_node.o free_list.o save.o syncfile.o booking_details.o reserve_ticket.o cancel_ticket.o signup.o signin.o
	gcc main.o display_trains.o display_seats.o get_available_seats.o get_current_seat.o update_seat_file.o create_node.o insert_last.o load_passengers.o search_passenger.o delete_node.o free_list.o save.o syncfile.o booking_details.o reserve_ticket.o cancel_ticket.o signup.o signin.o -o train

main.o : main.c
	gcc -c main.c

display_trains.o : display_trains.c
	gcc -c display_trains.c

display_seats.o : display_seats.c
	gcc -c display_seats.c

get_available_seats.o : get_available_seats.c
	gcc -c get_available_seats.c

get_current_seat.o : get_current_seat.c
	gcc -c get_current_seat.c

update_seat_file.o : update_seat_file.c
	gcc -c update_seat_file.c

create_node.o : create_node.c
	gcc -c create_node.c

insert_last.o : insert_last.c
	gcc -c insert_last.c

load_passengers.o : load_passengers.c
	gcc -c load_passengers.c

search_passenger.o : search_passenger.c
	gcc -c search_passenger.c

delete_node.o : delete_node.c
	gcc -c delete_node.c

free_list.o : free_list.c
	gcc -c free_list.c

save.o : save.c
	gcc -c save.c

syncfile.o : syncfile.c
	gcc -c syncfile.c

booking_details.o : booking_details.c
	gcc -c booking_details.c

reserve_ticket.o : reserve_ticket.c
	gcc -c reserve_ticket.c

cancel_ticket.o : cancel_ticket.c
	gcc -c cancel_ticket.c

signup.o : signup.c
	gcc -c signup.c

signin.o : signin.c
	gcc -c signin.c

clean:
	rm -f *.o train
