class Stack{
    int top; // 스택의 top
    int[] stack; // stack 배열
    int stack_maxSize; // stack 최대 크기

    Stack(int size){ // Stack 생성자
        top = -1;
        stack = new int[size];
        stack_maxSize = size;
    }

    public void push(int data){ // push 메소드
        if(top >= stack_maxSize - 1){
            System.out.println("Stack is Full");
        } else {
            stack[++top] = data;
        }
    }

    public int pop(){ // pop 메소드
        if(top == -1){
            System.out.println("Stack is Empty");
            return 0;
        } else {
            return stack[top--];
        }
    }

    public void peek(){ // peek 메소드
        if(top == -1){
            System.out.println("Stack is Empty");
        } else {
            System.out.println(stack[top]);
        }
    }
}
public class StackArray{
    public static void main(String[] args){
        Stack st = new Stack(100);
        st.push(1);
        st.push(2);
        st.peek();
        System.out.println(st.pop());
        st.peek();
    }
}