 program count;
 var n,i,ans,j,k : longint;
     c : char;
     s : string;
     x : byte;
 begin
 assign(input,'count.in');
 reset(input);
 assign(output,'count.out');
 rewrite(output);
 readln(n,x);
 ans := 0;
 c := chr(x + 48);
 for i := 1 to n do
  begin
   str(i,s);
   k := length(s);
   for j := 1 to k do if (s[j] = c) then inc(ans);
  end;
 write(ans);
 close(input);
 close(output);
 end.
