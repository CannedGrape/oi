program NOIP2013number;
  uses math;
  var n,p,i,most:longint;
      a:array[1..1000000] of integer;
      b:array[1..1000000] of longint;
  function sum(s:longint):longint;
    begin
      if s=1 then sum:=a[s] else
      sum:=max(sum(s-1),sum(s-1)+a[s]);
    end;
  function ans(s:longint):longint;
    var max1,k:longint;
    begin
      if s<3 then ans:=b[s] else
        begin
          max1:=-1000000;
          for k:=3 to n do if ans(k)+b[k]>max1 then max1:=ans(k)+b[k];
          ans:=max1;
        end;
    end;
  begin
    assign(input,'number.in');
    assign(output,'number.out');
    reset(input); rewrite(output);
      read(n,p);
      for i:=1 to n do read(a[i]);
        for i:=1 to n do b[i]:=sum(i);
      most:=-1000000;
        for i:=1 to n do
          if ans(n)>most then most:=ans(n);
      writeln(most mod p);
    close(input);
    close(output);
  end.


