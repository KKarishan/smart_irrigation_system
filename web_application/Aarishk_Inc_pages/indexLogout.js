function logout() {

    firebase.auth().signOut().then(function() {
        // Sign-out successful.
        window.location = "login.html";
    }).catch(function(error) {
        // An error happened.
        window.alert(error.message);
    });

}