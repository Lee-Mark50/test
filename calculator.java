主程序
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
                else if (label == "sqr") {//开平方根运算
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
                else if (label == "e" || label == "π") {
                    if (label == "e") {
                        String m = String.valueOf(2.71);
                        this.b = this.b + m;
                        resultText.setText(this.b);
                    }
                    if (label == "π") {
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
    public String yunsuan2(String str){//开平方根运算
        String result="";
        double a=Double.parseDouble(str),b=0;
        b=Math.sqrt(a);
        result=String.valueOf(b);
        return result;
    }
    public String yunsuan3(String str){//平方运算
        String result="";
        double a=Double.parseDouble(str),b=0;
        b=Math.pow(a, 2);
        result=String.valueOf(b);
        return result;
    }
    public String yunsuan4(String str){//正弦运算。。
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
            if((c=s.charAt(i))<48||(c=s.charAt(i))>57){//符号
                ls.add(""+c);
                i++;//遍历即可
            }
            else{//数字
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
    public static List<String> ToPuffOutExpress(List<String> a){//双栈处理得出后缀表达式
        Stack<String> s1=new Stack<String>();//储存栈
        List<String> s2=new ArrayList<String>();//计算型数据区域
        for(String i:a) {
            if (i.matches("\\d+")) {//正则表达式，判断是不是数字
                s2.add(i);
            } else if (i.equals("(")) {
                s1.push(i);
            } else if (i.equals(")")) {
                while (!s1.peek().equals("(")) {
                    s2.add(s1.pop());
                }//当匹配到的时），则回溯s1栈，并且遍历到左括号并pop出，得到结果并除掉（）
                s1.pop();
            }
            else {
                //判断i与栈顶的优先级，如果高则压栈s1，否则弹出s1顶压入栈s2.回溯新遍历
                while(s1.size()!=0&&operator.getValue(s1.peek())>=operator.getValue(i)){
                    s2.add(s1.pop());
                }
                s1.push(i);
            }
        }
        while(s1.size()!=0){
            s2.add(s1.pop()) ;
        }

        return s2;//处理s2即可
    }
    //后缀计算相应表达式
    public static List<String> getListString(String suffixExpression){
        String[]split=suffixExpression.split(" ");//空格分隔
        List<String>list =new ArrayList<>();
        for(String ele:split){
            list.add(ele);
        }
        return list;
    }
    public static int calculate(List<String> ls){
        //创建一个栈
        Stack<String> stack=new Stack<String>();
        for(String item:ls){
            if(item.matches("\\d+")){
                //匹配的是多位数
                stack.push(item);
            }
            else {
                int num2=Integer.parseInt(stack.pop());
                int num1=Integer.parseInt(stack.pop());
                int res=0;
                switch (item){//计算部分
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
                stack.push(res+"");//整数转字符串
            }
        }
        return Integer.parseInt(stack.pop());//转换字符串为整数
    }
    /**
     * 计算后缀表达式
     */
}
}

2：gui程序
	public abstract class calculator_ui extends JFrame implements ActionListener {
    //gui界面处理
    private String[] KEYS = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "+", "-", "*", "/", "%", "cls", "x*x", "sin", "=","sqr"};
    private JButton keys[] = new JButton[KEYS.length];//定义按钮数组
    private static JTextField resultText = new JTextField("0");//新建结果框or文本框不允许编辑
    String b = "";//存放计算式的String b

    public calculator_ui() {//初始化方法
        super("计算器");//调用父类构造方法JFrame的构造方法，写出窗口头标题
        this.setLayout(null);
        resultText.setBounds(20, 5, 255, 40);
        //窗口大小--x轴20，y轴为5（20，5）点开始，绘制一个长255，宽40的框
        resultText.setHorizontalAlignment(JTextField.CENTER);//文本框文字中心对齐
        resultText.setEditable(false);//文本框不允许编辑
        this.add(resultText);

        int x = 20, y = 55;//一共十五个按钮，排布顺序
        for (int i = 0; i < KEYS.length; i++) {//绘制按钮
            keys[i] = new JButton();//创建允许单击的按钮
            keys[i].setText(KEYS[i]);//将创立的KEYS文字流传给keys
            keys[i].setBounds(x, y, 60, 40);

            //此处需要其他按钮
            if (x < 215) {
                x += 65;
            } else {
                x = 20;
                y += 45;
            }
            this.add(keys[i]);//添加按钮成功
        }
        for (int i = 0; i < KEYS.length; i++) {
            keys[i].addActionListener(this);//注册每个按钮的事件监视器
        }
        this.setResizable(false);
        this.setBounds(500, 200, 300, 400);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
    }


3：其他程序
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
