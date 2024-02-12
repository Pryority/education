package_delivered_pts = 50
collision_pts = -10
bonus_pts = 500

def calculate(delivered_packages_num, collisions_num):
    score = 0
    if (delivered_packages_num > collisions_num):
        score += 500

    score += (delivered_packages_num * package_delivered_pts) + (collisions_num * collision_pts)
    
    print("SCORE:", score)
    return score

calculate(5, 2)

calculate(0, 10)
