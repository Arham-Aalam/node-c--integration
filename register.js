  var fs = require('fs');
  var firebase = require('firebase');
  fs.unlink("./stuff/valide.txt", "0");
  // Initialize Firebase
  var config = {
    apiKey: "<your apiKey>",
    authDomain: "<your authDomain>",
    databaseURL: "<your databaseURL>",
    projectId: "<your project id>",
    storageBucket: "<your storageBucket>",
    messagingSenderId: "<your messagingSenderId>"
  };
  firebase.initializeApp(config);
  //reading file
var email = fs.readFileSync('./stuff/demo.txt', 'utf8');
var psw = fs.readFileSync('./stuff/demo2.txt', 'utf8');
var auth = firebase.auth();
var promise = auth.createUserWithEmailAndPassword(email, psw);
promise
.catch(function(err){
console.log(err.message);
fs.writeFileSync("./stuff/valide.txt", "0");
process.exit("^C");
});
