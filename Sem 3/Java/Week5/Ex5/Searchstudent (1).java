package SearchStudent;

import java.util.*;
import DisplayStudent.*;
import StuRank.*;
import StuGrade.*;

public class Searchstudent {
    int ch, check = 0;
    char chr, c;
    String returnValue;

    public String matchString(StudentGrade[] objs, int choice, String searchValue) {
        this.ch = choice;
        switch (ch) {
            case 1:
                chr = searchValue.charAt(0);
                for (int i = 0; i < objs.length; i++) {
                    try {
                        if (objs[i].name.length() == 0) {
                            throw new NullPointerException();
                        }
                        c = objs[i].name.charAt(0);
                        if (chr == c) {
                            check = 1;
                            this.returnValue = objs[i].name;
                            break;
                        }
                    } catch (NullPointerException n) {
                        System.out.println(n);
                    }
                }
                if (check == 0) {
                    this.returnValue = "No Names Found";
                }
                break;
            case 2:
                chr = searchValue.charAt(0);
                for (int i = 0; i < objs.length; i++) {
                    try {
                        if (objs[i].name.length() == 0) {
                            throw new NullPointerException();
                        } else {
                            c = objs[i].city.charAt(objs[i].city.length() - 1);
                        }
                    } catch (NullPointerException n) {
                        System.out.println(n);
                    }
                    if (chr == c) {
                        check = 1;
                        this.returnValue = objs[i].city;
                        break;
                    }
                }
                if (check == 0) {
                    this.returnValue = "No Cities Found";
                }
                break;
            case 3:
                for (int i = 0; i < objs.length; i++) {
                    try {
                        if (objs[i].name.length() == 0) {
                            throw new NullPointerException();
                        }
                        if (searchValue.equalsIgnoreCase(objs[i].name)) {
                            check = 1;
                            this.returnValue = objs[i].name;
                            break;
                        }
                    } catch (NullPointerException n) {
                        System.out.println(n);
                    }
                }
                if (check == 0) {
                    this.returnValue = "Not Found";
                }
                break;
            case 4:
                for (int i = 0; i < objs.length; i++) {
                    try {
                        if (objs[i].name.length() == 0) {
                            throw new NullPointerException();
                        }
                        if (objs[i].name.contains(searchValue)) {
                            check = 1;
                            this.returnValue = objs[i].name;
                            break;
                        }
                    } catch (NullPointerException n) {
                        System.out.println(n);
                    }
                }
                if (check == 0) {
                    this.returnValue = "Not Found";
                }
                break;
            case 5:
                String shortest = objs[0].name, longest = objs[0].name;
                int sh = objs[0].name.length(), lo = objs[0].name.length();
                for (int i = 1; i < objs.length; i++) {
                    if (objs[i].name.length() < sh && objs[i].name.length() != 0) {
                        sh = objs[i].name.length();
                        shortest = objs[i].name;
                        continue;
                    }
                    if (objs[i].name.length() > lo) {
                        lo = objs[i].name.length();
                        longest = objs[i].name;
                    }

                }
                this.returnValue = shortest + ", " + longest;
                break;
            default:
                this.returnValue = "Invalid Choice";
        }
        return this.returnValue;
    }

    public static void main(String[] args) {
    }
}