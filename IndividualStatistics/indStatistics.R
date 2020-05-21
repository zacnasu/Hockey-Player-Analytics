BenthamFaceoffs <- c(66,58,73,56,40,75,69,60,55,67,78,62,57,77,61,36,50,79,81,82,47,38,55,47,54)
plot(BenthamFaceoffs,ylab = "Percentage",xlab = "Games",type = "b",ylim = c(0,100), col ="blue",main = "Bentham Faceoffs")
abline(h = 50)
abline(h=mean(BenthamFaceoffs), col = "red")
legend("topright", c("Game By Game","Average"), fill = c("blue","red"))

ChyzowskiFaceoffs <- c(43,75,58,33,67,67,50,44,89,60,26,56,55,40,60,71,25,39,45,48,50,60,67)
plot(ChyzowskiFaceoffs,ylab = "Percentage",xlab = "Games",type = "b",ylim = c(0,100), col ="blue",main = "Chyzowski Faceoffs")
abline(h = 50)
abline(h=mean(ChyzowskiFaceoffs), col = "red")
legend("topright", c("Game By Game","Average"), fill = c("blue","red"))



playernums <- c(3,5,6,7,8,11,12,14,15,16,17,18,19,21,22,23,27,71,88,91)
playernames <- c("Rust","McClintick","Houlding","Taron","Hamilton","Hadley","Bentham",
                 "Meehan","Nursey","Westhaver","Duffin","McClelland","Jones","Stockton","Sidaway",
                 "Ferrie","Klassen","Chyzowski","Larson","Parkhouse")

i <- 1
for(playerName in playernames){
#playerName = Test
strings <- c(paste("corsi",playernums[i],sep=""),
             paste("teamcorsi",playernums[i],sep=""),
             paste("SOG",playernums[i],sep=""),
             paste("TeamSOG",playernums[i],sep=""),
             paste("ScoringOpps",playernums[i],sep=""),
             paste("TeamScoringOpps",playernums[i],sep=""),
             paste("Games",playernums[i],sep=""),
             paste("SOGFShift",playernums[i],sep=""),
             paste("SOGAShift",playernums[i],sep=""),
             paste("OFShift",playernums[i],sep=""),
             paste("OAShift",playernums[i],sep=""),
             paste("ESShiftShare",playernums[i],sep=""),
             paste("averages",playernums[i],sep=""),
             paste("Opponent",playernums[i],sep=""))
strings

data <- list(get(strings[1]),
             get(strings[2]),
             get(strings[3]),
             get(strings[4]),
             get(strings[5]),
             get(strings[6]),
             get(strings[7]),
             get(strings[8]),
             get(strings[9]),
             get(strings[10]),
             get(strings[11]),
             get(strings[12]),
             get(strings[13]),
             get(strings[14]))



plot(data[[1]],ylab = "Percentage",xlab = "Games",type = "b",ylim = c(0,100), col ="blue",xaxt = "none",main = paste(playerName,"Corsi (Percentage of Shot Attempts For)"))
text(data[[1]],labels = data[[14]])
lines(data[[2]],type = "b",col = "red")
lines(data[[12]],type = "b",col = "forestgreen")
axis(1, at=1:length(data[[1]]), lab= data[[7]])
abline(h = data[[13]][1],col = "red")
abline(h = 33)
abline(h = 25)
abline(h = 50)
legend("topright", c("Individual", "Team","Shift-Share"), fill = c("blue", "red","forestgreen"))
#legend("topright", c("Individual","Overall"), fill = c("blue","red"))


plot(data[[3]],ylab = "Percentage",xlab = "Games",type = "b",ylim = c(0,100), col ="blue",xaxt = "none",main = paste(playerName,"Percentage of Shots on Goal For"))
text(data[[3]],labels = data[[14]])
lines(data[[4]],type = "b",col = "red")
lines(data[[12]],type = "b",col = "forestgreen")
axis(1, at=1:length(data[[1]]), lab= data[[7]])
abline(h = data[[13]][2],col = "red")
abline(h = 33)
abline(h = 25)
abline(h = 50)
legend("topright", c("Individual", "Team","Shift-Share"), fill = c("blue", "red","forestgreen"))
#legend("topright", c("Individual","Overall"), fill = c("blue","red"))



plot(data[[5]],ylab = "Percentage",xlab = "Games",type = "b",ylim = c(0,100), col ="blue",xaxt = "none",main = paste(playerName,"Percentage of Scoring Opportunities For"))
text(data[[5]],labels = data[[14]])
lines(data[[6]],type = "b",col = "red")
lines(data[[12]],type = "b",col = "forestgreen")
axis(1, at=1:length(data[[1]]), lab= data[[7]])
abline(h = data[[13]][3],col = "red")
abline(h = 33)
abline(h = 25)
abline(h = 50)
legend("topright", c("Individual", "Team","Shift-Share"), fill = c("blue", "red","forestgreen"))
#legend("topright", c("Individual","Overall"), fill = c("blue","red"))



plot(data[[8]],ylab = "Avg Per Shift",xlab = "Games",type = "b",ylim = c(0,2), col ="darkgreen",xaxt = "none",main = paste(playerName,"Stats Per Shift"))
text(data[[8]],labels = data[[14]])
lines(data[[9]],type = "b",col = "darkred")
lines(data[[10]],type = "b",col = "chartreuse3")
lines(data[[11]],type = "b",col = "firebrick1")
axis(1, at=1:length(data[[1]]), lab= data[[7]])
legend("topright", c("Shots on Goal For", "Shots on Goal Against","Scoring Opportunities For","Scoring Opportunities Against"), fill = c("darkgreen", "darkred","chartreuse3","firebrick1"))
i <- i+1
}
