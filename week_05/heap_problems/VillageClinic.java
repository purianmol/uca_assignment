import java.util.PriorityQueue;

public class VillageClinic {
  static class Village {
    int clinic = 1;
    int population;
    double clinic_density = population;

    Village(int clinic, int population) {
      this.clinic = clinic;
      this.population = population;
    }

    private double calc_density() {
      clinic_density = (double) population / clinic;
      return clinic_density;
    }

  }

  public static double minimizeMaxLoad(int n, int[] population, int k) {
    PriorityQueue<Village> pq = new PriorityQueue<>((a, b) -> Double.compare(b.calc_density(), a.calc_density()));

    for (int village : population) {
      pq.offer(new Village(1, village));
    }
    int clinics = k - n;
    while (clinics > 0) {
      Village village = pq.poll();
      pq.offer(new Village(village.clinic + 1, village.population));
      village.calc_density();
      clinics--;
    }
    return pq.peek().clinic_density;
  }

  public static void main(String[] args) {
    int n = 3;
    int[] population = { 200, 20, 50 };
    int k = 5;

    double result = minimizeMaxLoad(n, population, k);
    System.out.printf("%.2f%n", result);
  }

}
