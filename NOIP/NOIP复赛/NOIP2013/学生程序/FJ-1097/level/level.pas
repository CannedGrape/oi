var
  n,m,s,k,beg:integer;
  i,j,ii:integer;
  a,b:array [1..1000] of integer;
  pan:array [1..1000,1..1000] of integer;

  min,max,num:integer;
  pp,qq,hh:boolean;

function yes(l:integer):boolean;
var ok:boolean;
begin
       for j:=1 to n do
         begin
           if a[j]=l then
              begin
                yes:=true;
                exit;
              end;
         end;
       yes:=false;
end;

begin
       assign(input,'level.in');
       reset(input);
       assign(output,'level.out');
       rewrite(output);
         read(n,m); num:=1;
         for i:=1 to n do a[i]:=0;
         for i:=1 to m do
            begin
               read(beg);
               for j:=1 to beg do read(b[j]); pp:=true;qq:=true;hh:=true;
               //for j:=1 to beg do write(b[j],' ');readln;
               for j:=2 to beg do
                  begin
                    if b[j]-b[j-1]<>1 then
                       begin
                         pp:=false; break;
                       end;
                  end;
               for ii:=1 to num-1 do
                    begin
                       if pan[ii,1]=beg then
                          for j:=1 to beg do
                               begin
                                   if b[j]<>pan[ii,j+1] then  hh:=false;
                               end else hh:=false;
                       if hh=true then
                             begin
                               qq:=false;
                               break;
                             end;
                    end;
               if   qq then
                begin
                    pan[num,1]:=beg;
                    for j:=1 to beg do
                       begin
                           pan[num,j+1]:=b[j];
                       end;
                    if not pp then
                      begin
                         //for j:=1 to beg do writeln(b[j]);readln;
                         for j:=1 to beg do inc(a[b[j]]);
                      end;
                end;
               inc(num);
                  
            
            end;
         max:=0;min:=10000; s:=0;
         for i:=1 to n do
            begin
               if (a[i]>max) then max:=a[i];
               if (a[i]<min) then min:=a[i];
            end;
         for i:=min to max do
            begin
               if yes(i) then inc(s);

            end;
         writeln(S);
       close(input);
       close(output);

end.
