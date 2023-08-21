#Password Strength Check

def password(ps) :
    c1, c2, c3 = 0, 0, 0
    spls = [ "@" ,"_", "!", "#", "$", "%",  "^", "&", "*", "(", ")",  "<", ">", "?", "/", "|","{", "}", "~"]
    for i in ps :
        if(i.isupper()) :
            c1 = 1
            continue
        if(i.isdigit()) :
            c2 = 1
            continue
        if(i in spls) :
            c3 = 1
            continue
    if(c1 == 1 and c2 == 1 and c3 == 1) :
        return "Strong"
    return "Weak"

ps = input("Enter Password : ")
print(password(ps))