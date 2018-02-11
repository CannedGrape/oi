var  n,i,j,k,ans,temp,ans2,ans3,wei2,wei3:longint;
    a,b:array[0..100500]of longint;
    c,d:array[0..100500]of longint;

procedure paic;
var q,w,x,tem:longint;
begin
  for q:=1 to n do
   begin
    x:=0;
    for w:=1 to n-1 do
    if c[w]>c[w+1] then begin tem:=c[w];c[w]:=c[w+1];c[w+1]:=tem;x:=1;end;
    if x=0 then break;
   end;
end;
procedure paid;
var q,w,x,tem:longint;
begin
  for q:=1 to n do
   begin
    x:=0;
    for w:=1 to n-1 do
    if d[w]>d[w+1] then begin tem:=d[w];d[w]:=d[w+1];d[w+1]:=tem;x:=1;end;
    if x=0 then break;
   end;
end;
procedure changa;
var q,w:longint;
begin
  for q:=1 to n do
   begin
     for w:=1 to n do if a[q]=c[w] then begin a[q]:=w;c[w]:=-1;break;end;
   end;
end;

procedure changb;
var q,w:longint;
begin
  for q:=1 to n do
   begin
     for w:=1 to n do if b[q]=d[w] then begin b[q]:=w;d[w]:=-1;break;end;
   end;
end;
begin
assign(input,'match.in');assign(output,'match.out');reset(input);rewrite(output);
  read(n);
  for i:=1 to n do begin read(a[i]);c[i]:=a[i];end;
  for i:=1 to n do begin read(b[i]);d[i]:=b[i];end;
  paic;paid; changa;changb;


  i:=0;
  repeat
  inc(i);
   if a[i]<>b[i] then
     begin
     k:=i;
     repeat
     inc(k);
     until (a[k]=b[i]) or (a[i]=b[k]);

     if a[k]=b[i] then
   begin
     temp:=a[k];
     ans:=ans+k-i;
     for j:=k downto i+1 do
      a[j]:=a[j-1];
     a[i]:=temp;
   end else
    begin
     temp:=b[k];
     ans:=ans+k-i;
     for j:=k downto i+1 do
      b[j]:=b[j-1];
     b[i]:=temp;
    end;
     end;
  until i=n;



  writeln(ans mod 99999997);
close(input);
close(output);
end.
