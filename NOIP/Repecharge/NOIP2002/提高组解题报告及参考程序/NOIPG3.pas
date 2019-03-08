program NOIPG3;
  const g=10{重力加速度};e=1E-5;{小车接受小球的极限距离}
  var H,s1,v,l,k,t1,t2,Vmin,Vmax:real;
      n2,n1,num,n:integer;
  begin
    readln(h,s1,v,l,k,n);num:=-1;
    t1:=sqrt(2*h/g);{小球落地时间}
    if h<=k+e then t2:=0 else t2:=sqrt(2*(h-k-e)/g);{小球落到小车上的最短时间}
    if s1-v*t2+L+e<0 
      then num:=0
      else n2:=trunc(s1-v*t2+L+e);{小车接受的球的最大编号为n2}
    if n2>n-1 then n2:=n-1;{n2取trunc(s1-v*t2+L+e)与n-1的较小值}
    if s1-v*t1-e<=0 
      then n1:=0
      else if s1-v*t1-e>n-1
             then num:=0
             else if (s1-v*t1-e)=trunc(s1-v*t1-e)
                    then n1:=trunc(s1-v*t1-e){小车接受的球的最小编号为n1}
                    else n1:=trunc(s1-v*t1-e)+1;
    if num=-1 then num:=n2-n1+1;{小车接受的球的个数为num}
    writeln(num);
  end.
