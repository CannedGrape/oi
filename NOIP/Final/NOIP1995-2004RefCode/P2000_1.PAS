program p2000_1(input,output);{¼ÆËãÆ÷µÄ¸ÄÁ¼ Improve the calculator}
var temp,s:char;
    cur,xi,cons:integer;
    den,fu:-1..1;
    zimu:boolean;

begin
     assign(input,'calc.in');
     reset(input);
     read(temp);
     assign(output,'calc.out');
     rewrite(output);
     cur:=0;
     xi:=0;
     fu:=1;
     zimu:=false;
     den:=1;
     while not eoln(input) do
     begin
         if (temp>='0') and (temp<='9') then
              cur:=cur*10+ord(temp)-ord('0')
         else
           if temp='=' then
             begin
               if zimu then
                  xi:=xi+fu*den*cur
               else
                  cons:=cons+fu*den*cur;
               den:=-1;
               cur:=0;
               fu:=1;
               zimu:=false;
             end
         else if temp='+' then
            begin
               if zimu then
                   xi:=xi+fu*den*cur
               else
                   cons:=cons+fu*den*cur;
               fu:=1;
               cur:=0;
               zimu:=false;
            end
         else if temp='-' then
            begin
               if zimu then
                   xi:=xi+fu*den*cur
               else
                   cons:=cons+fu*den*cur;
               fu:=-1;
               cur:=0;
               zimu:=false;
            end
         else if (ord(temp)>=ord('a')) and (ord(temp)<=ord('z')) then
            begin
               if cur=0 then
                  cur:=1;
                  zimu:=true;
                  s:=temp;
            end
         else
            begin
                writeln('error input');
                writeln('temp=',temp);
                close(output);
                halt;
            end;
        read(temp);
     end;
     if ( (ord(temp)>=ord('a')) and (ord(temp)<=ord('z')) ) then
            xi:=xi+fu*den*cur
      else
         begin
               cur:=cur*10+ord(temp)-ord('0');
               cons:=cons+fu*den*cur;
         end ;
     write(s,'=');
     if cons=0 then writeln(0.0:0:3)
       else writeln((-1)*cons/xi:0:3);
     close(input);
     close(output);
end.
