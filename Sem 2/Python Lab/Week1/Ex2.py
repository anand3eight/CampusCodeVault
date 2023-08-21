'''Normalization
z = (x-mean)/std'''

x = int(input("Enter X value : "))
mean = int(input("Enter Mean : "))
stddev = int(input("Enter Standard Deviation : " ))
z = (x-mean)/stddev
print("Normalized Value : ", z)
