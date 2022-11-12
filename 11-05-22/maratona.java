import java.util.Scanner;

public class maratona {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int min = in.nextInt();
        int max = in.nextInt();

        if (min < max) {
            primeN(min, max);
        } else {
            primeM(min, max);
        }

    }

    public static void primeN(int min, int max) {
        int x, y, flg, cont = 0;
        for (x = min + 1; x < max; x++) {
            if (x == 1 || x == 0)
                continue;
            flg = 1;

            for (y = 2; y <= x / 2; ++y) {
                if (x % y == 0) {
                    flg = 0;
                    break;
                }
            }

            if (flg == 1) {
                System.out.print(x + " ");
                cont++;
            }

        }
        if (cont == 0) {
            System.out.println("0");
        }
    }

    public static void primeM(int min, int max) {
        int x, y, flg, cont = 0;
        for (x = min - 1; x > max; x--) {
            if (x == 1 || x == 0)
                continue;
            flg = 1;

            for (y = 2; y <= x / 2; ++y) {
                if (x % y == 0) {
                    flg = 0;
                    break;
                }
            }

            if (flg == 1) {
                System.out.print(x + " ");
                cont++;
            }
        }
        if (cont == 0) {
            System.out.println("0");
        }
    }
}
