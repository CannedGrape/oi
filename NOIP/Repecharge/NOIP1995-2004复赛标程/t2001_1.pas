program t2001_1;
const eps=0.01;
var a,b,c,d:real;
    first:boolean;
    x1,x2:real;
    count:integer;

function f(x:real):real;
begin
    f:=d+x*(c+x*(b+x*a));
end;

function root(x1,x2:real):real;
var middle:real;
begin
     if (x2-x1)<eps then root:=(x2+x1)/2
     else begin
         middle:=(x1+x2)/2;
         if f(middle)=0 then root:=middle
         else if f(x1)*f(middle)<0 then root:=root(x1,middle)
         else root:=root(middle,x2);
     end;
end;

begin
    assign(input,'input1.dat');
    reset(input);
    readln(a,b,c,d);
    close(input);
    first:=true;
    x1:=-100;x2:=x1+1;
    count:=0;
    assign(output,'output1.dat');
    rewrite(output);
    while (count<3) and (x2<=100) do begin
        while (count<3) and (f(x1)*f(x2)>0) do begin
            x1:=x2;x2:=x1+1;
          end;
        while (count<3) and ((f(x1)=0) or (f(x2)=0)) do begin
            count:=count+1;
            if f(x1)=0 then begin
                if first then begin write(x1:0:2);first:=false;end
                   else write(' ',x1:0:2);
                x1:=x2;x2:=x1+1;
              end
            else begin
                if first then begin write(x2:0:2);first:=false;end
                   else write(' ',x2:0:2);
                x1:=x2+1;x2:=x1+1;
              end
          end;
        while (count<3) and (f(x1)*f(x2)<0) do begin
            count:=count+1;
            if first then begin write(root(x1,x2):0:2);first:=false;end
               else write(' ',root(x1,x2):0:2);
            x1:=x2;x2:=x1+1;
          end;
    end;
    close(output);
end.
