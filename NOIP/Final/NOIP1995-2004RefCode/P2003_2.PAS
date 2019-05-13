program p2003_2(input,output);
const maxn=50;maxm=9;
type arr=array[0..maxn-1,1..maxn,0..2] of longint;
var n,m,t10,t:integer;
    i,j,k:integer;
    a:array[0..maxn-1] of integer;
    min,max:arr;
    m1,m2,temp:longint;
begin
    assign(input,'game.in');
    reset(input);
    readln(n,m);
    for i:=0 to n-1 do readln(a[i]);
    close(input);
    for i:=0 to n-1 do begin
      temp:=0;
      for j:=1 to n do begin
          temp:=temp+a[(i+j-1) mod n];
          if temp>=0 then t10:=temp mod 10
             else t10:=(10-((-1)*temp) mod 10) mod 10;
          min[i,j,0]:=t10;
          max[i,j,0]:=t10;
          min[i,j,1]:=t10;
          max[i,j,1]:=t10;
       end;
    end;
    for k:=1 to m-1 do begin

        for j:=k+1 to n do
          for i:=0 to n-1 do begin
              m1:=2000000000;m2:=-2000000000;
              for t:=k to j-1 do begin
                 if m1>min[i,t,1]*min[(i+t)mod n,j-t,0] then
                   begin m1:=min[i,t,1]*min[(i+t)mod n,j-t,0];
                     if m1<0 then writeln(m1,'=',min[i,t,1],'*',min[(i+t)mod n,j-t,0]);end;
                 if m2<max[i,t,1]*max[(i+t)mod n,j-t,0] then
                  begin m2:=max[i,t,1]*max[(i+t)mod n,j-t,0];
                 end;
              end;
              min[i,j,2]:=m1;
              max[i,j,2]:=m2;
        end;

        for i:=0 to n-1 do
          for j:=1 to n do begin
             min[i,j,1]:=min[i,j,2];
             max[i,j,1]:=max[i,j,2];
        end;
   end;

    m1:=2000000000;m2:=-2000000000;
    for i:=0 to n-1 do begin
        if m1>min[i,n,1] then m1:=min[i,n,1];
        if m2<max[i,n,1] then m2:=max[i,n,1];
    end;
    assign(output,'game.out');
    rewrite(output);
    writeln(m1);
    writeln(m2);
    close(output);
end.



