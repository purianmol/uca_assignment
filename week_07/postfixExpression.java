import java.util.*;

public class postfixExpression {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    if (scanner.hasNextLine()) {
      String expression = scanner.nextLine();
      int result = evaluatePostfix(expression);
      System.out.println(result);
    }

    scanner.close();
  }

  public static int evaluatePostfix(String exp) {
    Stack<Integer> stack = new Stack<>();

    String[] tokens = exp.trim().split("\\s+");

    for (String token : tokens) {
      if (token.isEmpty())
        continue;

      if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
        int val2 = stack.pop();
        int val1 = stack.pop();

        switch (token) {
          case "+":
            stack.push(val1 + val2);
            break;
          case "-":
            stack.push(val1 - val2);
            break;
          case "*":
            stack.push(val1 * val2);
            break;
          case "/":
            stack.push(val1 / val2);
            break;
        }
      } else {
        stack.push(Integer.parseInt(token));
      }
    }
    return stack.pop();
  }
}
