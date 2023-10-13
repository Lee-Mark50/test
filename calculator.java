������
package gui_test;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import static gui_test.stack_calculator.ToPuffOutExpress;
import static gui_test.stack_calculator.ToInfixExpression;

    public static void main(String args[]) {
        calculator_ui windows1 = new calculator_ui() {

            @Override
            public void actionPerformed(ActionEvent e) {
                String label = e.getActionCommand();
                if (label == "cls" || label == "=") {
                    if (label == "=") {                   
 String s = yunsuan(this.b);
                    String result = s;
                    this.b = s + "";
                        resultText.setText(this.b);
                    }
                    else {
                        this.b = "";
                        resultText.setText("0");
                    }
                }
                else if (label == "sqr") {//��ƽ��������
                    String n = yunsuan2(this.b);
                    resultText.setText(n);
                    this.b = n;
                } else if (label == "x*x") {
                    String m = yunsuan3(this.b);
                    resultText.setText(m);
                    this.b = m;
                } else if(label=="sin") {
                    String l=yunsuan4(this.b);
                    resultText.setText(l);
                    this.b = l;
                } else if(label=="%"){
                    String l=yunsuan5(this.b);
                    resultText.setText(l);
                    this.b = l;
                }
                else if (label == "e" || label == "��") {
                    if (label == "e") {
                        String m = String.valueOf(2.71);
                        this.b = this.b + m;
                        resultText.setText(this.b);
                    }
                    if (label == "��") {
                        String m = String.valueOf(3.14);
                        this.b = this.b + m;
                        resultText.setText(this.b);

                    }
                } else {
                    this.b = this.b + label;
                    resultText.setText(this.b);
                }
            }
        };
    }

    public String yunsuan(String str){        
String result="";
       
        result= String.valueOf(stack_calculator.calculate(ToPuffOutExpress(ToInfixExpression(str))));
        return result;
    }
    public String yunsuan2(String str){//��ƽ��������
        String result="";
        double a=Double.parseDouble(str),b=0;
        b=Math.sqrt(a);
        result=String.valueOf(b);
        return result;
    }
    public String yunsuan3(String str){//ƽ������
        String result="";
        double a=Double.parseDouble(str),b=0;
        b=Math.pow(a, 2);
        result=String.valueOf(b);
        return result;
    }
    public String yunsuan4(String str){//�������㡣��
        String result="";
        double a=Double.parseDouble(str),b=0;
        b=Math.sin(a);
        result=String.valueOf(b);
        return result;
    }
    public String yunsuan5(String str){//,int p
        String result="";
        double a=Double.parseDouble(str),b=0;
        b=a/100;
        //b=Math.pow(a,p);
        result=String.valueOf(b);
        return result;
    }
}
class stack_calculator {
    public static List<String> ToInfixExpression(String s){
        List<String> ls=new ArrayList<String>();
        int i=0;
        String str;
        char c = 0;
        do {
            if((c=s.charAt(i))<48||(c=s.charAt(i))>57){//����
                ls.add(""+c);
                i++;//��������
            }
            else{//����
                str="";
                while(i<s.length()&&(c=s.charAt(i))>=48&&(c=s.charAt(i))<=57){
                    str+=c;
                    i++;
                }
                ls.add(str);
            }
        }while (i<s.length());
        return ls;
    }
    public static List<String> ToPuffOutExpress(List<String> a){//˫ջ����ó���׺���ʽ
        Stack<String> s1=new Stack<String>();//����ջ
        List<String> s2=new ArrayList<String>();//��������������
        for(String i:a) {
            if (i.matches("\\d+")) {//������ʽ���ж��ǲ�������
                s2.add(i);
            } else if (i.equals("(")) {
                s1.push(i);
            } else if (i.equals(")")) {
                while (!s1.peek().equals("(")) {
                    s2.add(s1.pop());
                }//��ƥ�䵽��ʱ���������s1ջ�����ұ����������Ų�pop�����õ��������������
                s1.pop();
            }
            else {
                //�ж�i��ջ�������ȼ����������ѹջs1�����򵯳�s1��ѹ��ջs2.�����±���
                while(s1.size()!=0&&operator.getValue(s1.peek())>=operator.getValue(i)){
                    s2.add(s1.pop());
                }
                s1.push(i);
            }
        }
        while(s1.size()!=0){
            s2.add(s1.pop()) ;
        }

        return s2;//����s2����
    }
    //��׺������Ӧ���ʽ
    public static List<String> getListString(String suffixExpression){
        String[]split=suffixExpression.split(" ");//�ո�ָ�
        List<String>list =new ArrayList<>();
        for(String ele:split){
            list.add(ele);
        }
        return list;
    }
    public static int calculate(List<String> ls){
        //����һ��ջ
        Stack<String> stack=new Stack<String>();
        for(String item:ls){
            if(item.matches("\\d+")){
                //ƥ����Ƕ�λ��
                stack.push(item);
            }
            else {
                int num2=Integer.parseInt(stack.pop());
                int num1=Integer.parseInt(stack.pop());
                int res=0;
                switch (item){//���㲿��
                    case "+":
                        res=num1+num2;
                        break;
                    case "-":
                        res=num1-num2;
                        break;
                    case "*":
                        res=num1*num2;
                        break;
                    case "/":
                        res=num1/num2;
                        break;
                    case ";":
                        break;
                }
                stack.push(res+"");//����ת�ַ���
            }
        }
        return Integer.parseInt(stack.pop());//ת���ַ���Ϊ����
    }
    /**
     * �����׺���ʽ
     */
}
}

2��gui����
	public abstract class calculator_ui extends JFrame implements ActionListener {
    //gui���洦��
    private String[] KEYS = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "+", "-", "*", "/", "%", "cls", "x*x", "sin", "=","sqr"};
    private JButton keys[] = new JButton[KEYS.length];//���尴ť����
    private static JTextField resultText = new JTextField("0");//�½������or�ı�������༭
    String b = "";//��ż���ʽ��String b

    public calculator_ui() {//��ʼ������
        super("������");//���ø��๹�췽��JFrame�Ĺ��췽����д������ͷ����
        this.setLayout(null);
        resultText.setBounds(20, 5, 255, 40);
        //���ڴ�С--x��20��y��Ϊ5��20��5���㿪ʼ������һ����255����40�Ŀ�
        resultText.setHorizontalAlignment(JTextField.CENTER);//�ı����������Ķ���
        resultText.setEditable(false);//�ı�������༭
        this.add(resultText);

        int x = 20, y = 55;//һ��ʮ�����ť���Ų�˳��
        for (int i = 0; i < KEYS.length; i++) {//���ư�ť
            keys[i] = new JButton();//�����������İ�ť
            keys[i].setText(KEYS[i]);//��������KEYS����������keys
            keys[i].setBounds(x, y, 60, 40);

            //�˴���Ҫ������ť
            if (x < 215) {
                x += 65;
            } else {
                x = 20;
                y += 45;
            }
            this.add(keys[i]);//��Ӱ�ť�ɹ�
        }
        for (int i = 0; i < KEYS.length; i++) {
            keys[i].addActionListener(this);//ע��ÿ����ť���¼�������
        }
        this.setResizable(false);
        this.setBounds(500, 200, 300, 400);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
    }


3����������
	class operator{
    private static int jia=1;
    private static int jian=1;
    private static int chen=2;
    private static int chu=2;
    public static int getValue(String operation){
        int result =0;
        switch (operation){
            case "+":
                result=jia;break;
            case "-":
                result=jian;break;
            case "*":
                result=chen;break;
            case "/":
                result=chu;break;
        }
        return result;
    }
