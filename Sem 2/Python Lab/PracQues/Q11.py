#Prefix Spectrum

dc = {71.0371: 'A', 103.0092: 'C', 115.0269: 'D', 129.0426: 'E', 147.0684: 'F', 57.0215: 'G', 137.0589: 'H', 113.0841: 'L', 128.095: 'K', 131.0405: 'M', 114.0429: 'N', 97.0528: 'P', 128.0586: 'Q', 156.1011: 'R', 87.032: 'S', 101.0477: 'T', 99.0684: 'V', 186.0793: 'W', 163.0633: 'Y'}
n = int(input("Enter Length : "))
ls = list(map(float, input("Enter : ").strip().split()))[:n]
for i in range(n-1) :
    diff = round(ls[i+1] - ls[i], 4)
    print(dc[diff], end= '')