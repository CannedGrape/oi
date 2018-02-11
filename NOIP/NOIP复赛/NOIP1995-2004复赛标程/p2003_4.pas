program masson(input,output);{2^p -1,the last 500 wei}
type arr=array[1..500] of integer;
     arry=array[1..50] of integer;
var p:longint;bp:array[1..22]of integer;
    i,bpn:integer;
    x500:arr;y50:arry;
    weiy:longint;
    q:integer;

procedure mul(var x:arr);
var i,j,c:integer;y,z:arr;
begin
    for i:=1 to 500 do begin y[i]:=x[i];z[i]:=x[i];x[i]:=0;end;
    for i:=1 to 500 do begin
       c:=0;
       for j:=1 to 500 do
            if (i+j-1)<=500 then begin
               x[i+j-1]:=x[i+j-1]+c+y[i]*z[j];
               c:=x[i+j-1] div 10;
               x[i+j-1]:=x[i+j-1] mod 10;end
            else break;
    end;
end;

procedure add(var x:arr);
var i,c:integer;
begin
    c:=0;
    for i:=1 to 500 do begin
       x[i]:=x[i]+x[i]+c;
       c:=x[i] div 10;
       x[i]:=x[i] mod 10;
    end;
end;

procedure muly(var x:arry;var wei:longint);
var y,z:arry;x1:arr;
    i,j,c:integer;
    nx:integer;{nx is the WeiShu of x}
begin
    for i:=1 to 50 do begin y[i]:=x[i];z[i]:=x[i];end;
    c:=0;fillchar(x1,sizeof(x1),0);
    for i:=1 to 50 do

     begin
       c:=0;
       for j:=1 to 50 do begin
           x1[i+j-1]:=x1[i+j-1]+c+y[i]*z[j];
           c:=x1[i+j-1] div 10;
           x1[i+j-1]:=x1[i+j-1] mod 10;
       end;
       if c>0 then x1[i+50]:=c;
     end;

    if c>0 then begin i:=100;end
        else i:=99;
    wei:=wei+wei+(i-50);
    if x1[i-50]>=5 then c:=1 else c:=0;
    for j:=1 to 50 do begin
        x[j]:=x1[i-50+j]+c;
        c:=x[j] div 10;
        x[j]:=x[j] mod 10;
    end;

end;

procedure addy(var x:arry;var wei:longint);
var i,c,c1:integer;
begin
     c:=0;
     for i:=1 to 50 do begin
         x[i]:=x[i]+x[i]+c;
         c:=x[i] div 10;
         x[i]:=x[i] mod 10;
     end;
     if c>0 then begin {move 1 bit to right}
          wei:=wei+1;
          if x[1]>=5 then c1:=1 else c1:=0;
          for i:=1 to 49 do begin
              x[i]:=x[i+1]+c1;
              c1:=x[i] div 10;
              x[i]:=x[i] mod 10;
          end;
          x[50]:=c+c1;
    end;
end;

begin
  assign(input,'mason.in');
  reset(input);
  readln(p);
  close(input);
  i:=0;
  while p>0 do begin i:=i+1;bp[i]:=p mod 2;p:=p div 2;end;
  bpn:=i;

  weiy:=-49;
  fillchar(y50,sizeof(y50),0);
  y50[50]:=1;
  i:=bpn;
  while i>0  do begin
     if  bp[i]=1 then begin
             muly(y50,weiy);
             addy(y50,weiy);
          end

        else
           muly(y50,weiy);

     i:=i-1;
  end;
  assign(output,'mason.out');
  rewrite(output);
  writeln(weiy+50);
  fillchar(x500,sizeof(x500),0);
  i:=bpn;x500[1]:=1;
  while i>0 do begin
     if bp[i]=1 then begin mul(x500);add(x500);end
        else mul(x500);
     i:=i-1;
  end;
  x500[1]:=x500[1]-1;
  for i:=500 downto 1 do write(x500[i]);
  writeln;
  close(output);
end.
