package PS;

public class Password
{
    int ch = 0;
    String ps;
    public Password(String p)
    {
        ps = p;
    }
    public Password()
    {
        ps = null;
    }
    public boolean checkpswd()
    {
        if(ps.length() > 5){
            ch += 1;
        }
        for(int i = 0; i < ps.length(); i++)
        {
            if(Character.isUpperCase(ps.charAt(i)))
            {
                ch += 1;
                break;
            }
        }
        for(int i = 0; i < ps.length(); i++)
        {
            if(Character.isLowerCase(ps.charAt(i)))
            {
                ch += 1;
                break;
            }
        }
        for(int i = 0; i < ps.length(); i++)
        {
            if(Character.isDigit(ps.charAt(i)))
            {
                ch += 1;
                break;
            }
        }
        return ch == 4;

    }
    public void printAnagram(String a, String b)
    {
        if(a.length() == 0){
            System.out.print(b + " ");
            return;
        }
        int i;
        char ch;
        String retstr;
        for(i = 0; i < a.length(); i++){
            ch = a.charAt(i);
            retstr = a.substring(0, i) + a.substring(i+1);
            printAnagram(retstr, b + ch);
        }

    }

    public void countChar(char ch)
    {
        int count = 0;
        System.out.print("Locations : ");
        for(int i = 0; i < ps.length(); i++)
        {
            if(ps.charAt(i) == ch){
                count++;
                System.out.print(i + " ");
            }
        }
        System.out.println("Count : "  + count);

    }

    public void sort()
    {
        char temp, ch[] = ps.toCharArray();
        for(int i = 0; i < ch.length; i++)
        {
            for(int j = i+1; j < ch.length; j++)
            {
                if(ch[i] > ch[j])
                {
                   temp = ch[i];
                   ch[i] = ch[j];
                   ch[j] = temp;
                }
            }
        }
        System.out.print("\nSorted String : ");
        for(int i = 0; i < ch.length; i++)
        {
            System.out.print(ch[i]);
        }
    }

    public void swap()
    {
        char temp, ch[] = ps.toCharArray();
        for(int i = 0; i < ch.length/2; i++)
        {
            temp = ch[i];
            ch[i] = ch[i + ch.length/2];
            ch[i + ch.length/2] = temp;
        }
        System.out.print("\nSwapped String : ");
        for(int i = 0; i < ch.length; i++)
        {
            System.out.print(ch[i]);
        }
    }
    public static void main(String[] args) {
    }
}