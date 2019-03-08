var a:array[1..1000]of longint;
  i,j,tmpa,tmpb,tail,ans,uns:longint;
  ch:char;

begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);

  uns:=0;
  tmpb:=1;
  while not(eoln) do
   begin
     read(ch);
     tmpa:=0;
     while (ch<>'+')and(ch<>'*')and(not(eoln)) do
        begin
         tmpa:=tmpa*10+ord(ch)-ord('0');
         tmpa:=(tmpa mod 10000);
         read(ch);
        end;
     if (ch<>'+')and(ch<>'*') then tmpa:=tmpa*10+ord(ch)-ord('0');
     tmpa:=(tmpa*tmpb) mod 10000;
     if ch='+' then begin inc(tail); a[tail]:=tmpa; tmpb:=1; end;
     if ch='*' then begin tmpb:=tmpa; end;
   end;
   inc(tail); a[tail]:=tmpa;
   ans:=0;
   for i:=1 to tail do
      ans:=((ans+a[i])mod 10000);
   writeln(ans);

   close(input);
   close(output);
end.



