list_of_people_who_shared = []

while True:
    try:
        person_count = int(input("How many people are answering the questions?\n"))
        break
    except ValueError:
        print("Invalid input. Please enter a valid integer for the number of people answering.")

for person in range(0, person_count):
    while True:
        name = input("What is your name?\n")
        if name.strip() and not name.isdigit(): 
            break
        else:
            print("Invalid input. Please enter a valid string for your name.")

    # Input validation for age
    while True:
        try:
            age = int(input("What is your age?\n"))
            break  # Break out of the loop if the input is a valid integer
        except ValueError:
            print("Invalid input. Please enter a valid integer for your age.")

    while True:
        favourite_food = input("What is your favourite food?\n")
        if favourite_food.strip() and not favourite_food.isdigit(): 
            break
        else:
            print("Invalid input. Please enter a valid string for your favourite food.")

    print(f"\n👋 Hello, {name}! Your favourite food is {favourite_food} and you are {age} years old.\n")

    list_of_people_who_shared.append(name)
    people_who_shared = ', '.join(list_of_people_who_shared)

print(f"Thank you for sharing a bit about yourself, {people_who_shared}. It is nice to meet you.\n")

