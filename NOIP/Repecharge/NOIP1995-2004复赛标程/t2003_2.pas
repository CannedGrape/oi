program t2003_2;
const maxm=20;maxp=100;
var name:array[1..maxm]of string;
    says:array[1..maxp]of string;
    m,n,ntrue,nfalse,p,i,j,k,p1,count:integer;
    ss,nam,Zuifan,day,sub:string;
    all,find:boolean;
    g:array[1..maxm]of 0..2;
    f:array[1..2] of integer;

function loc(s,sub:string;sta:integer):integer;
var find:boolean;i,i1,j,Ls,Lsub:integer;
begin
    find:=false;
    Ls:=length(s);Lsub:=length(sub);
    if sta+Lsub-1>Ls then
        loc:=0
    else begin
        i:=sta;
        while not find and (i<=Ls-Lsub+1) do begin
            j:=1;i1:=i;
            while (j<=Lsub) and (s[i1]=sub[j]) do
              begin i1:=i1+1;j:=j+1;end;
            if j>Lsub then
                find:=true
            else
                i:=i+1;
        end;
        if find then
           loc:=i
        else
           loc:=0;
    end;
end;

function trim(s:string;sta,len:integer):string;
var ss:string;i:integer;
begin
    if len<1 then trim:=''
    else begin
       for i:=1 to len do
          ss[i]:=s[sta+i-1];
       ss[0]:=chr(len);
       trim:=ss;
    end;
end;

function isname(s:string):boolean;
var  find:boolean;i:integer;
begin
    find:=false;i:=1;
    while not find and (i<=m) do
        if name[i]=s then
            find:=true
        else
           i:=i+1;
    isname:=find;
end;

function isday(s:string):boolean;
var ok:boolean;
begin  ok:=true;
    if (s='Monday') or (s='Tuesday') or (s='Wednesday') or (s='Thursday') then
       ok:=true;
    if ok or (s='Friday') or (s='Saturday') or (s='Sunday') then
       isday:=true
    else
       isday:=false;
end;

function ok(s:string):boolean;
var f:array[1..5]of integer;
    ok1:boolean;sub:string;
begin
    f[1]:=loc(s,' ',1);
    sub:=trim(s,1,f[1]-2);
    if not isname(sub) then
        ok:=false
    else begin
        f[2]:=loc(s,' ',f[1]+1);
        sub:=trim(s,f[1]+1,f[2]-f[1]-1);
        if sub='I' then begin
             f[3]:=loc(s,' ',f[2]+1);
             sub:=trim(s,f[2]+1,f[3]-f[2]-1);
             if not isname('I') and (sub<>'am') then ok:=false
             else if isname('I') and (sub<>'is') and (sub<>'am') then ok:=false
             else begin
                  f[4]:=loc(s,' ',f[3]+1);
                  if f[4]>=f[3]+1 then begin
                      sub:=trim(s,f[3]+1,f[4]-f[3]-1);
                      if sub<>'not' then ok:=false
                      else begin
                           f[5]:=loc(s,'.',f[4]+1);
                           if f[5]<length(s) then ok:=false
                           else begin
                               sub:=trim(s,f[4]+1,f[5]-f[4]-1);
                               if sub='guilty' then ok:=true
                               else ok:=false;
                           end;
                      end;
                   end
                  else begin
                      f[4]:=loc(s,'.',f[3]+1);
                      if f[4]<length(s) then ok:=false
                      else begin
                           sub:=trim(s,f[3]+1,f[4]-f[3]-1);
                           if sub='guilty' then ok:=true
                           else ok:=false;
                      end;
                  end;
             end;
          end
          else if sub='Today' then begin
             f[3]:=loc(s,' ',f[2]+1);
             sub:=trim(s,f[2]+1,f[3]-f[2]-1);
             if sub<>'is' then ok:=false
             else begin
                 f[4]:=loc(s,'.',f[3]+1);
                 if f[4]>=f[3]+1 then begin
                      sub:=trim(s,f[3]+1,f[4]-f[3]-1);
                      if isday(sub) then ok:=true
                      else ok:=false;
                   end
                 else ok:=false;
             end;
          end
          else if isname(sub) then begin
             f[3]:=loc(s,' ',f[2]+1);
             sub:=trim(s,f[2]+1,f[3]-f[2]-1);
             if sub<>'is' then ok:=false
             else begin
                  f[4]:=loc(s,' ',f[3]+1);
                  if f[4]>=f[3]+1 then begin
                      sub:=trim(s,f[3]+1,f[4]-f[3]-1);
                      if sub<>'not' then ok:=false
                      else begin
                           f[5]:=loc(s,'.',f[4]+1);
                           if f[5]<length(s) then ok:=false
                           else begin
                               sub:=trim(s,f[4]+1,f[5]-f[4]-1);
                               if sub='guilty' then ok:=true
                               else ok:=false;
                           end;
                      end;
                   end
                  else begin
                      f[4]:=loc(s,'.',f[3]+1);
                      if f[4]<length(s) then ok:=false
                      else begin
                           sub:=trim(s,f[3]+1,f[4]-f[3]-1);
                           if sub='guilty' then ok:=true
                           else ok:=false;
                      end;
                  end;
             end;
           end
        else ok:=false;

    end;
