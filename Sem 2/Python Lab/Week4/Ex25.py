exp = input("Enter Math Expression : ")
result = exp.replace('(', '*(')
num = ['1','2','3','4','5','6','7','8','9','0']
i = 0
while(i < len(exp)) :
    if exp[i] in num :
        ind = i + 1
        if exp[ind] not in num and exp[ind] not in '(':
            result = result.replace(exp[i], exp[i] + '*')
    i += 1 
        
print(result)
