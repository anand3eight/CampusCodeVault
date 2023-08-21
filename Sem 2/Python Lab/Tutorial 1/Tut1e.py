#Pythagorean Triplets

for i in range(1, 100) :
    for j in range(i, 100) :
        for k in range(j, 100) :
            if(k*k ==  i*i + j*j) :
                print(i, j, k)
