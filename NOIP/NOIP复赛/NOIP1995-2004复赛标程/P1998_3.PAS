program p1998_3(input,output);{2µÄÃİ´ÎÊä³ö;Output2(2(2)+2+2(0))+2(2+2(0))+2(0)}
var n:integer;

procedure try(n:integer);
const m=16;
var i,j:integer;
    first:boolean;
    b:array[0..m] of integer;
begin
  if n=0 then write(0)
  else begin
     i:=0;first:=true;
     while n<>0 do begin b[i]:=n mod 2;n:=n div 2;i:=i+1;end;
     for j:=i-1 downto 0 do
     if b[j]=1 then begin
         if first then first:=false
            else write('+');
          if j=1 then write(2)
           else begin
             write('2(');
             try(j);
             write(')');
           end;
     end;
  end;
end;

begin
    assign(input,'power.in');
    reset(input);
    readln(n);
    close(input);
    assign(output,'power.out');
    rewrite(output);
    try(n);
    writeln;
    close(output);
end.
