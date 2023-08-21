package DisplayStudent;

import StuRank.*;
import java.util.*;
import StuGrade.*;

public class Displaystudent {
    int ch, check;
    String name, city;

    public String printModify(String name, String city, int ch) {
        if (check == 1) {
            return "Invalid";
        }
        switch (ch) {
            case 1:
                try {
                    this.name = Character.toUpperCase(name.charAt(0)) + name.substring(1, name.length());
                    this.city = Character.toUpperCase(city.charAt(0)) + city.substring(1, city.length());
                } catch (StringIndexOutOfBoundsException s) {
                    System.out.println(s);
                }
                break;
            case 2:
                try {
                    this.name = name.toLowerCase();
                    this.city = city.toLowerCase();
                } catch (StringIndexOutOfBoundsException s) {
                    System.out.println(s);
                }
                break;
            case 3:
                try {
                    this.name = name.toUpperCase();
                    this.city = city.toUpperCase();
                } catch (StringIndexOutOfBoundsException s) {
                    System.out.println(s);
                }
                break;
            case 4:
                this.name = name;
                this.city = city;
                break;
            default:
                this.name = "Invalid Choice";
                this.city = "Invalid.Choice";
        }
        return this.name + "," + this.city;

    }

    public static void main(String[] args) {
    }

}