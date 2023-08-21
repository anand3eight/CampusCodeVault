package StuDB;
import StuGrade.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class StudentDB {
    public StudentDB(StuGrade.StudentGrade obj[], int rank[]) throws  Exception{
        Connection con = DriverManager.getConnection("jdbc:ucanaccess://C://Users//ANAND//IdeaProjects//Java_Lab//Week10//StudentDB.accdb");
        Statement st = con.createStatement();
        String query;
        for(int i = 0; i < obj.length; i++){
            query = "insert into StudentTable values(" +
                    (i+1) + "," +
                    "'" + obj[i].name + "'," +
                    "'" + obj[i].city + "'," +
                    "'" + obj[i].dob + "'," +
                    obj[i].age + "," +
                    obj[i].sem + "," +
                    obj[i].sum + "," +
                    obj[i].att + "," +
                    "'" + obj[i].grade + "'," +
                    rank[i] + ");";
                    System.out.println(query);
                    st.executeUpdate(query);

        }

        System.out.println("StudentTable Updated");
        con.close();
    }

    public static void main(String[] args) {
    }
}
