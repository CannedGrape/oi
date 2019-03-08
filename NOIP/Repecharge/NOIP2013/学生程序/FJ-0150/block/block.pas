program block;
var a,b:array[1..100000]of longint;
    n,i,j,s:longint;
begin
   assign(input,'block.in');
   reset(input);
   assign(output,'block.out');
   rewrite(output);
   readln(n);
   s:=0;
   for i:=1 to n do
    begin
     read(a[i]);
     b[i]:=0;
    end;
   readln;
   for i:=1 to n do
       while a[i]>b[i] do
         begin
           for j:=i to n do
            begin
              b[j]:=b[j]+1;
              if a[j]<b[j] then break;
            end;
          s:=s+1;
         end;
   writeln(s);
   readln;
   close(input);
   close(output);
end.
