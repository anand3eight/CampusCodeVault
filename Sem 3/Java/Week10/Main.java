import java.util.*;
import StudentInterface.*;
import StuGrade.*;
import StuRank.*;
import DisplayStudent.*;
import SearchStudent.*;
import StuFrame.*;

public class Main extends StuRank.Rank {
    public static void main(String[] args) {
        StuFrame.StudentFrame frameObj = new StuFrame.StudentFrame();
        frameObj.inputData();
    }
}