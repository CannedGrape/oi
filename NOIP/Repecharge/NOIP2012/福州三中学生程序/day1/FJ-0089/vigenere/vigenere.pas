program xxx;
var ans:array [1..1000] of char;
 now,pl,i,j,k,n,m:longint;
 s:ansistring; s1:string;
begin
 assign(input,'vigenere.in');
 assign(output,'vigenere.out');
 reset(input); rewrite(output);
 readln(s); readln(s1);
 for i:=1 to length(s1) do
  if ord(s1[i])<96 then s1[i]:=chr(ord(s1[i])-ord('A')+ord('a'));
 while not(now>=length(s)) do
  begin
   inc(now);
   pl:=(now-1) mod length(s1)+1;
   if s[now] in ['A'..'Z'] then
   ans[now]:=chr(ord('A')+((ord(s[now])-ord('A')+ord(s1[pl])-ord('a')+26) mod 26));
   if s[now] in ['a'..'z'] then
   ans[now]:=chr(ord('a')+((ord(s[now])-ord('a')+ord(s1[pl])-ord('a')+26) mod 26));
  end;
 for i:=1 to length(s) do write(ans[i]);
 close(input); close(output);
end.
