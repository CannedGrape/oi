program p2002_3(input,output);{²úÉúÊýGenerate the numbers}
const maxk=15;
type arr=array[1..31] of integer;
var x,y:array[1..maxk] of integer;
    n:string;
    k,i,m:integer;
    z:arr;
procedure mul(var z:arr;m:integer);
var i,c:integer;
begin
     c:=0;
     for i:=1 to 31 do begin
         z[i]:=c+z[i]*m;
         c:=z[i] div 10;
         z[i]:=z[i] mod 10;
     end;
end;

function count(m:integer):integer;
type point=^node;
     node=record
        value:integer;
        next:point;
     end;
var h,p,t,q:point;
    i,sum:integer;
    find:boolean;
begin
     new(p);
     p^.value:=m;p^.next:=nil;
     h:=p;t:=p;sum:=1;
     while p<>nil do begin
         for i:=1 to k do
             if p^.value=x[i] then begin
                  q:=h;find:=false;
                  while not find and (q<>nil) do begin
                     if q^.value=y[i] then find:=true;
                     q:=q^.next;
                  end;
                  if not find then begin
                       new(q);
                       q^.value:=y[i];
                       q^.next:=nil;
                       t^.next:=q;
                       t:=q;sum:=sum+1;
                  end;
             end;
         p:=p^.next;
     end;
     count:=sum;
end;

begin
      assign(input,'p3.in');
      reset(input);
      i:=1;read(n[i]);
      while n[i]<>' ' do begin i:=i+1;read(n[i]);end;
      n[0]:=chr(i-1);readln(k);
      for i:=1 to k do readln(x[i],y[i]);
      close(input);
      fillchar(z,sizeof(z),0);
      z[1]:=1;
      for i:=1 to length(n) do begin
          m:=count(ord(n[i])-ord('0'));
          mul(z,m);
      end;
      assign(output,'p3.out');
      rewrite(output);
      i:=31;
      while (i>0) and (z[i]=0) do i:=i-1;
      while (i>0) do begin write(z[i]);i:=i-1;end;
      writeln;
      close(output);
end.
