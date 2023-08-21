// Threads

class sampleThread extends Thread {
    public synchronized void print() {
        for (int i = 0; i < 3; i++) {
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
            }
        }
    }
}

public class sampleinif2 {
    public static void main(String[] args) {
        sampleThread t1 = new sampleThread();
        System.out.println(t1.getState());
        sampleThread t2 = new sampleThread();
        t1.print();
        System.out.println(t1.getState());
        System.out.println(t1.getState());

        t2.print();
    }
}
