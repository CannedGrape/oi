program expand1;
type str1=string[100];
     str2=array [0..6500] of char;
var s1:str1;
    s2:str2;
    file1:string[30];
    text1,text2:text;
    p1,p2,p3,z1,z2,maxj:integer;

function isalpha(c:char):boolean;
var i:integer;
begin
 i:=ord(c);
 if ((i>=65) and (i<=90)) or
      ((i>=97) and (i<=122)) then
   isalpha:=true
 else
   isalpha:=false;
end;
function isdigit(c:char):boolean;
var i:integer;
begin
 i:=ord(c);
 if (i>=48) and (i<=57) then
   isdigit:=true
 else
  isdigit:=false;
end;

function tolower(c:char):char;
var i:integer;
begin
 i:=ord(c);
 if (i>=65) and (i<=90) then
   tolower:=chr(i+32)
 else
   tolower:=c;
end;


procedure readdata_expand;
begin
  writeln('input filename for input:');
  readln(file1);
  assign(text1,file1); reset(text1);
  readln(text1,p1,p2,p3);
  readln(text1,s1);
  close(text1);
end;

procedure inverse;
var i,j:integer;
    t:char;
begin
 i:=z1;j:=z2;
 while(i<j) do
   begin
    t:=s2[i]; s2[i]:=s2[j]; s2[j]:=t;
    inc(i); dec(j);
   end;
end;

procedure expand;
var i,j,k:integer;
    a,b,c:char;
begin
  j:=1; c:=char(1); i:=0;
  while i<=length(s1) do
   begin{1}
     inc(i); c:=s1[i];
     if c='-' then
      begin {2}
       a:=s1[i-1]; b:=s1[i+1];
       if (upcase(a)<upcase(b))and
           ((isalpha(a) and isalpha(b)) or (isdigit(a) and isdigit(b)))
       then
          begin {3}
            if (p1=1) then
               begin
                 a:=tolower(a);b:=tolower(b);
               end
            else if(p1=2) then
               begin
	         a:=upcase(a);b:=upcase(b);
            end;
            z1:=j;
	    while (tolower(a)<pred(tolower(b))) do
               begin
                  a:=succ(a);
                  for k:=1 to p2 do
                    begin
                     if p1=3 then s2[j]:='*'
                     else  s2[j]:=a;
                     inc(j);
                    end;
                end;
            z2:=j-1;
	    if p3=2 then
              inverse();
           end {3}
           else
              begin  s2[j]:=c;inc(j);  end;
          end {2}
       else
           begin  s2[j]:=c;inc(j);    end;
    end;{1}
   maxj:=j-1;
 end;
procedure out_expand;
var j,k:integer;
begin
 writeln('input filename for output:');
 readln(file1);
  assign(text2,file1); rewrite(text2);
  for j:=1 to maxj do
    write(text2,s2[j]);
  writeln(text2);
  close(text2);
end;

begin
  readdata_expand;
  expand;
  out_expand;
end.

