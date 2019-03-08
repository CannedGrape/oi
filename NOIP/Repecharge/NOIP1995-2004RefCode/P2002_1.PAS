program p02_1(input,output);{级数求和 Ji Shu Qiu He}

var n:longint;
    s:extended;k:integer;

begin
     assign(input,'p1.in');
     reset(input);
     readln(k);
     close(input);
     n:=1;s:=1;
     while s<=k do
       begin n:=n+1;s:=s+1/n;end;
     assign(output,'p1.out');
     rewrite(output);
     writeln(n);
     close(output);
end.

