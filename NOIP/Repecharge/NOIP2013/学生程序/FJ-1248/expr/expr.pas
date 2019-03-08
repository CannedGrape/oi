program expr;
var i,j,n,m,k,top1,top2,t:longint;
    number,express:array[0..100005]of longint;
    a,b,c:array[0..40]of integer;
    ch:char;
    s:string;
procedure fill;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(c,sizeof(c),0);
end;
function highjia(x,y:longint):longint;
var i,j:longint;
    la,lb:longint;
begin
  fill;
  la:=0;lb:=0;
  while x>0do begin inc(la);a[la]:=x mod 10;x:=x div 10;end;
  while y>0do begin inc(lb);b[lb]:=y mod 10;y:=y div 10;end;
  j:=0;
  for i:=1 to 5 do
  begin
    c[i]:=a[i]+b[i]+j;
    j:=c[i] div 10;
    c[i]:=c[i] mod 10;
  end;
  j:=0;
  for i:=5 downto 1 do j:=j*10+c[i];
  highjia:=j;
end;
function highcheng(x,y:longint):longint;
var i,j:longint;
    la,lb:longint;
begin
  fill;
  la:=0;lb:=0;
  while x>0do begin inc(la);a[la]:=x mod 10;x:=x div 10;end;
  while y>0do begin inc(lb);b[lb]:=y mod 10;y:=y div 10;end;
  for i:=1 to la do
  for j:=1 to lb do c[i+j-1]:=c[i+j-1]+a[i]*b[j];
  j:=0;
  for i:=1 to la+lb do
  begin
    c[i]:=c[i]+j;
    j:=c[i]div 10;
    c[i]:=c[i] mod 10;
  end;
  j:=0;
  for i:=5 downto 1 do j:=j*10+c[i];
  highcheng:=j;
end;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
  t:=0;
  while not eof do
  begin
    read(ch);
    if(ch>='0')and(ch<='9')then t:=t*10+(ord(ch)-48)
    else
    begin
      inc(top1);
      number[top1]:=t;t:=0;
      if ch='+'then k:=1 else k:=2;
      if top2=0 then
      begin
        inc(top2);
        express[top2]:=k;
      end
      else

      begin
        while(top2>0)and(k<=express[top2])do
        begin
          if express[top2]=2then //chengfa
          begin
            top1:=top1-1;
            number[top1]:=highcheng(number[top1],number[top1+1]);
          end
          else begin top1:=top1-1;
                     number[top1]:=highjia(number[top1],number[top1+1]);end;
          top2:=top2-1;
        end;
        inc(top2);
        express[top2]:=k;
      end;
    end;
  end;
  inc(top1);number[top1]:=t;
  while top2>0do
  begin
    if express[top2]=2 then begin top1:=top1-1;
                number[top1]:=highcheng(number[top1],number[top1+1]);end
    else begin top1:=top1-1;
               number[top1]:=highjia(number[top1],number[top1+1]);end;
    top2:=top2-1;
  end;
  write(number[top1]mod 10000);

close(input);close(output);
end.
