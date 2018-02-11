program ex02;
var w:array[1..100005] of longint;
    y:array[0..100005] of char;
    a:char;
    s:string;
    i,sn,st,x:longint;



procedure jia(n,m:longint);
begin
w[m]:=w[n]+w[m];
if w[m]>=10000 then w[m]:=w[m] mod 10000;
end;
procedure cheng(n,m:longint);
begin
w[n]:=w[n]*w[m];
if w[n]>=10000 then w[n]:=w[n] mod 10000;
end;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
st:=0;sn:=0;s:='';

while not(eof) do
   begin
     read(a);
     if (a<>'*')and(a<>'+') then
       begin
       if length(s)<4 then s:=s+a
          else if length(s)=4 then begin delete(s,1,1);s:=s+a; end;
       end
        else begin
        sn:=st+1;
        val(s,w[sn],x);
        s:='';


          if y[sn-1]='*' then
               begin cheng(sn-1,sn);st:=st-1;sn:=sn-1; end;
        inc(st);
        y[st]:=a;
        end;
   end;

   sn:=st+1;
   val(s,w[sn],x);
   s:='';
   if y[sn-1]='*' then begin cheng(sn-1,sn);st:=st-1;sn:=sn-1; end;

for i:=1 to st do jia(i,i+1);
write(w[st+1]);
close(input);
close(output);
end.


