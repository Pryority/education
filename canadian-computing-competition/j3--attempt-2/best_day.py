num_attendees = input("How many people attending?\n")
availability_list = []

for attendee in range(0, int(num_attendees)):
    availability = input(f"Enter availability: \n")
    availability_list.append(availability)
    print("Appended availability to the list!")

print(availability_list)
