from tkinter import *
import random
ops = ['.','-','+','()','/' , '*']

class interface():
    def __init__(self,root):
        self.root = root
        self.op = []
        self.root.geometry('550x550')
        self.root.resizable(width=False, height=False)
        self.add_v = IntVar()
        self.sub_v = IntVar()
        self.div_v = IntVar()
        self.mul_v = IntVar()
        self.isl_v = IntVar()
        self.kuo_v = IntVar()
        self.operations = [0,0,0,0,0,0]
        self.sub = Checkbutton(self.root,text='减法运算',variable= self.sub_v,command = self.update)
        self.add = Checkbutton(self.root,text='加法运算',variable= self.add_v,command = self.update)
        self.div = Checkbutton(self.root,text='除法运算',variable= self.div_v,command = self.update)
        self.isl = Checkbutton(self.root,text='加小数',variable= self.isl_v,command = self.update)
        self.kuo = Checkbutton(self.root,text='加括号',variable= self.kuo_v,command = self.update)
        self.mul = Checkbutton(self.root,text='乘法运算',variable= self.mul_v,command = self.update)
        self.isl.place(x=300,y=0,anchor=NW)
        self.sub.place(x=370,y=0,anchor=NW)
        self.add.place(x=440,y=0,anchor=NW)
        self.kuo.place(x=300,y=20,anchor=NW)
        self.div.place(x=370,y=20,anchor=NW)
        self.mul.place(x=440,y=20,anchor=NW)
        self.but = Button(text='开始',command = self.is_start).place(x=300,y=50)
        self.label_range = Label(self.root,text='输入范围')
        self.label_range.place(x=80,y=10,anchor=NW)
        self.min_entry = Text(self.root)
        self.min_entry.place(width=50,height=20,x=40,y=30,anchor=NW)
        self.max_entry = Text(self.root)
        self.max_entry.place(width=50,height=20,x=119,y=30,anchor=NW)
        self.label_num = Label(self.root,text='个数').place(x=230,y=10,anchor=NW)
        self.entry_num = Text(self.root)
        self.entry_num.place(width=50,height=20,x=220,y=30,anchor=NW)
        self.entry_show = Text(self.root)
        self.entry_show.place(width=260,height=450,x=20,y=80,anchor=NW)
        self.entry_result = Text(self.root)
        self.entry_result.place(width=240,height=450,x=290,y=80,anchor=NW)
    def update(self):
        if  self.isl_v.get():
            self.operations[0] = 1
        else:
            self.operations[0] = 0
        if  self.sub_v.get():
            self.operations[1] = 1
        else:
            self.operations[1] = 0
        if  self.add_v.get():
            self.operations[2] = 1
        else:
            self.operations[2] = 0
        if  self.kuo_v.get():
            self.operations[3] = 1
        else:
            self.operations[3] = 0
        if  self.div_v.get():
            self.operations[4] = 1
        else:
            self.operations[4] = 0 
        if  self.mul_v.get():
            self.operations[5] = 1
        else:
            self.operations[5] = 0
   
    
    
    def is_start(self):
        is_kuo = False
        is_l = False
        self.op.clear()
        l_num = int(self.entry_num.get(0.0,'end'))
        min_ = int(self.min_entry.get(0.0,'end'))
        max_ = int(self.max_entry.get(0.0,'end'))
        for i in range(len(self.operations)):
            if self.operations[i]==1:
                self.op.append(ops[i])
        operation = self.op
        if operation.count('()')!=0:
            is_kuo = True
            operation.remove('()')
        if operation.count('.')!=0:
            is_l = True
            operation.remove('.')
        formula = []
        num = int(self.entry_num.get(0.0,'end'))
        formula = []
        for i in range(num):
            l = random.randint(2,6)
            now_op = []
            for j in range(l):
                now_op.append(random.choice(operation))
            print('now_op:',now_op)
            if len(now_op)>3 and is_kuo:
                #有括号且括号运算符超过等于三个添加括号
                you_kuo = random.randint(1,len(now_op))
                weizhi = random.randint(1,you_kuo)
                now_op.insert(you_kuo,')')
                now_op.insert(you_kuo-weizhi,'(')
                #print('kuohao:',now_op)

                s = ''
                for j in range(len(now_op)):
                    if is_l:
                        r_ = random.uniform(min_,max_)
                        r = '{:.2f}'.format(r_)
                    else:
                        r = str(random.randint(min_,max_))
                    s += r
                    if  now_op[j] == '(':
                        s += str(random.choice(operation))
                        s += str(now_op[j])
                    elif now_op[j] == ')':
                        s += str(now_op[j])
                        s += str(random.choice(operation))

                    else:
                        s += str(now_op[j])
                if is_l:
                    r_ = random.uniform(min_,max_)
                    r = '{:.2f}'.format(r_)
                else:
                    r = str(random.randint(min_,max_))
                s += r
                formula.append(s)
            else:
                s = ''
                for j in range(len(now_op)):
                    if is_l:
                        r_ = random.uniform(min_,max_)
                        r = '{:.2f}'.format(r_)
                    else:
                        r = str(random.randint(min_,max_))
                    s += r
                    s += str(now_op[j])
                if is_l:
                    r_ = random.uniform(min_,max_)
                    r = '{:.2f}'.format(r_)
                else:
                    r = str(random.randint(min_,max_))
                s += r
                formula.append(s)
        fs = []
        for i,f in enumerate(formula):
            s = ''
            s += '(%d) %s \n'%(i+1,formula[i])
            fs.append(s)
        self.put_data(fs)
        self.put_result(formula)
        
    
    
    
    def put_data(self,s):
        self.entry_show.delete('1.0','end')
        for i in  range(len(s)):
            self.entry_show.insert(INSERT,s[i])

    def put_result(self,s):
        self.entry_result.delete('1.0','end')
        for i in range((len(s))):
            
            result ='({}) {:.4f}\n'.format(i+1,eval(s[i]))
            self.entry_result.insert(INSERT,result)
root = Tk()
r = interface(root)