input_array_1 = ["YY.Y.", "...Y.", ".YYY."]
input_array_2 = ["YY..Y",".YY.Y",".Y.Y.",".YY.Y","Y...Y"]

def best_day_for_event(N, availability_list):
    max_attendance = 0
    best_days = []

    for day in range(1,6):
        attendance_count = 0

        for availability in availability_list:
            if availability[day-1] == 'Y':
                attendance_count += 1

        if attendance_count > max_attendance:
            max_attendance = attendance_count
            best_days = [day]
        elif attendance_count == max_attendance:
            best_days.append(day)

    print("BEST DAY(S): ", best_days)
    return best_days

best_day_for_event(3, input_array_1)
best_day_for_event(5, input_array_2)