end;

begin
     assign(input,'logic.in');
     reset(input);
     readln(m,n,p);
     for i:=1 to m do readln(name[i]);
     i:=1;j:=1;
     while i<=p do begin
        readln(ss);
        if ok(ss) then begin
            says[j]:=ss;j:=j+1;end;
        i:=i+1;
     end;
     close(input);
     p:=j-1;
     assign(output,'logic.out');
     rewrite(output);
     find:=false;
     for j:=1 to 7 do begin
         count:=0;
         case j of
           1:day:='Monday';
           2:day:='Tuesday';
           3:day:='Wednesday';
           4:day:='Thursday';
           5:day:='Friday';
           6:day:='Saturday';
           7:day:='Sunday';
         end;
         for i:=1 to m do begin
             fillchar(g,sizeof(g),0);
             all:=true;
             p1:=1;
             while all and (p1<=p) do begin
                 f[1]:=loc(says[p1],' ',1);
                 f[2]:=loc(says[p1],' ',f[1]+1);
                 nam:=trim(says[p1],1,f[1]-2);
                 for k:=1 to m do
                    if name[k]=nam then break;
                 sub:=trim(says[p1],f[1]+1,f[2]-f[1]-1);
                 if sub='Today' then begin
                      if g[k]=0 then begin
                         if trim(says[p1],f[2]+4,length(says[p1])-f[2]-4)=day then
                            g[k]:=2
                         else g[k]:=1;
                        end
                      else if (g[k]=1) and (trim(says[p1],f[2]+4,length(says[p1])-f[2]-4)=day) then
                            all:=false
                      else if (g[k]=2) and (trim(says[p1],f[2]+4,length(says[p1])-f[2]-4)<>day) then
                            all:=false;
                   end
                 else if (sub='I')  and (trim(says[p1],f[2]+1,2)='am') then begin
                      if g[k]=0 then begin
                            if trim(says[p1],f[2]+4,1)='g' then begin
                                if nam=name[i] then g[k]:=2
                                  else g[k]:=1;
                              end
                            else begin
                                if nam=name[i] then g[k]:=1
                                  else g[k]:=2;
                              end;
                        end
                      else if (g[k]=1) then begin
                            if (trim(says[p1],f[2]+4,1)='g') and (nam=name[i]) then
                                   all:=false
                            else if (trim(says[p1],f[2]+4,1)='n') and (nam<>name[i]) then
                                   all:=false;
                        end
                      else if (g[k]=2) then begin
                            if (trim(says[p1],f[2]+4,1)='g') and (nam<>name[i]) then
                                   all:=false
                            else if (trim(says[p1],f[2]+4,1)='n') and (nam=name[i]) then
                                   all:=false;
                        end;
                   end
                 else begin
                      if g[k]=0 then begin
                            if trim(says[p1],f[2]+4,1)='g' then begin
                                if sub=name[i] then g[k]:=2
                                   else g[k]:=1;
                               end
                            else begin
                                if sub=name[i] then g[k]:=1
                                   else g[k]:=2;
                               end;
                        end
                      else if (g[k]=1) then begin
                            if (trim(says[p1],f[2]+4,1)='g') and (sub=name[i]) then
                                   all:=false
                            else if (trim(says[p1],f[2]+4,1)='n') and (sub<>name[i]) then
                                   all:=false;
                        end
                      else if (g[k]=2) then begin
                            if (trim(says[p1],f[2]+4,1)='g') and (sub<>name[i]) then
                                   all:=false
                            else if (trim(says[p1],f[2]+4,1)='n') and (sub=name[i]) then
                                   all:=false;
                        end;
                   end;
                   p1:=p1+1;
             end;
             if all then begin
                 ntrue:=0;
                 nfalse:=0;
                 for p1:=1 to m do
                    if g[p1]=1 then nfalse:=nfalse+1
                    else if g[p1]=2 then ntrue:=ntrue+1;
                 if (nfalse<=n) and (ntrue<=m-n) then begin
                    count:=count+1;
                    ZuiFan:=name[i];
                    find:=true;
                 end;
             end;
         end;
         if count=1 then begin
             writeln(ZuiFan);close(output);halt;end;
     end;
     if find then writeln('Cannot Determine')
     else  writeln('Impossible');
     close(output);

end.
