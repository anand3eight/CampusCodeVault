package StuRank;
import StuGrade.*;

public class Rank extends StudentGrade
{
    public static int[] rankCal(StudentGrade[] studArr)
    {
	int len = studArr.length;
        int rankarr[] = new int[len];
        int i, j, rank, rankst = len;
	for(i = 0; i < len; i++){
		if(studArr[i].grade == "F"){
			rankst--;
		}
	}
        for(i = 0; i < len; i++){
            rank = rankst;
	    if(studArr[i].grade == "F"){
		rank = -1;
		continue;
	    }
            for(j = 0; j < len; j++) {
		if(studArr[j].grade == "F"){
			continue;
		}
                if(i!= j && studArr[i].sum > studArr[j].sum){
                    rank--;
                }
            }
            rankarr[i] = rank;
        }
        return rankarr;
    }

    public static void main(String[] args) {
    }
}


