chili_dict = [
    {"Pepper":  "Poblano", "Scoville Units (SHU)": 1500},
    {"Pepper":  "Mirasol", "Scoville Units (SHU)": 6000},
    {"Pepper":  "Serrano", "Scoville Units (SHU)": 15500},
    {"Pepper":  "Cayenne", "Scoville Units (SHU)": 40000},
    {"Pepper":     "Thai", "Scoville Units (SHU)": 75000},
    {"Pepper": "Habanero", "Scoville Units (SHU)": 125000}
]

def calculate_total_spice(num_peppers, pepper_names_list):
    total_spice = 0
    for chili in chili_dict:
        for pepper in pepper_names_list:
            if chili["Pepper"] == pepper:
                print(pepper)
                total_spice += chili["Scoville Units (SHU)"]
    print("TOTAL SPICE: " + str(total_spice) + " 🌶️🔥")



calculate_total_spice(4, ["Poblano", "Cayenne", "Thai", "Poblano"])
